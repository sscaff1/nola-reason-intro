open BsSpectacle;

let theme =
  Theme.(
    createTheme(
      {
        primary: "#1F2022",
        secondary: "white",
        tertiary: "#03A9FC",
        quarternary: "#CECECE",
      },
      {
        primary: {
          name: "Montserrat",
          googleFont: true,
          styles: [|"300"|],
        },
        secondary: {
          name: "Helvetica",
          googleFont: true,
          styles: [|"100"|],
        },
        tertiary: simpleFont("monospace"),
      },
    )
  );

let s = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Simple");

let make = _children => {
  ...component,
  render: _self =>
    <Deck transition=[|Fade, Slide|] theme>
      <Slide bgColor="secondary">
        <Heading> (s("Reason Intro")) </Heading>
        <Text textFont="secondary"> (s("Front-End Party March 2018")) </Text>
        <Text textFont="quarternary"> (s("Steven Scaffidi")) </Text>
      </Slide>
      <Slide>
        <Heading> (s("What is Reason?")) </Heading>
        <List>
          <ListItem> (s("New syntax and toolchain for OCaml")) </ListItem>
          <ListItem> (s("Developed by Facebook")) </ListItem>
          <ListItem> (s("100% type coverage guaranteed")) </ListItem>
          <ListItem> (s("Great ecosystem and tooling")) </ListItem>
          <ListItem> (s("Great support for JSX")) </ListItem>
          <ListItem>
            (s("Functional but still gives developers flexibility"))
          </ListItem>
        </List>
      </Slide>
      <Slide>
        <Heading textSize="5rem">
          (s("How does BuckleScript play a role?"))
        </Heading>
        <List>
          <ListItem> (s("Interop with JavaScript")) </ListItem>
          <ListItem>
            (s("Compiles Reason/OCaml to readable JavaScript"))
          </ListItem>
          <ListItem>
            (s("Allows you to leverage the JavaScript eco-system"))
          </ListItem>
          <ListItem> (s("Helps you get started on new projects")) </ListItem>
        </List>
      </Slide>
      <Slide>
        <Heading> (s("Let Binding")) </Heading>
        <List>
          <ListItem> (s("Block Scoped")) </ListItem>
          <ListItem> (s("Immutable bindings")) </ListItem>
          <ListItem> (s("Similar to const in JavaScript")) </ListItem>
        </List>
        <CodePane
          lang="reason"
          textSize="1em"
          source=[%raw
            {| require('raw-loader!../../../assets/letBinding.example')|}
          ]
        />
      </Slide>
      <Slide>
        <Heading> (s("Functions")) </Heading>
        <List>
          <ListItem>
            (s("Types can be explictiy or implicitly defined"))
          </ListItem>
          <ListItem> (s("All functions are curried")) </ListItem>
          <ListItem> (s("Labeled or non-labeled arguments")) </ListItem>
          <ListItem> (s("Optional arguments")) </ListItem>
        </List>
        <CodePane
          lang="reason"
          textSize="1rem"
          source=[%raw
            {| require('raw-loader!../../../assets/function.example')|}
          ]
        />
      </Slide>
      <Slide>
        <Heading> (s("Variants")) </Heading>
        (s("Like a switch statement in JavaScript except much more powerful"))
        <CodePane
          lang="reason"
          textSize="1rem"
          source=[%raw
            {| require('raw-loader!../../../assets/variant.example')|}
          ]
        />
      </Slide>
      <Slide>
        <Heading> (s("Variants")) </Heading>
        (s("(Continued)"))
        <CodePane
          lang="reason"
          textSize="1rem"
          source=[%raw
            {| require('raw-loader!../../../assets/variant.1.example')|}
          ]
        />
      </Slide>
      <Slide>
        <Heading> (s("Variants")) </Heading>
        (s("(Continued)"))
        <CodePane
          lang="reason"
          textSize="1rem"
          source=[%raw
            {| require('raw-loader!../../../assets/variant.2.example')|}
          ]
        />
      </Slide>
    </Deck>,
};