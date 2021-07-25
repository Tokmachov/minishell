#minishell
###to start
make
./minishell

###functions
• Shows a prompt when waiting for a new command
• Searches and launches the right executable (based on the PATH variable or by using relative or absolute path) like in bash
• implements the builtins like in bash:
◦ echo with option ’-n’
◦ cd with only a relative or absolute path
◦ pwd without any options
◦ export without any options
◦ unset without any options
◦ env without any options and any arguments ◦ exit without any options
• ; in the command should can separate commands like in bash
• ’ and " work like in bash except for multiline commands
• Redirections < > “>>” work like in bash except for file descriptor aggregation
• Pipes | work like in bash
• Environment variables ($ followed by characters) work like in bash 
• $? should work like in bash
• ctrl-C, ctrl-D and ctrl-\ have the same result as in bash
