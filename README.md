# mfGUI #
A simple SFML GUI library

## How to compile

### Install dependencies 

``sudo dnf install SFML SFML-devel``

``sudo dnf install boost boost-devel``

### Generate ninja build file

``cmake -G Ninja .``

### Run ninja

``ninja .``

### Custom commands

- Clean build files: `ninja clean`
- Run tests: `ninja test`
- Run the application: `ninja run`