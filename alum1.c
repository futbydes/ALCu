/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:29:43 by vludan            #+#    #+#             */
/*   Updated: 2018/10/19 17:37:45 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			main(void)
{
	int		*x;

	x = get_board();
	if (x == 0)
	{
		ft_printf("ERROR\n");
		return (2);
	}
	alum_alg(x);
	free(x);
	return (0);
}

int			*get_board(void)
{
	char	*line;
	int		*x;

	line = 0;
	x = 0;
	while (get_next_line(0, &line) > 0 && ft_strlen(line))
	{
		if (!get_board_linecheck(line))
		{
			free(x);
			free(line);
			return (0);
		}
		x = get_board_realloc(line, x);
		free(line);
	}
	free(line);
	return (x);
}

int			get_board_linecheck(char *line)
{
	int		x;
	int		z;

	x = 0;
	z = ft_atoi(line);
	while (line[x] != '\0')
	{
		if (!ft_isdigit(line[x]))
			return (0);
		x++;
	}
	if (z > 10000 || z < 1)
		return (0);
	return (1);
}

int			*get_board_realloc(char *line, int *x)
{
	int		z;
	int		y;
	int		*tmp;

	z = 0;
	y = 0;
	while (x && x[z])
		z++;
	tmp = ft_memalloc(8 * (z + 2));
	while (y != z)
	{
		tmp[y] = x[y];
		y++;
	}
	free(x);
	tmp[y] = ft_atoi(line);
	tmp[y + 1] = 0;
	return (tmp);
}

void		alum_alg(int *brd)
{
	while (brd[0] != 0)
	{
		board_display(brd);
		matches_p_task(brd);
		if (brd[0] == 0)
		{
			ft_printf(RED "YOU LOOSE\n" RESET);
			return ;
		}
		board_display(brd);
		ft_printf(DARKGREY "BOT TURN\n" RESET);
		matches_c_task(brd);
	}
	brd[0] == 0 ? ft_printf(GREEN "YOU WIN\n" RESET) : 0;
}
