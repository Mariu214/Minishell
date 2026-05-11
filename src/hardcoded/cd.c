/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaimo <malaimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:09:17 by malaimo           #+#    #+#             */
/*   Updated: 2026/05/11 20:14:07 by malaimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd(t_data *data, char *str)
{
	char	*temp;
	char	*old_temp;
	int		return_value;

	if (chdir(str) == -1)
		return (ft_printf_fd(2, "minishell: cd: %s: %s\n", str,
				strerror(errno)), 1);
	temp = getcwd(data->current_dir, 4096);
	if (!temp)
		return (ft_printf_fd(2, "Minishell: couldn't access directory", 1));
	old_temp = ft_getenv("PWD", data->env);
	temp = ft_strjoin("PWD=", temp);
	if (!temp)
		return (1);
	old_temp = ft_strjoin("OLDPWD=", old_temp);
	if (!old_temp)
		return (free(temp), 1);
	return_value = export(data, temp);
	if (return_value)
		return (free(temp), free(old_temp), return_value);
	free(temp);
	return_value = export(data, old_temp);
	free(old_temp);
	return (return_value);
}

int	cd_minus(t_data *data, int return_value)
{
	char	*temp;
	char	*old_temp;

	temp = ft_getenv("OLDPWD", data->env);
	if (!temp)
		return (0);
	if (chdir(temp) == -1)
		return (ft_printf_fd(2, "minishell: cd: %s: %s\n", temp,
				strerror(errno)), 1);
	temp = getcwd(data->current_dir, 4096);
	if (!temp)
		return (ft_printf_fd(2, "Minishell: couldn't access directory", 1));
	old_temp = ft_getenv("PWD", data->env);
	temp = ft_strjoin("PWD=", temp);
	if (!temp)
		return (1);
	old_temp = ft_strjoin("OLDPWD=", old_temp);
	if (!old_temp)
		return (free(temp), 1);
	return_value = export(data, temp);
	if (return_value)
		return (free(temp), free(old_temp), return_value);
	return_value = export(data, old_temp);
	return (free(temp), free(old_temp), return_value);
}

int	init_cd(t_data *data, t_lexst **list)
{
	char	*temp;
	int		return_value;

	*list = (*list)->next;
	if (!(*list) || (*list)->type != BUILT_IN
		|| ft_strcmp((*list)->content, "~") == 0)
	{
		temp = ft_getenv("HOME", data->env);
		if (!temp)
			return (ft_printf_fd(2, "bash: cd: HOME not set\n"), 1);
		return_value = cd(data, temp);
		return (return_value);
	}
	if ((*list)->next && (*list)->next->type == BUILT_IN)
	{
		while (*list && (*list)->type == BUILT_IN)
			*list = (*list)->next;
		return (ft_printf_fd(2, "minishell: cd: too many arguments\n"), 1);
	}
	if (ft_strcmp((*list)->content, "-") == 0)
		return (cd_minus(data, 0));
	return (cd(data, (*list)->content));
}
