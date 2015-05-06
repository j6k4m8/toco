# toco

The repository contains two directories which are *entirely discrete projects*: One for [Arduino](https://arduino.cc), and one for [Processing](https://processing.org/).

The Arduino sketch can be loaded onto the Arduino hardware, and will transmit data back via `Serial` to the laptop (when plugged in with USB).

The Processing sketch is run through the JVM included with the Processing software. After the Arduino is successfully tied into the Serial stream (which should be a few seconds after the upload finishes), run the Processing sketch to graph the outputs.

Note that while the software looks similar, Processing is a Java derivative and Arduino is a C derivative, and their code cannot be mixed.
