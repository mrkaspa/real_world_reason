module type X_int = sig
  val x: int
end

module Increment (M : X_int) : X_int = struct
  let x = M.x + 1
end

module Zero = struct
  let x = 0
end

module One = Increment(Zero)

let () =
  print_int (One.x)
