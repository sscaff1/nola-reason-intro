/* LET BINDING */
let myMessage = "Hello from let binding";

Js.log(myMessage);

/* FUNCTIONS */
let sum = (x, y, z) => x + y + z; /* signature (int, int, int) => int */

let addTwoAndThree = sum(2, 3); /* Taking advantage of currying */

5 |> addTwoAndThree; /* Pipeline operator assigns 5 to z (10 will be the sum) */

/* labeled function with optional argument */
let sum2 = (~x, ~y=2., ()) => x +. y; /* signature (~x:float, ~y:float=?, unit) => float; */

let add3 = sum2(~x=3.); /* add3 is another function since everything is curried */

sum2(~x=3., ()); /* however calling sum2 with unit means I'm done and I want the sum */

/* VARIANTS */
/* Record defintion to be used for my variant */
type wheels = {
  frontWheels: int,
  backWheels: int,
};

/* Definition of my variant */
type vehicle =
  | None
  | Car
  | Motorcycle
  | MadeUp(wheels);

/* regular switch function - note reason tells me I have a warning that this switch isn't exhaustive */
let getVehicleDescriptionTemp = (v: vehicle) =>
  switch (v) {
  | None => "No Vehicle Present"
  };

/* shorthand definition for a switch */
let getVehicleDescription =
  fun
  | None => "No Vehicle Present"
  | Car => "Two front-wheels and Two back-wheels"
  | Motorcycle => "One front-wheel and One back-wheel"
  /* Destructuring of variables and string interpolation Bucklescript style */
  | MadeUp({frontWheels, backWheels}) => {j| $frontWheels front-wheels and $backWheels back-wheels|j};

/* Applying my switch */
let madeUpCar = MadeUp({frontWheels: 2, backWheels: 3});

/* Create a cube (w, h, d) - the below construct is known as a tuple */
let cube = (2, 12, 3);

/* Now use some pattern matching on the tuple */
let getCube1Makeup =
  switch (cube) {
  | (w, h, d) when h > w && h > d => "You have a tall skinny cube"
  | (_, _, _) => "You have a cube"
  };