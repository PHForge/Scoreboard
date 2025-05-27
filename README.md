# Scoreboard

A retro-style scoreboard management program crafted in C, inspired by 1980s arcade games. This project enables users to manage players, track scores with tie-aware rankings, and persist data via file I/O, showcasing modular design, robust input validation, and cross-platform compatibility for a seamless user experience.


![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Language](https://img.shields.io/badge/language-C-green.svg)

<br>

## Features 📋

- **Player Management**: Add players with names (up to 48 characters) and non-negative scores, with validation to prevent invalid entries.
- **Ranking System**: Displays sorted rankings with tie handling (ex-aequo) using a custom sorting algorithm for accurate rank progression.
- **File I/O**: Persists scores to `scores.txt` using robust file operations, ensuring data integrity across sessions.
- **Retro Interface**: Features an ASCII art banner at startup, optimized for terminal display with a nostalgic 1980s arcade aesthetic.
- **User-Friendly Menu**: Modular menu system for adding players, viewing the scoreboard, accessing credits, or exiting the program.
- **Input Validation**: Comprehensive checks for empty names, commas, negative scores, and other edge cases to ensure stability.


<br>

## System Requirements ⚙️

The following components are required to build, run, or contribute to this project:

| Component          | Requirement                              | Notes                                      |
|--------------------|------------------------------------------|--------------------------------------------|
| Language | C                                      | Core language used for the project         |
| Compiler       | GCC                                      | Ensure GCC is installed (e.g., MinGW for Windows) |
| Libraries      | Standard C Libraries (stdio.h, string.h, ctype.h) | Included with standard C installations      |
| IDE/Editor     | Code::Blocks or any C-compatible IDE/terminal | Other IDEs like VS Code or CLion can be used |
| Version Control | Git                                     | Required to clone the repository           |

> [!TIP]
> For optimal setup, install GCC via [MinGW](https://www.mingw-w64.org/) on Windows or use a package manager like `apt` or `brew` on Linux/macOS to install Git and GCC.

<br>

## Installation </>

1. **Clone the repository**:
	```bash	
	git clone https://github.com/ton-username/Scoreboard.git
	cd Scoreboard
	```

2. **Compile the game**:
	- Windows: Use MinGW and run:
		```bash
		gcc -o scoreboard main.c
		```
	- Linux/macOS: Ensure GCC is installed (`sudo apt install gcc` or `brew install gcc`) and run:
		```bash
		gcc -o scoreboard main.c
		```
3. **Run the game**:
	```bash
	./scoreboard
	```

<br>

## License 🧾

This project is licensed under the MIT License - see the LICENSE file for details.

<br>

## Crédits ☕

> Developed by PHForge. 
> Feel free to reach out via [GitHub](https://github.com/PHForge) for feedback or collaboration ideas!

> Special thanks ❤️ to my wife and son for their patience and love.

<br>

## Example Output 💻

```c

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