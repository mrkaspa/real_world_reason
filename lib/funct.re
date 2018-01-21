open Core.Std;

module type Summer = {type t; let sum: (t, t) => t;};

module type Summable = {type t; let zero: t; let unit: t;};

module type Incrementor = {type t; let inc: t => t;};

module IntSummable = {
  type t = int;
  let zero = 0;
  let unit = 1;
};

module FloatSummable = {
  type t = float;
  let zero = 0.;
  let unit = 1.;
};

module IntSummer = {
  type t = int;
  let sum = (n1, n2) => n1 + n2;
};

module FloatSummer = {
  type t = float;
  let sum = (n1, n2) => n1 +. n2;
};

module Make_incrementor =
       (A: Summable, M: Summer with type t = A.t)
       : (Incrementor with type t = A.t) => {
  include M;
  let inc = n => M.sum(n, A.unit);
};

module Int_incrementor = Make_incrementor(IntSummable, IntSummer);

module Float_incrementor = Make_incrementor(FloatSummable, FloatSummer);

let int_inc: (module Incrementor with type t = int) = (module Int_incrementor);

let increment =
    (type a, (module A): (module Incrementor with type t = a), n: a) =>
  A.inc(n);

let apply_twice = (f, n) => f(f(n));

let increment_twice =
    (type a, (module A): (module Incrementor with type t = a), n: a) =>
  apply_twice(increment((module A)), n);

let () = {
  printf("int %d\n", increment(int_inc, 10));
  printf("float %f\n", increment((module Float_incrementor), 10.));
  printf("float twice %f\n", increment_twice((module Float_incrementor), 10.));
};
