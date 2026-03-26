#include "../../include/minishell.h"

int	is_redirection(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

void	init_null(t_data *data, int size)
{
	int	i;

	i = 0;
	data->line = ft_calloc_gc(sizeof(t_cmd), (size + 1), &data->gc);
	while (i <= size)
	{
		data->line[i].is_cmd = 0;
		data->line[i].is_file = 0;
		data->line[i].is_pipe = 0;
		data->line[i].is_redirection = 0;
		i++;
	}
}
