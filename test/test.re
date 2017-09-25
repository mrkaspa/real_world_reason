let test1 () => assert (Lib.Main.add2 5 === 7);

let test2 () => assert (Lib.Main.add2 5 === 7);

{
  test1 ();
  test2 ()
};
