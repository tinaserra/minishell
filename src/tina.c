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

//int	ft_isalnum(int c)
//{
//	if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
//	|| (c >= 'A' && c <= 'Z')))
//		return (0);
//	return (1);
//}

void	print_list(t_list *args)
{
	t_list *list;
	int i;

	list = args;
	i = 0;
	while (list)
	{
		i++;
		printf("%d ", i);
		printf("arg = |%s|\n", list->content);
		list = list->next;

	}
}

int		get_args(t_minishell *ms, t_list *args)
{

	printf("GET ARGS\n");
	int		len;
	//int i;
	char	*tmp;


	printf("1 |%c|\n", *ms->line);
	//i = 0;
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
		ms->line -= len;
		printf("2 |%c|\n", *ms->line);
		printf("len = %d\n", len);
		tmp = ft_calloc(len + 1, 1);
		printf("1 tmp = |%s|\n", tmp);
		ft_strncpy(tmp, (char *)ms->line, len);
		printf("2 tmp = |%s|\n", tmp);
		//printf("%p\n", args);
		//if (args)
		//{
			//printf("NIQUE TES GRANDS MORTS\n");
			ft_lstadd_back(&args, ft_lstnew(tmp));

		printf("%s\n", args->content);
		//}
		//else
		//	args = ft_lstnew(tmp);
		free(tmp);
		tmp = NULL;
		ms->line += len;
		printf("3 |%c|\n", *ms->line);
	}
	print_list(args);
	return (0);
}

int		parse_echo(t_minishell *ms)
{
	t_list	*args;
	printf("PARSE ECHO\n");

	args = malloc(sizeof(t_list));
	args = NULL;
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

	return(get_args(ms, args));
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