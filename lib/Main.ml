open Core.Std

let add2 x = x + 2

let ratio x y =
  Float.of_int x /. Float.of_int y

let divisible_by (by: int) (n: int): bool =
  (n mod by) = 0

let even: int -> bool =
  divisible_by 2

let count_pairs (ls: int list): int =
  List.filter ls even
  |> List.length

let sum_if_true (test: int -> bool) (first: int) (second: int): int =
  (if test first then first else 0)
  + (if test second then second else 0)

let run () =
  Printf.printf "sum if even %d\n" (sum_if_true even 1 2);
  Printf.printf "%f\n" (ratio 1 2);
  Printf.printf "counting pairs %d\n" (count_pairs [1; 2; 3; 4]);
