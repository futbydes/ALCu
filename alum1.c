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
	while (get_next_line(0, &line) && ft_strlen(line))
	{
		if (!get_board_linecheck(line))
			return (0);
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
	//	board_display(brd);
	//	matches_c_task(brd);
	}
	brd[0] == 0 ? ft_printf(GREEN "YOU WIN\n" RESET) : 0;
}

void		board_display(int *brd)
{
	int		c;
	int		x;

	c = 0;
	x = 0;
	while (brd && brd[x])
	{
		c = brd[x];
		while (c-- != 0)
			ft_printf(CYAN "|" RESET);
		ft_printf("\n");
		x++;
	}
}

int			matches_p_task(int *board)
{
	char	*line;
	int		res;

	res = 0;
	while (res == 0)
	{
		ft_printf(DARKGREY "YOUR TURN,PLEASE,TAKE FROM 1 "
			"TO 3 MATCHES FROM THE LAST LINE\n" RESET);
		get_next_line(0, &line);
		if (line && (line[0] == '1' || line[0] == '2' ||
			line[0] == '3') && line[1] == 0)
			res = ft_atoi(line);
		if (res != 0 && !matches_take(res, board))
			res = 0;
		free(line);
	}
	return (res);
}

int			matches_take(int matches, int *board)
{
	int		x;

	x = 0;
	while (board[x] != 0)
		x++;
	if (x && board[x - 1] < matches)
		return (0);
	if (board[x - 1] == matches)
		board[x - 1] = 0;
	else
		board[x - 1] -= matches;
	return (1);
}
