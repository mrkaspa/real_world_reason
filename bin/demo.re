open Core.Std;

let say_hello = (name: string) => print_string("Hola mundo " ++ (name ++ "\n"));

let prt = (elem) => print_string(string_of_int(elem) ++ "\n");

List.iter(List.range(1, 10), prt);

let count = ref(0);

for (i in 0 to 10) {
  count := count^ + 1;
  say_hello("Michel")
};

if (count^ >= 1) {
  print_string("entro if")
};
