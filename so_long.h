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
    void    *img11;
    void    *img12;
    int     x, y,  i,e,fd;
    char    *str;
    char    *str1;
    char    **str2;
	char	**tab;
	char	**tab1;
    char    *file;
    int     count1;
    int     count2;
    int     idx;
    int     line;
    int     a;
    int     b;
    int     eny;
    int pos1;
    int pos2;
}	t_long;

int f, p;
int m, n;
int xeny, yeny;
int a;
int x, y;
int xani, yani;
//int to, ti, ta, te;


void    check_size(char *file);
void	sec_check(char *file);
void    ft_window(char *file);
int	    ft_number_line(char *file);
int		ft_size_height(char *file);
int		ft_size_width(char *file);
char   **key_event(char *file, t_long *index);
void    ft_complete_map(char *file, t_long *index);
int		find_position_index(char **tab);
int		find_position_line(char **tab);
void	ft_wall(char **tab, t_long *index);
void	click_down(t_long *index);
void	click_right(t_long *index);
void	click_up(t_long *index);
void	click_left(t_long *index);
int     ft_exit(char **tab);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_position_index_k(char **tab);
int		find_position_line_K(char **tab);
char   **key_event_enemy(char *file, t_long *index);
//void	utils_move_down(t_long *index);

#endif