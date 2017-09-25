open Core.Std;

let rec read_and_accumulate accum => {
  let line = In_channel.input_line In_channel.stdin;
  switch line {
  | None => accum
  | Some x =>
    try (read_and_accumulate (accum +. Float.of_string x)) {
    | Invalid_argument _ => accum
    }
  }
};

let is_empty =
  fun
  | [] => true
  | _ => false;

let run () => printf "Total: %F\n" (read_and_accumulate 0.);
