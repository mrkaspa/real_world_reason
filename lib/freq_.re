open Core.Std;

let build_counts () =>
  In_channel.fold_lines
    stdin
    init::[]
    f::(
      fun counts line => {
        let count =
          switch (List.Assoc.find counts line) {
          | None => 0
          | Some x => x
          };
        List.Assoc.add counts line (count + 1)
      }
    );

let run_counts () =>
  build_counts () |> List.sort cmp::(fun (_, x) (_, y) => Int.descending x y) |> (
    fun l => List.take l 10
  ) |>
  List.iter f::(fun (line, count) => printf "%3d: %s\n" count line);
