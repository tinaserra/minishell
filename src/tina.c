#include "minishell.h"

//int		parse_echo(t_minishell *ms)
//{
//	// t_list	*args;
//	printf("PARSE ECHO\n");

//	// args = NULL;
//	ms->mask |= IS_ECHO;
//	ms->line += 4;
//	while (*(ms->line) == ' ')
//		ms->line++;
//	if (ft_strnstr(ms->line, "-n", 2) != 0)
//	{
//		ms->mask |= IS_NL;
//		ms->line += 2;
//	}
//	while (*(ms->line) == ' ')
//		ms->line++;

//	return(get_args(ms));
//	//execute_echo(ms); // #john
//}


//int		get_cmds(t_minishell *ms)
//{
//	printf("GET CMDS\n");
//	if (ft_strnstr(ms->line, "echo", 4) != 0)
//		return(parse_echo(ms));
//	//else if (ft_strnstr(ms->line, "cd", 2) != 0)
//	//	parse_cd(ms);
//	//else if (ft_strnstr(ms->line, "pwd", 3) != 0)
//	//	parse_pwd(ms);
//	//else if (ft_strnstr(ms->line, "export", 6) != 0)
//	//	parse_export(ms);
//	//else if (ft_strnstr(ms->line, "unset", 5) != 0)
//	//	parse_unset(ms);
//	//else if (ft_strnstr(ms->line, "env", 3) != 0)
//	//	parse_env(ms);
//	//else if (ft_strnstr(ms->line, "exit", 4) != 0)
//	//	parse_exit(ms);
//	//else
//		//execve ou error
//	return (-1);
//}


void fonction() // parsing
{
	parsing();
}
