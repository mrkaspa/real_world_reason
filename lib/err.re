open Core.Std;

let safe_div n d =>
  if (d == 0) {
    Error (Error.of_string "d is 0")
  } else {
    Ok (n / d)
  };

exception DemoEx string;

let unsafe_div n d =>
  if (d == 0) {
    raise (DemoEx "d is 0")
  } else {
    n / d
  };

let use_safe_div () => {
  open Result.Monad_infix;
  let res = safe_div 1 1 >>= (fun res => Ok (res + 1));
  switch res {
  | Ok res => printf "The res %d" res
  | Error error => printf "Err %s" (Error.to_string_hum error)
  }
};

let use_unsafe_div () =>
  try {
    let res = unsafe_div 1 0;
    printf "The res %d" res
  } {
  | DemoEx msg => printf "Err %s" msg
  };

let () = use_unsafe_div ();
