open Core.Std;

let say_hello = (name) => {
  let name = "michel";
  print_string("Hola mundo " ++ (name ++ "\n"))
};

let () = {
  for (i in 0 to 10) {
    say_hello()
  };
  List.iter(List.range(1, 10), (elem) => print_string(string_of_int(elem)));
  ()
};
