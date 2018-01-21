open Core.Std;

module Username: {
  type t;
  let of_string: string => t;
  let to_string: t => string;
} = {
  type t = string;
  let of_string = x => x;
  let to_string = x => x;
};

let print_name = (name: Username.t) => print_string(Username.to_string(name));

module type ID = {
  type t;
  let of_string: string => t;
  let to_string: t => string;
};

module String_id = {
  type t = string;
  let of_string = x => x;
  let to_string = x => x;
};

module Usernami: ID = String_id;

module Hostname: ID = String_id;

type session_info = {
  user: Usernami.t,
  host: Hostname.t,
  when_started: Time.t
};

let create_session = (username, host) => {
  user: username,
  host,
  when_started: Time.now()
};

let id_to_string = (type a, (module B): (module ID with type t = a), id: a) =>
  B.to_string(id);

module Logon = {
  type t = {
    session_id: string,
    time: Time.t,
    user: string,
    credentials: string
  };
};

let get_users = logons => List.dedup(List.map(logons, ~f=x => x.Logon.user));

let () = {
  let session =
    create_session(Usernami.of_string("demo"), Hostname.of_string("host"));
  print_string(
    "The username is " ++ id_to_string((module Usernami), session.user)
  );
};
