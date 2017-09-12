module type Monoid = sig
  type t
  val mempty : t
  val mappend : t -> t -> t
end

type sum = Sum of int

module SumMonoid = struct
  type t = sum
  let mempty = (Sum 0)
  let mappend (Sum a) (Sum b) =
    Sum (a + b)
end

module ProdMonoid = struct
  type t = int
  let mempty = 1
  let mappend a b = a * b
end

type 'a monoid_a = (module Monoid with type t = 'a)

(* another signature *)
(* let sumi (type a) ((module A) : (module Monoid with type t = a)) (n : a) = *)
let sumi (type a) ((module A) : (a monoid_a)) (n : a) =
  A.mappend n A.mempty

let (Sum res) =
  sumi (module SumMonoid) (Sum 1)

let res1 = string_of_int res

let res2 = string_of_int (sumi (module ProdMonoid) 1)

let run () =
  print_string ("sumi => " ^ res1); print_string ("prodi => " ^ res2)
