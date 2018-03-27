open Webapi.Dom;

let unwrapElement =
  fun
  | Some(v) => v
  | None => raise(Invalid_argument("No element passed to unwrap"));