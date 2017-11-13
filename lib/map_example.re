open Core.Std;

let add_map = () =>
  [("1", 1), ("2", 2)]
  |> Map.of_alist_exn(~comparator=String.comparator)
  |> Map.add(~key="2", ~data=2)
  |> ((m) => Map.find(m, "2"));
