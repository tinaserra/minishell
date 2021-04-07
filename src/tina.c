#include "minishell.h"

		//ms->mask |= IS_CD;
		//ms->mask |= IS_PWD;
		//ms->mask |= IS_EXPORT; // int is_export = 1;
		//ms->mask |= IS_UNSET;
		//ms->mask |= IS_ENV;
		//ms->mask |= IS_EXIT;

	//int i;
	//int		len;
	//char	**cmds;

	//cmds = ft_split(*(ms->line), " ");
	//len = ft_strs_tab_size(cmds);
	//i = 0;
	//while (i < len)
	//{
	//	printf("%s\n", cmds[i]);
	//	i++;
	//}

int	ft_isalnum(int c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
	|| (c >= 'A' && c <= 'Z')))
		return (0);
	return (1);
}

void	get_args(ms);
{
	//ft_lstnew(/* content (void *)*/);
	while (*(ms->line) != ' ' && *(ms->line) != ';' && *(ms->line != '\0')
	{
		if (ft_isalnum(*(ms->line)) == 1)
		{

		}
	}
}

void	parse_echo(t_minishell *ms)
{
	ms->mask |= IS_ECHO;
	ms->line += 4;
	printf("|%c|\n", *ms->line);
	while (*(ms->line) == ' ')
		*(ms->line)++;
	if (ft_strnstr(*(ms->line), "-n", 2) != 0)
	{
		ms->mask |= IS_NL;
		ms->line += 2;
	}
	get_args(ms);
	execute_echo(ms); // #john
}


void	get_cmds(t_minishell *ms)
{
	if (ft_strnstr((char *)ms->line, "echo", 4) != 0)
		parse_echo(ms);
	else if (ft_strnstr((char *)ms->line, "cd", 2) != 0)
		parse_cd(ms);
	else if (ft_strnstr((char *)ms->line, "pwd", 3) != 0)
		parse_pwd(ms);
	else if (ft_strnstr((char *)ms->line, "export", 6) != 0)
		parse_export(ms);
	else if (ft_strnstr((char *)ms->line, "unset", 5) != 0)
		parse_unset(ms);
	else if (ft_strnstr((char *)ms->line, "env", 3) != 0)
		parse_env(ms);
	else if (ft_strnstr((char *)ms->line, "exit", 4) != 0)
		parse_exit(ms);
	else
		//execve ou error
}

void		parsing()
{
	int i;

	printf("|%s|\n", ms->line);
	while (*(ms->line))
	{
		i = 0;
		while (ms->line[i] != ';' && ms->line[i])
		{
			while (ms->line[i] == ' ')
				i++;
			get_cmds(ms);
			i++;
		}
		// reset mask + args
		*(ms->line)++;
	}
}

void fonction(t_minishell *ms) // parsing
{
	printf("Le temps est bon, le ciel est bleu !\n");
	parsing(ms);
}