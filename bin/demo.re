let f a => a;

let () = {
  let res = f 1;
  print_string (string_of_int res)
};
