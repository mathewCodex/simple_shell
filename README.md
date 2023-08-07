# 0x16. C - SIMPLE SHELL
The simple shell project aims to progressively build a simple shell that can handle basic commands, including those with arguments, handle errors, and implement built-in commands like exit and env.

### Task 0: Betty Would Be Proud
- Write a beautiful code that passes the Betty checks

### Task 1: Simple shell 0.1
Write a UNIX command line interpreter.
-   Usage: simple_shell
-   Your Shell should:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
-   The prompt is displayed again each time a command has been executed.
-   The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
-   The command lines are made only of one word. No arguments will be passed to programs.
-   If an executable cannot be found, print an error message and display the prompt again.
-   Handle errors.
-   You have to handle the “end of file” condition (Ctrl+D) <br/><br/>
You don’t have to:
-   use the PATH
-   implement built-ins
-   handle special characters : ", ', `, \, *, &, #
-   be able to move the cursor
-   handle commands with arguments

### Task 3: Simple shell 0.2
Simple shell 0.1 +
-   Handle command lines with arguments

### Task 4: Simple shell 0.3
Simple shell 0.2 +
-   Handle the PATH
-   fork must not be called if the command doesn’t exist

### Task 5:  Simple shell 0.4
Simple shell 0.3 +
-   Implement the exit built-in, that exits the shell
-   Usage: exit
-   You don’t have to handle any argument to the built-in exit

### Task 6: Simple shell 1.0
Simple shell 0.4 +
-   Implement the env built-in, that prints the current environment


### Contributors
[Otavie Okuoyo](https://github.com/Otavie) <br/>
[Matthew Emmanuel](https://github.com/mathewCodex)


### Duration:
#### Start Date: Wednesday, July 12, 2023
#### End Date: Thursday, July 27, 2023








<!-- 
# Simple Shell

This is a simple UNIX command line interpreter (shell) that allows users to enter commands and execute them. The shell supports basic command execution, displaying the current environment, and exiting the shell.

## How to Use

1. Clone the repository to your local machine.
2. Compile the code using the following command:

   ```
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
   ```

3. Run the compiled executable:

   ```
   ./simple_shell
   ```

4. The shell will display a prompt (`$`) where you can enter commands.
5. Enter a command and press Enter to execute it.
6. The prompt will be displayed again after each command execution.
7. To exit the shell, enter the command `exit` and press Enter.

## Supported Commands

1. Execution of external commands: You can run any command available in your system, as long as it does not require any arguments.
2. `env` command: Enter `env` to display the current environment variables.

## Limitations

1. The shell only supports commands without arguments.
2. Advanced features like pipes, redirections, and semicolons are not supported.
3. Special characters like quotes, backticks, and ampersands are not handled.

## Additional Notes

1. The shell uses the `getline` function to read user input and the `strtok` function to parse the input into individual command and argument strings.
2. The `execute_command` function uses the `fork` system call to create a child process to execute the entered command.
3. The child process runs the command using `execvp`, and the parent process waits for the child process to complete using `wait`.
