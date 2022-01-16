/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:56:29 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/17 17:51:52 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd_syntax(char *cmd, int count, int *env_count)
{
	int	i;

	i = 0;
	if (cmd[i] >= 'A' && cmd[i] <= 'Z')
		i++;
	else
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '=')
			break ;
		else if ((cmd[i] >= 'A' && cmd[i] <= 'Z')
			|| (cmd[i] >= '0' && cmd[i] <= '9') || cmd[i] == '_')
			i++;
		else
			return (0);
	}
	if (ft_isprint(cmd[++i]))
	{
		if (count)
			*env_count += 1;
		return (1);
	}
	return (0);
}

char	**get_args(char **cmd_splitted_list, int env_count, int list_count)
{
	char	**cmd_arg_list;
	int		i;
	int		j;

	cmd_arg_list = malloc((list_count - env_count + 1) * sizeof(char *));
	if (!cmd_arg_list)
		return (NULL);
	i = -1;
	j = -1;
	while (cmd_splitted_list[++i])
	{
		if (!(check_cmd_syntax(cmd_splitted_list[i], 0, NULL)))
			cmd_arg_list[++j] = cmd_splitted_list[i];
	}
	cmd_arg_list[++j] = NULL;
	return (cmd_arg_list);
}

/*
char	**get_envs(char **cmd_splitted_list, int env_count)
{
	char	**cmd_env_list;
	int		i;
	int		j;

	cmd_env_list = malloc((env_count + 1) * sizeof(char *));
	if (!cmd_env_list)
		return (NULL);
	i = -1;
	j = -1;
	while (cmd_splitted_list[++i])
	{
		if (check_cmd_syntax(cmd_splitted_list[i], 0, NULL))
			cmd_env_list[++j] = cmd_splitted_list[i];
	}
	cmd_env_list[++j] = NULL;
	return (cmd_env_list);
}
*/

char	**cmd_split(char *cmd, int *env_count, int *list_count)
{
	char	**cmd_splitted_list;
	int		i;

	cmd_splitted_list = ft_split(cmd, ' ');
	i = -1;
	while (cmd_splitted_list[++i])
		check_cmd_syntax(cmd_splitted_list[i], 1, env_count);
	*list_count = i;
	return (cmd_splitted_list);
}
