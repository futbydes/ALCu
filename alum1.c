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


int		main(void)
{
	char	**brd;

	brd = get_board();
	if (brd == 0)
	{
		ft_printf("ERROR\n");
		return (2);
	}
	alum_alg(brd);
	board_free(brd);
	return (0);
}

void		alum_alg(char **board)
{
	int		check;

	check = 0;
	while (!check)
	{
		printbord(board);
		matches_p_task(board);
		check = check_board(board, 1);
		//printbord(board);
		//matches_c_task(board);
		//check = check_board(board, 2);
	}
}

int			matches_p_task(char **board)
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

int			check_board(char **board, int pl)
{
	int		c;
	int		y;

	c = 0;
	y = -1;
	while (board[0] && board[0][++y])
		board[0][y] == '|' ? c++ : 0;
	if (c == 0)
	{
		pl == 1 ? ft_printf(RED "YOU LOOSE\n" RESET) :
		ft_printf(GREEN "YOU WIN\n" RESET);
		return (1);
	}
	else
		return (0);
}

int			matches_take(int matches, char **board)
{
	int		x;
	int		y;
	int		c;

	x = 0;
	y = -1;
	c = 0;
	while (board[x] != 0)
		x++;
	x != 0 ? x-- : 0;
	while (board[x][++y] == '|' || board[x][y] == ' ')
		board[x][y] == '|' ? c++ : 0;
	if (c < matches)
		return (0);
	else if (c == matches)
	{
		free(board[x]);
		board[x] = 0;
	}
	else
		while (matches)
		{
			board[x][y] == '|' ? matches-- : 0;
			board[x][y] = 0;
			y--;
		}
	return (1);
}


char		**get_board(void)
{
	char	**board;
	char	*line;

	board = 0;
	line = 0;
	while (get_next_line(0, &line) > 0 && ft_strlen(line))
	{
		board = board_realloc(line, board);
		free(line);	
	}
	free(line);
	if (!err_board(board))
	{
		board_free(board);
		return (0);
	}
	else
		return (board);
}

int			err_board(char **board)
{
	int		x;
	int		y;
	int		c;

	x = 0;
	y = -1;
	if (board == 0)
		return (0);
	else
	{
		while (board[x])
		{
			c = 0;
			while ((board[x][++y] == '|' || 
				board[x][y] == ' ') && board[x][y])
				board[x][y] == '|' ? c++ : 0;
			if (board[x][y] || c < 1 || c > 10000)
				return (0);
			y = -1;
			x++;
		}
	}
	return (1);
}

void		board_free(char **board)
{
	int		x;

	x = 0;
	while (board && board[x])
	{
		free(board[x]);
		x++;
	}
	free(board);
}

char		**board_realloc(char *line, char **board)
{
	int		c;
	int		x;
	char	**tmp;

	c = 0;
	x = 0;
	while (board && board[c] != 0)
		c++;
	tmp = ft_memalloc(8 * (c + 2));
	while (x != c)
	{
		tmp[x] = ft_memalloc(ft_strlen(board[x]) + 1);
		ft_strcpy(tmp[x], board[x]);
		x++;
	}
	tmp[x] = ft_memalloc(ft_strlen(line) + 1);
	ft_strcpy(tmp[x], line);
	tmp[x + 1] = 0;
	return (tmp);
}

void		printbord(char **board)
{
	int		x;

	x = 0;
	while (board[x])
	{
		ft_printf("%s\n", board[x]);
		x++;
	}
}
