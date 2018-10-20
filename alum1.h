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
char				**get_board(void);
int					err_board(char **board);
char				**board_realloc(char *line, char **board);
void				printbord(char **board);
void				board_free(char **board);
int					matches_p_task(char **board);
int					matches_take(int matches, char **board);
int					check_board(char **board, int pl);

void				alum_alg(char **board);


#endif
