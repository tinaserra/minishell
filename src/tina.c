#include "minishell.h"

		//ms->mask |= IS_CD;
		//ms->mask |= IS_PWD;
		//ms->mask |= IS_EXPORT; // int is_export = 1;
		//ms->mask |= IS_UNSET;
		//ms->mask |= IS_ENV;
		//ms->mask |= IS_EXIT;

// void	print_list(t_list *args)
// {
// 	t_list *list;
// 	int i;

// 	list = args;
// 	i = 0;
// 	while (list)
// 	{
// 		i++;
// 		printf("%d ", i);
// 		printf("arg = |%s| ", list->data);
// 		list = list->next;
// 		printf("\n");
// 	}
// }

void	print_list(t_list *l)
{
	if (l == NULL)
		printf("la liste est vide\n");
	while (l != NULL)
	{
		printf("|%s| ", l->data);
		l = l->next;
	}
	printf("\n");
}

int		get_args(t_minishell *ms)
{
	printf("GET ARGS\n");
	int		len;
	char	*tmp;
	t_list	*args;
	int pos = 0;

	args = NULL;

	while (*(ms->line)!= '\0')
	{
		while (*(ms->line) == ' ')
			ms->line++;
		len = 0;
		while (*(ms->line) != '"' && *(ms->line) != '\0')
		{
			if (*(ms->line) == ';' || *(ms->line) == ' ')
				break ;
			ms->line++;
			len++;
		}
		tmp = ft_calloc(len + 1, 1);
		ms->line -= len;
		ft_strncpy(tmp, (char *)ms->line, len);
		printf("tmp = |%s| len = %d\n", tmp, len);
		args = ft_lstadd_at(args, tmp, pos);
		free(tmp);
		tmp = NULL;
		pos++;
		ms->line += len;
		print_list(args);
	}
	return (0);
}

int		parse_echo(t_minishell *ms)
{
	// t_list	*args;
	printf("PARSE ECHO\n");

	// args = NULL;
	ms->mask |= IS_ECHO;
	ms->line += 4;
	while (*(ms->line) == ' ')
		ms->line++;
	if (ft_strnstr((char *)ms->line, "-n", 2) != 0)
	{
		ms->mask |= IS_NL;
		ms->line += 2;
	}
	while (*(ms->line) == ' ')
		ms->line++;

	return(get_args(ms));
	//execute_echo(ms); // #john
}


int		get_cmds(t_minishell *ms)
{
	printf("GET CMDS\n");
	if (ft_strnstr((char *)ms->line, "echo", 4) != 0)
		return(parse_echo(ms));
	//else if (ft_strnstr((char *)ms->line, "cd", 2) != 0)
	//	parse_cd(ms);
	//else if (ft_strnstr((char *)ms->line, "pwd", 3) != 0)
	//	parse_pwd(ms);
	//else if (ft_strnstr((char *)ms->line, "export", 6) != 0)
	//	parse_export(ms);
	//else if (ft_strnstr((char *)ms->line, "unset", 5) != 0)
	//	parse_unset(ms);
	//else if (ft_strnstr((char *)ms->line, "env", 3) != 0)
	//	parse_env(ms);
	//else if (ft_strnstr((char *)ms->line, "exit", 4) != 0)
	//	parse_exit(ms);
	//else
		//execve ou error
	return (-1);
}

void		parsing(t_minishell *ms)
{
	//int i;

	printf("|%s|\n", ms->line);
	while (*(ms->line) == ' ')
		ms->line++;
	if (get_cmds(ms) == -1)
		ft_putstr_fd(2, "command not found\n");
	//while (*(ms->line))
	//{
		//i = 0;
	//	while (ms->line[i] != ';' && ms->line[i])
	//	{
	//		while (ms->line[i] == ' ')
	//			i++;
	//		i++;
	//	}
	//	// reset mask + args
	//	ms->line++;
	//}
}

void fonction() // parsing
{
	parsing(ms);
}