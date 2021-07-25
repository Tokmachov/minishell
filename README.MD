# minishell<br/>
### to start<br/>
cd to project dir<br/>
make<br/>
./minishell<br/>

### functions<br/>
• Shows a prompt when waiting for a new command<br/>
• Searches and launches the right executable (based on the PATH variable or by using relative or absolute path) like in bash<br/>
• implements the builtins like in bash:<br/>
◦ echo with option ’-n’<br/>
◦ cd with only a relative or absolute path<br/>
◦ pwd without any options<br/>
◦ export without any options<br/>
◦ unset without any options<br/>
◦ env without any options and any arguments ◦ exit without any options<br/>
• ; in the command should can separate commands like in bash<br/>
• ’ and " work like in bash except for multiline commands<br/>
• Redirections < > “>>” work like in bash except for file descriptor aggregation<br/>
• Pipes | work like in bash<br/>
• Environment variables ($ followed by characters) work like in bash <br/>
• $? should work like in bash<br/>
• ctrl-C, ctrl-D and ctrl-\ have the same result as in bash<br/>
