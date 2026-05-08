# PARSING

# EXEC

ls | <----------------------------t pas obligee si t'a la flemme les les ctrl marchent pas avec une pipe a la fin(ej crois que c'est exactement pareil que heredoc)
pipe> (ctrl)

<!-- ATOLL REGLE -->

<!-- >minishell << LIM cat <---------------------------------------------------------------------------NORMALEMENT C BON
heredoc> l
heredoc> l
heredoc> l
heredoc> LIM
==1096358== 
==1096358== FILE DESCRIPTORS: 0 open (0 inherited) at exit.
==1096358== 
==1096358== HEAP SUMMARY:
==1096358==     in use at exit: 229,110 bytes in 250 blocks
==1096358==   total heap usage: 691 allocs, 441 frees, 255,142 bytes allocated
==1096358== 
==1096358== 2 bytes in 1 blocks are definitely lost in loss record 3 of 88
==1096358==    at 0x483FB26: malloc (vg_replace_malloc.c:447)
==1096358==    by 0x407667: ft_itoa (ft_itoa.c:44)
==1096358==    by 0x40509D: rtv (expand_variables.c:36)
==1096358==    by 0x405139: with_dollar (expand_variables.c:53)
==1096358==    by 0x40537D: expander (expand_variables.c:94)
==1096358==    by 0x40540C: check_expand (expand_variables.c:111)
==1096358==    by 0x403196: init_lexer (lexer.c:63)
==1096358==    by 0x4031D2: test_lexer (lexer.c:72)
==1096358==    by 0x403C3E: init_loop (init_data.c:26)
==1096358==    by 0x4006B5: main (main.c:25)
==1096358== 
==1096358== 2 bytes in 1 blocks are definitely lost in loss record 4 of 88
==1096358==    at 0x483FB26: malloc (vg_replace_malloc.c:447)
==1096358==    by 0x407667: ft_itoa (ft_itoa.c:44)
==1096358==    by 0x4050E1: rtv (expand_variables.c:40)
==1096358==    by 0x405139: with_dollar (expand_variables.c:53)
==1096358==    by 0x40537D: expander (expand_variables.c:94)
==1096358==    by 0x40540C: check_expand (expand_variables.c:111)
==1096358==    by 0x403196: init_lexer (lexer.c:63)
==1096358==    by 0x4031D2: test_lexer (lexer.c:72)
==1096358==    by 0x403C3E: init_loop (init_data.c:26)
==1096358==    by 0x4006B5: main (main.c:25)
==1096358== 
==1096358== LEAK SUMMARY:
==1096358==    definitely lost: 4 bytes in 2 blocks
==1096358==    indirectly lost: 0 bytes in 0 blocks
==1096358==      possibly lost: 0 bytes in 0 blocks
==1096358==    still reachable: 0 bytes in 0 blocks
==1096358==         suppressed: 229,106 bytes in 248 blocks
==1096358== 
==1096358== For lists of detected and suppressed errors, rerun with: -s
==1096358== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
l
l
l -->


<!-- Ajouter un memeset pour initialiser la struct termios. <---------------------------------------------------------------------------NORMALEMENT C BON
>minishell cat Makefile | cat | cat | cat 
==1095768== Syscall param ioctl(TCSET{S,SW,SF}) points to uninitialised byte(s)
==1095768==    at 0x49B48B1: tcsetattr (tcsetattr.c:79)
==1095768==    by 0x402A1A: ft_shellerror_gc (ft_shellerror_gc.c:21)
==1095768==    by 0x4011D6: in_pipe (parsing_pipe.c:27)
==1095768==    by 0x401244: apply_pipe (parsing_pipe.c:44)
==1095768==    by 0x401320: find_pipe (parsing_pipe.c:69)
==1095768==    by 0x40173C: init_parser (parsing.c:23)
==1095768==    by 0x403C5A: init_loop (init_data.c:28)
==1095768==    by 0x4006B5: main (main.c:25)
==1095768==  Address 0x1ffefff9b0 is on thread 1's stack
==1095768==  in frame #0, created by tcsetattr (tcsetattr.c:45)
==1095768==  Uninitialised value was created by a stack allocation
==1095768==    at 0x4029D4: ft_shellerror_gc (ft_shellerror_gc.c:16)
==1095768==  -->

<!---------------------------------------------------------------------------ALORS BASH FAIS LA MEME DONC NIQUE
>minishell echo -nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn -nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn test
test>minishecho -nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn -nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn test
test>minish -->

<!-- Quand exit : <---------------------------------------------------------------------------NORMALEMENT C BON
==1094247== FILE DESCRIPTORS: 0 open (0 inherited) at exit.
==1094247== 
==1094247== HEAP SUMMARY:
==1094247==     in use at exit: 229,044 bytes in 264 blocks
==1094247==   total heap usage: 705 allocs, 441 frees, 255,204 bytes allocated
==1094247== 
==1094247== 10 bytes in 3 blocks are definitely lost in loss record 6 of 83
==1094247==    at 0x483FB26: malloc (vg_replace_malloc.c:447)
==1094247==    by 0x407667: ft_itoa (ft_itoa.c:44)
==1094247==    by 0x40509D: rtv (expand_variables.c:36)
==1094247==    by 0x405139: with_dollar (expand_variables.c:53)
==1094247==    by 0x40537D: expander (expand_variables.c:94)
==1094247==    by 0x40540C: check_expand (expand_variables.c:111)
==1094247==    by 0x403196: init_lexer (lexer.c:63)
==1094247==    by 0x4031D2: test_lexer (lexer.c:72)
==1094247==    by 0x403C3E: init_loop (init_data.c:26)
==1094247==    by 0x4006B5: main (main.c:25)
==1094247== 
==1094247== 10 bytes in 3 blocks are definitely lost in loss record 7 of 83
==1094247==    at 0x483FB26: malloc (vg_replace_malloc.c:447)
==1094247==    by 0x407667: ft_itoa (ft_itoa.c:44)
==1094247==    by 0x4050E1: rtv (expand_variables.c:40)
==1094247==    by 0x405139: with_dollar (expand_variables.c:53)
==1094247==    by 0x40537D: expander (expand_variables.c:94)
==1094247==    by 0x40540C: check_expand (expand_variables.c:111)
==1094247==    by 0x403196: init_lexer (lexer.c:63)
==1094247==    by 0x4031D2: test_lexer (lexer.c:72)
==1094247==    by 0x403C3E: init_loop (init_data.c:26)
==1094247==    by 0x4006B5: main (main.c:25)
==1094247== 
==1094247== LEAK SUMMARY:
==1094247==    definitely lost: 20 bytes in 6 blocks
==1094247==    indirectly lost: 0 bytes in 0 blocks
==1094247==      possibly lost: 0 bytes in 0 blocks
==1094247==    still reachable: 0 bytes in 0 blocks
==1094247==         suppressed: 229,024 bytes in 258 blocks
==1094247== 
==1094247== For lists of detected and suppressed errors, rerun with: -s
==1094247== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0) -->

<!-- ctrl c = 130
ctr \ = 131
- Handle ’ (single quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the meta-
characters in the quoted sequence except for $ (dollar sign) return 127 -->

<!-- - < should redirect input.
- > should redirect output. -->
<!-- - << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history! -->
<!-- - >> should redirect output in append mode. -->


<!-- - ctrl-C end the current process and return to prompt. -->
<!-- - ctrl-D send EOF to the current process -->
<!-- - ctrl-\ quit process (core dumped). -->

## interactive mode
<!-- - ctrl-C displays a new prompt on a new line.
<!-- - ctrl-D exits the shell. -->
<!-- - ctrl-\ does nothing. -->

<!-- - Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.

- Handle environment variables ($ followed by a sequence of characters) which
should expand to their values -->

<!-- - Handle $? which should expand to the exit status of the most recently executed
foreground pipeline. -->

<!-- - echo with option -n
- cd with only a relative or absolute path
<!-- - pwd with no options -->
<!-- - export with no options -->
<!-- unset with no options attention au readonly -->
<!-- - env with no options or arguments -->
<!-- - exit with no options -->



erreur a gerer

parsing redirection
builtin aevc  pipe
quote marche psd