open Core.Std

let add2 x = x + 2

let ratio x y =
  Float.of_int x /. Float.of_int y

let even (n: int): bool =
  (n mod 2) = 0

let count_pairs (ls: int list): int =
  List.filter ls even
  |> List.length

let run () =
  Printf.printf "%f\n" (ratio 1 2);
  Printf.printf "counting pairs %d\n" (count_pairs [1;2;3;4]);
