open Core.Std;

module Ord = {
  type t =
    | GT
    | EQ
    | LT;
};

module type Comparable = {type t; let compare: t => t => Ord.t;};

module type Interval_iface = {
  type endpoint;
  type t =
    | Interval endpoint endpoint
    | Empty;
  let create: endpoint => endpoint => t;
  let is_empty: t => bool;
  let contains: t => endpoint => bool;
};

module Make_interval (Endpoint: Comparable) :(Interval_iface with type endpoint := Endpoint.t) => {
  type t =
    | Interval Endpoint.t Endpoint.t
    | Empty;
  let create low high =>
    if (Endpoint.compare low high == Ord.GT) {
      Empty
    } else {
      Interval low high [@implicit_arity]
    };
  let is_empty =
    fun
    | Empty => true
    | Interval _ => false;
  let contains t x =>
    switch t {
    | Empty => false
    | Interval low high [@implicit_arity] =>
      Endpoint.compare x low == Ord.GT && Endpoint.compare x high == Ord.LT
    };
};

module IntInterval =
  Make_interval {
    type t = int;
    let compare i1 i2 =>
      switch (Int.compare i1 i2) {
      | 0 => Ord.EQ
      | 1 => Ord.GT
      | (-1) => Ord.LT
      | _ => Ord.EQ
      };
  };

let () = {
  open IntInterval;
  let inter = IntInterval.create 10 2;
  switch inter {
  | Interval low high [@implicit_arity] => printf "Interval %d - %d" low high
  | Empty => print_string "Empty interval"
  }
};
