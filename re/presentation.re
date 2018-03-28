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
          googleFont: false,
          styles: [|"300"|],
        },
        secondary: {
          name: "Helvetica",
          googleFont: false,
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
        <Heading fit=true> (s("Reason & BuckleScript Intro")) </Heading>
        <Text textFont="secondary"> (s("Front-End Party March 2018")) </Text>
        <Text textFont="quarternary"> (s("Steven Scaffidi")) </Text>
        <Text textFont="secondary">
          <Link href="https://github.com/sscaff1" target="_blank">
            <i className="fab fa-github" />
          </Link>
          <Link href="https://twitter.com/Steven_Scaffidi" target="_blank">
            <i className="fab fa-twitter" />
          </Link>
          <Link href="mailto:sscaff1@gmail.com">
            <i className="fas fa-envelope" />
          </Link>
        </Text>
      </Slide>
      <Slide>
        <Heading fit=true> (s("What is Reason?")) </Heading>
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
        <Heading fit=true> (s("What is BuckleScript?")) </Heading>
        <List>
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
      <Slide>
        <Heading> (s("Example")) </Heading>
        <Link href="slider.html" target="_blank" textColor="secondary">
          (s("Slider"))
        </Link>
      </Slide>
      <Slide bgColor="secondary">
        <Heading> (s("Questions?")) </Heading>
        <Text textFont="secondary">
          <Link href="http://nola-reason-intro.surge.sh/" target="_blank">
            (s("Presentation"))
          </Link>
        </Text>
        <Text textFont="secondary">
          <Link
            href="https://github.com/sscaff1/nola-reason-intro"
            target="_blank">
            (s("Source Code"))
          </Link>
        </Text>
        <Text textFont="secondary">
          <Link href="https://github.com/sscaff1" target="_blank">
            <i className="fab fa-github" />
          </Link>
          <Link href="https://twitter.com/Steven_Scaffidi" target="_blank">
            <i className="fab fa-twitter" />
          </Link>
          <Link href="mailto:sscaff1@gmail.com">
            <i className="fas fa-envelope" />
          </Link>
        </Text>
      </Slide>
    </Deck>,
};