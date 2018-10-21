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
