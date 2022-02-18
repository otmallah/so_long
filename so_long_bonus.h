/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:53:39 by otmallah          #+#    #+#             */
/*   Updated: 2022/02/16 16:53:40 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "get/get_next_line.h"

typedef struct s_long {
	int		yu;
	int		po;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	void	*img9;
	void	*img10;
	void	*img13;
	void	*img14;
	void	*img15;
	void	*img16;
	void	*img17;
	void	*iimg7;
	void	*iimg2;
	void	*iimg8;
	void	*iimg9;
	void	*iimg10;
	char	**tab;
	char	**tab1;
	char	*file;
	int		e;
	int		i;
	int		fd;
	char	*str;
	void	*img11;
	void	*img12;
	int		cb1;
	int		cb2;
	int		xy;
	int		yy;
	int		idx;
	int		line;
	int		eny;
	int		a;
	int		b;
	int		num_mv;
	int		xi;
	int		yi;
	int		pok;
}		t_long;

void	sec_check_bonus(char *file, t_long *index);
void	check_size_bonus(char *file);
void	ft_window_bonus(char *file);
char	**key_event_bonus(char *file, t_long *index);
char	**key_event_enemy_bonus(char *file, t_long *index);
int		ft_number_line_bonus(char *file);
void	ft_wall_bonus(char **tab, t_long *index);
int		find_position_line_bonus(char **tab);
int		find_position_index_bonus(char **tab);
void	click_up_bonus(t_long *index);
void	click_right_bonus(t_long *index);
void	click_left_bonus(t_long *index);
void	click_down_bonus(t_long *index);
int		ft_size_height(char *file);
int		ft_size_width(char *file);
int		ft_exit(char **tab);
char	*ft_itoa(int n);
int		find_position_index_k(char **tab);
int		find_position_line_k(char	**tab);
char	**key_event_enemy(char *file, t_long *index);
void	ft_animation_player(t_long *index);
void	ft_animation_coin(t_long *index, int i, int j);
void	ft_enemy_animation(t_long *index);
int		number_coin(t_long *index);
void	animation_enemy(t_long *index);
void	complete_map_bonus(t_long *index);
void	images_bonus(t_long *i);
int		ft_exit(char **tab);
int		key_hook(int keycode, t_long *index);
int		ft_close(void);
int		number_coin(t_long *index);
void	sen_main_bon(t_long *id, char *file);
int		loop_hook(t_long *index);
int		check_event(t_long *index);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t n, size_t c);

#endif