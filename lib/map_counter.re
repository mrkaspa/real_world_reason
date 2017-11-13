open Core.Std;

type t = String.Map.t(int);

let empty = String.Map.empty;

let to_list = (t) => Map.to_alist(t);

let touch = (t, s) => {
  let count =
    switch (Map.find(t, s)) {
    | None => 0
    | Some(x) => x
    };
  Map.add(t, ~key=s, ~data=count + 1)
};
