open Core.Std;

let say_hello = (name: string) => print_string("Hola mundo " ++ (name ++ "\n"));

let () = {
  let prt = (elem) => print_string(string_of_int(elem) ++ "\n");
  List.iter(List.range(1, 10), prt);
  for (i in 0 to 10) {
    say_hello("Michel")
  };
  if (1 == 1) {
    print_string("eoo")
  };
  ()
};
