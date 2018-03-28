open Webapi.Dom;

external toDomElement : 'a => Dom.element = "%identity";

let unwrapElement =
  fun
  | Some(v) => v
  | None => raise(Invalid_argument("No element passed to unwrap"));

let selectItem = query =>
  document |> Document.querySelector(query) |> unwrapElement;

let handleSlide = () => {
  let container = selectItem(".container");
  let before = selectItem(".before");
  let active = selectItem(".active");
  let after = container |> Element.querySelectorAll(".after");
  let afterArray = after |> NodeList.toArray |> Array.map(toDomElement);
  let lastAfter = afterArray[Array.length(afterArray) - 1];
  before |> Element.classList |> DomTokenList.replace("before", "active");
  active |> Element.classList |> DomTokenList.replace("active", "after");
  lastAfter |> Element.remove;
  lastAfter |> Element.classList |> DomTokenList.replace("after", "before");
  %bs.raw
  {| container.prepend(lastAfter) |};
  ();
};

Js.Global.setInterval(handleSlide, 1500);