int	exec_binary(t_cmd *cmd)
{
	char	*binary;
	char	**args;
	//t_cmd	*tmp;
	struct stat stats;

	if (cmd->type == PIPE)
	{
		binary = check_path(cmd);
		if (binary)
		{
			free(cmd->cmd);
			cmd->cmd = ft_strdup(binary);
			exec_pipe(cmd);
		}
		else
		{
			if (lstat(cmd->cmd, &stats))
				printf("minishell: %s: command not found\n", cmd->cmd); // ERR
			else
				exec_pipe(cmd);
		}
		free(binary);
	}
	else
	{
		binary = check_path(cmd);
		args = list_to_tab(cmd);
		printf("%s\n", args[0]);
		if (binary)
			exec_command(binary, args);
		else
		{
			printf("abc\n");
			if (lstat(cmd->cmd, &stats))
				printf("minishell: %s: command not found\n", cmd->cmd); // ERR
			else
				exec_command(cmd->cmd, args);
		}
		free(binary);
		ft_free_tab(args);
	}
	return (0);
}