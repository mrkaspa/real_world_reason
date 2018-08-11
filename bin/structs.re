open Core.Std;

let dedup = (~comparator, ls) =>
  ls |> List.fold(~init=Set.empty(~comparator), ~f=Set.add) |> Set.to_list;

let cmp = Comparator.Poly.comparator;

let make_int_map = ls => Map.of_alist_exn(~comparator=cmp, ls);

let print_value =
  fun
  | Some(value) => print_string("Cad = " ++ value ++ "\n")
  | None => print_string("Not found\n");

let _ = {
  /*  Using Maps */
  let map = make_int_map([(1, "uno"), (2, "dos")]);
  let tree = Map.to_tree(map);
  let valueOpt = Map.Tree.find(~comparator=cmp, tree, 1);
  print_value(valueOpt);

  /* Using Sets */
  let ls = [2, 2, 1, 2, 4, 5, 4, 3];
  let dd = dedup(~comparator=Int.comparator, ls);
  List.iter(dd, ~f=n => print_string("- " ++ string_of_int(n) ++ "\n"));
};
