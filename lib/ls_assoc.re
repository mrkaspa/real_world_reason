open Core.Std;

let digit_alist = [(0, "zero")];

let find_in_assoc = n => {
  let res = List.Assoc.find(~equal=(==), digit_alist, n);
  switch (res) {
  | Some(a) => a
  | None => "not"
  };
};

let find_in_map = () => {
  let digit_map = Map.of_alist_exn(Core.Std.Int.comparator, digit_alist);
  digit_map
  |> Map.add(~key=1, ~data="one")
  |> (m => Map.find(m, 1))
  |> (opt => Option.(opt >>= (n => Some(n ++ n))));
};
