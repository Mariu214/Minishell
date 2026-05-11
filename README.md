*This project has been created as part of the 42 curriculum by malaimo and jdelmott*

# Description
This project consists of creating a **rudimentary Shell** in C, capable of executing commands and handling basic user interactions. The primary goal is to gain a deep understanding of process management, file descriptors, and inter-process communication via pipes.

**Key Features:**
* **Full Parsing**: Token management (words, pipes, redirections) and quote handling (single and double).
* **Execution**: Launching binaries via the `PATH` environment variable or through relative/absolute paths.
* **Built-ins**: Custom implementation of `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
* **Pipes & Redirections**: Handling of pipes (`|`) and redirections (`<`, `>`, `<<`, `>>`).
* **Signals**: Handling of `Ctrl+C`, `Ctrl+\`, and `Ctrl+D`.

# Instructions
To compile the program, simply run the command `make` in your terminal; this will create the `minishell` executable. To start the shell, run it with `./minishell`.

Once the prompt appears, you can use it like a standard terminal:
* **Basic commands**: Type any command like `ls`, `cat`, or `grep`.
* **Built-ins**: Use internal commands such as `cd` to move, `echo -n` to display text, or `export` to set variables.
* **Redirections**: You can send output to a file with `< Makefile cat` or chain commands using pipes like `cat Makefile | grep RESET`.
* **Exit**: To leave the program, simply type `exit` or press `Ctrl+D`.

# Resources
<br />
- https://tiswww.case.edu/php/chet/readline/readline.html <br />
- https://www.youtube.com/watch?v=Vax97MIL_uI&list=PLKUb7MEve0TjHQSKUWChAWyJPCpYMRovO&index=60 <br />
- https://man7.org/linux/man-pages/man3/readline.3.html <br />
- https://www.gnu.org/savannah-checkouts/gnu/bash/manual/ <br />
- https://man7.org/linux/man-pages/man3/termios.3.html <br />
- https://stackoverflow.com/questions/24538470/what-does-dup2-do-in-c <br />
- https://www.ibm.com/docs/fr/aix/7.3.0?topic=w-wait-waitpid-wait3-wait364-wait4-subroutine <br />
