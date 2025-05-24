# Scoreboard

A retro-style scoreboard management program written in C, inspired by 1980s arcade games. This project allows users to add players, manage scores, display rankings with tie handling, and save/load data to/from a file.

![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg)

## Features

- **Player Management**: Add players with names (up to 48 characters) and non-negative scores.
- **Ranking System**: Displays rankings with support for ties (ex-aequo) and proper rank progression.
- **File I/O**: Save and load scores to/from `scores.txt` for persistent data.
- **Retro Interface**: ASCII art banner at startup for a nostalgic 1980s arcade feel.
- **User-Friendly Menu**: Options to add players, display the scoreboard, view credits, or quit.
- **Input Validation**: Robust handling of invalid inputs (empty names, commas, negative scores, etc.).

## Tech Stack

- **Language**: C
- **Compiler**: GCC (via MinGW or Code::Blocks)
- **Tools**: Git, Code::Blocks
- **Key Libraries**: Standard C libraries (stdio.h, string.h, ctype.h)

### Prerequisites

- A C compiler (e.g., GCC).
- Code::Blocks or any IDE/terminal that supports C compilation.
- Git (to clone the repository).

### Installation

1. **Clone the repository**:
	```	
	git clone https://github.com/ton-username/Scoreboard.git
	cd Scoreboard
	```

2. **Compile the game**:
	```
	gcc -o scoreboard main.c
	```

3. **Run the game**:
	```
	./scoreboard.exe
	```

### License

This project is licensed under the MIT License - see the LICENSE file for details.

### Crédits

Developed by PHForge. Special thanks to my wife and son for their patience and love.

### Example Output

```

  _____                    _                         _
 / ____|                  | |                       | |
| (___   ___ ___  _ __ ___| |__   ___   __ _ _ __ __| |
 \___ \ / __/ _ \| '__/ _ \ '_ \ / _ \ / _` | '__/ _` |
 ____) | (_| (_) | | |  __/ |_) | (_) | (_| | | | (_| |
|_____/ \___\___/|_|  \___|_.__/ \___/ \__,_|_|  \__,_|

       by PHForge

Menu:
1. Add a player
2. Display Scoreboard
3. Credit
4. Quit

Select menu: 2

Scoreboard:

1. Batman : 500
2. Iron Man : 333 (ex-aequo)
2. James Bond : 333 (ex-aequo)
4. Harry Potter : 250
```