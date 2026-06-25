# uno++

Simple game inspired by Uno with extra tweaks.

Written using C programming language and uses around 230 kilobytes of RAM.

**The name UNO is a registered trademark of its respective owner. All rights to the name, logo, and related branding are fully reserved and protected under applicable trademark laws.**

## Rules

[Uno rules](<https://en.wikipedia.org/wiki/Uno_(card_game)>)

In short, this game uses official Uno rules with additional house rules.

Most notable differences are those that you don't have to say word `uno` when you have only one card left; and when +2 and +4 cards are played, next player is not skipped.

## Compile

## Installing dependencies

### Windows

- Git
- Visual Studio with C/C++ development extension
- CMake
- json-c (x64 static version from vcpkg)

### Linux

| Package: | Command:                                                                                                                           |
| -------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| git      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install git`</td><td>`pacman -S git`</td></tr></table>              |
| make     | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install make`</td><td>`pacman -S make`</td></tr></table>            |
| gcc      | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install gcc`</td><td>`pacman -S gcc`</td></tr></table>              |
| json-c   | <table><tr><th>Debian</th><th>Arch Linux</th></tr><td>`apt-get install libjson-c-dev`</td><td>`pacman -S json-c`</td></tr></table> |

## Compiling & running

### Windows

| Number: | Step:                                                             | Command:                                              |
| ------- | ----------------------------------------------------------------- | ----------------------------------------------------- |
| 1       | Clone a repository                                                | `git clone https://github.com/Andrej123456789/uno_pp` |
| 2       | Enter the `src` directory                                         | `cd uno_pp\src`                                       |
| 3       | Create the `build` directory and enter it                         | `mkdir build && cd build`                             |
| 4       | Run CMake                                                         | `cmake .. -DVCPKG_ROOT="path_to_vcpkg"`               |
| 5       | Open Visual Studio and build the solution                         |                                                       |
| 6       | Run the program located inside the `Debug` or `Release` folder    | `.\Debug\uno_pp.exe` or `.\Release\uno_pp.exe`        |
| 7       | Enter `Developer Command Prompt` and enter the `client` directory | `cd path_to_client_directory`                         |
| 8       | Compile and run the client                                        | `cl client_windows.c && .\client_windows <ip> <port>` |

**Notice! In order not to use Visual Studio (you still need to have it installed), you can use nmake. Run CMake with following command: `cmake -G "NMake Makefiles" -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl -DVCPKG_ROOT="path_to_vcpkg" ..`. To compile the project use command `nmake`. You need to be inside _Developer Command Prompt_ or _Developer Powershell_.**

### Linux

| Number: | Step:                        | Command:                                                           |
| ------- | ---------------------------- | ------------------------------------------------------------------ |
| 1       | Clone a repository           | `git clone https://github.com/Andrej123456789/uno_pp`              |
| 2       | Enter the `src` directory    | `cd uno_pp/src`                                                    |
| 3       | Compile                      | `make`                                                             |
| 4       | Run the program              | `make run`                                                         |
| 5       | Enter the `client` directory | `cd ../client`                                                     |
| 6       | Compile and run the client   | `gcc client_posix.c -o client_posix && ./client_posix <ip> <port>` |

## Default settings

default.json:

```json
{
  "match_points": 250, // number of points required to win a match
  "points_path": "settings/points.json", // path to the JSON file storing points
  "players": 2, // number of players in the game [2, INT32_MAX>
  "tweaks": [
    {
      "colors": true, // are colors enabled
      "stacking": true, // is stacking allowed
      "swap_card": true, // is swap card present
      "seven_o": false // is SevenO house rule enabled
    }
  ],
  "network": [
    {
      "enabled": true, // is multiplayer enabled
      "port": 5555 // port number
    }
  ]
}
```

points.json:

```json
// reset manually after finishing a match
// otherwise, don't change these values manually
{ "Player 0": 0, "Player 1": 0 }
```

## External dependencies

- [c-vector](https://github.com/eteran/c-vector)
