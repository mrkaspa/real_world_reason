open Core.Std;

let funi may =>
  switch may {
  | Some cad => print_string cad
  | None => print_string ""
  };

let prt_elems elems::(elems: string) =>
  elems |> String.split on::':' |> List.dedup compare::String.compare |>
  List.iter f::print_endline;

module type Bumper = {type t; let bump: t => t;};

module IntBumper = {
  type t = int;
  let bump t => t + 1;
};

let bumpi (type a) ((module B): (module Bumper with type t =a)) (ls: list a) =>
  List.map f::B.bump ls;

let concat (type a b) (funi: a => b) (lsa: list a) :list b => List.map f::funi lsa;

let main () => prt_elems "/usr/bin:/usr/local/bin:/bin:/sbin";
