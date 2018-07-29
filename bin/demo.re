open Core.Std;

let say_hello = (name: string) =>
  print_string("Hola mundo " ++ name ++ "\n");

let prt = elem => print_string(string_of_int(elem) ++ "\n");

let _ = {
  List.iter(List.range(1, 10), ~f=prt);
  let count = ref(0);
  for (_i in 0 to 10) {
    count := count^ + 1;
    say_hello("Michel");
  };
  if (count^ >= 1) {
    print_string("entro if");
  };
};
