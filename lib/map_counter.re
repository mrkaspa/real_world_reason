open Core.Std;

type t = String.Map.t(int);

let empty = String.Map.empty;

let to_list = t => Map.to_alist(t);

let add_with_default = (t, ~key, ~fn, ~default) => {
  let new_val =
    switch (Map.find(t, key)) {
    | None => default
    | Some(n) => fn(n)
    };
  Map.add(t, ~key, ~data=new_val);
};

let touch = (t, s) => add_with_default(t, ~key=s, ~fn=n => n + 1, ~default=0);
