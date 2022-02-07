/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:29:26 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/06 19:29:27 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H
#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "get/get_next_line.h"

typedef struct	s_long {
	void	*mlx;
	void	*win;
    void    *path1;
    void    *path2;
    void    *path3;
    void    *path4;
    void    *path5;
    void    *path6;
    void    *path7;
    void    *path8;
    void    *path9;
    void    *path10;
    void    *img1;
    void    *img2;
    void    *img3;
    void    *img4;
    void    *img5;
    void    *img6;
    void    *img7;
    void    *img8;
    void    *img9;
    void    *img10;
    int     x, y,  i,a,fd;
    char    *str;
    char    **str2;
	char	**tab;
}	t_long;

int count1;
int count2;
int idx;
int line;
int a;
int b;
int f, p;
int m, n;

int    check_size(void);
void	sec_check(void);
void    ft_window(void);
int	    ft_number_line(void);
int		ft_size_height(void);
int		ft_size_width(void);
char   **key_event(void);
void    ft_complete_map(void);
int		find_position_index(char **tab);
int		find_position_line(char **tab);
void	ft_wall(char **tab);

#endif