# PARSING




# EXEC

- Handle ’ (single quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence except for $ (dollar sign)

- < should redirect input.
- > should redirect output.
<!-- - << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history! -->
- >> should redirect output in append mode.


- ctrl-C displays a new prompt on a new line.
<!-- - ctrl-D exits the shell. -->
- ctrl-\ does nothing.

- Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.

- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options