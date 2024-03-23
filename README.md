# Basic Command line interpreter CLI

# Simple Shell

This is a simple command-line shell implemented in C. It provides basic functionalities such as executing commands, changing directories, and handling process creation and termination.

## Features

- Execute commands entered by the user, including system commands like expr.
- Change directories using the cd command.
- Basic error handling for command execution.
- Supports exiting the shell using the exit command.

## Usage

1. Clone the repository:
git clone <repository_url>

2.Run the code:
gcc cli.c
./a.out

## How it works

The shell reads commands entered by the user, parses them into individual arguments, and executes them as separate processes using `fork()` and `execvp()`. It also handles built-in commands such as `cd` and `exit`.

## License

This project is licensed under the MIT License.
