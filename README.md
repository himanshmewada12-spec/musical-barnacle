# musical-barnacle
A game called bot-arena. No time to think, just dodge and survive!

## Common Problems:
- Please download the needed dependencies for SFML before building.
- Version of SFML used: 3.0.2

## Formatting for Contribution
- Use clang-format, the formatting is mentioned in the .clang-format file. clang-format will pick it up automatically, you just need to run `$ clang-format -i src/main.cpp`

## Contribution
- This repository is always open to any contribution that makes the game better.
- Always make sure to analyze your code with clang-tidy before submitting.

## Some Extra Info:
- Some images present in include are for the README.md and not for the game. You should delete those images when building, as they are no longer needed.
- The Cmake automatically generates the compile_commands.json. So, if you want you can link that with your IDE for good integration.
- You can also stop the generation of compile_commands.json by removing this line from CMakeLists.txt: `set(CMAKE_EXPORT_COMPILE_COMMANDS ON)`
