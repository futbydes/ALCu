/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:27:15 by vludan            #+#    #+#             */
/*   Updated: 2018/10/19 17:30:30 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# define BUFF_SIZE 1000

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct      s_lst
 {
 	char            *buff;
 	int             ds;
 	struct s_lst    *next;
 }					t_lst;

int					get_next_line(const int fd, char **line);
int					*get_board(void);
int					get_board_linecheck(char *line);
int					*get_board_realloc(char *line, int *x);
void				alum_alg(int *brd);
void				board_display(int *brd);
int					matches_p_task(int *board);
int					matches_take(int matches, int *board);
void				matches_c_task(int *board, int res);







#endif
