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

void		matches_c_task(int *board)
{
	int		x;
	int		*indicators;

	x = 0;
	while (board[x] != 0)
		x++;
	indicators = ft_memalloc(8 * x);
	indicators[0] = 0;
	matches_indicator(board, x, indicators);
	x--;
	if (indicators[x] == 0)
		board_type(x, board, 0);
	else
		board_type(x, board, 1);
	free(indicators);
}

void		matches_indicator(int *board, int x, int *indicators)
{
	int		mod1;
	int		y;

	y = 1;
	while (y < x)
	{
		mod1 = board[y - 1] % 4;
		if (indicators[y - 1] == 0 && mod1 == 1)
			indicators[y] = 1;
		else if (indicators[y - 1] == 0 && mod1 != 1)
			indicators[y] = 0;
		else if (indicators[y - 1] == 1 && mod1 == 0)
			indicators[y] = 1;
		else if (indicators[y - 1] == 1 && mod1 != 0)
			indicators[y] = 0;
		y++;
	}
}

void		board_type(int x, int *board, int type)
{
	int		mod;

	mod = board[x] % 4;
	if (type == 0)
	{
		if (mod == 0)
			matches_take(3, board);
		else if (mod == 1 || mod == 2)
			matches_take(1, board);
		else if (mod == 3)
			matches_take(2, board);
	}
	else
	{
		if (mod == 1 || mod == 0)
			matches_take(1, board);
		if (mod == 2)
			matches_take(2, board);
		if (mod == 3)
			matches_take(3, board);
	}
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
		line = 0;
		ft_printf(DARKGREY "YOUR TURN,PLEASE,TAKE FROM 1 "
			"TO 3 MATCHES FROM THE LAST LINE\n" RESET);
		while (!line)
		{
			get_next_line(1, &line);
			if (line && (line[0] == '1' || line[0] == '2' ||
				line[0] == '3') && line[1] == 0)
				res = ft_atoi(line);
			free(line);
		}
		if (res != 0 && !matches_take(res, board))
			res = 0;
	}
	return (res);
}
