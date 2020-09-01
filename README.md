# Filler

Filler is a School 42 project. The purpose of this project is to create bot for map-filler puzzle game.


## How to clone?

```
git clone <repository url>
```

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## How to run program?

There are resources that are provided by task — a virtual machine (`filler_vm`), maps, and bots. They are located at the [`resources` directory](/resources).

The virtual machine moderates a game. It needs [a map file](/resources/maps) and [bots](/resources/players).

The purpose of the project is to create own bot.

A name of the created bot is `filler_rschmele`. It will be created after `make` command and placed at the root of the directory.

You can run the virtual machine with the following command:

```
./filler_vm -f MAP_FILE -p1 PLAYER_FILE -p2 PLAYER_FILE
```
