open Core.Std;

let build_counts = () =>
  In_channel.fold_lines(
    In_channel.stdin,
    ~init=Map_counter.empty,
    ~f=Map_counter.touch
  );

let run_counts = () =>
  build_counts()
  |> Map_counter.to_list
  |> List.sort(~cmp=((_, x), (_, y)) => Int.descending(x, y))
  |> (l => List.take(l, 10))
  |> List.iter(~f=((line, count)) => printf("%3d: %s\n", count, line));

let () = run_counts();
