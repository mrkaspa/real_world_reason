open Core.Std

type t

val touch : t -> string -> t

val empty: t

val to_list : t -> (string * int) list
