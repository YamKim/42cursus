/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yekim <yekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 07:05:15 by yekim             #+#    #+#             */
/*   Updated: 2021/01/01 13:19:32 by yekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "mlx.h"
# include "./cub3d_bonus.h"
# include "./libft.h"
# include "./utils.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

/*
** ERROR_CODE
*/
# define ERR_GET_INFO 3
# define ERR_CHECK_FILE 4
# define ERR_PARSE_CONFIG 5
# define ERR_PLAY_MUSIC 6
# define ERR_RUN_PROGRAM 7
# define ERR_TEXTURE_CALL 1
# define ERR_RUN 1
# define ERR_FILE 1
# define ERR_READ 1
# define ERR_MALLOC -1
# define ERR_PARSE 1
# define ERR_PARSE_MAP 8
# define ERR_DRAW_IMG 1
# define ERR_SAVE_BMP 5
# define ERR_MESSAGE "ERROR ERROR ERROR\n"

/*
** FILE SETTING
*/
# define FILE_EXTENSION ".cub"
# define FILE_EXTENSION_LENGTH 4
# define FILE_DATA 4096
# define FILE_NAME_BMP "save.bmp"

/*
** KEBOARD INPUT
*/
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_J 31
# define MOVE_W 0
# define MOVE_A 1
# define MOVE_S 2
# define MOVE_D 3
# define MOVE_LEFT 4
# define MOVE_RIGHT 5
# define KEY_ESC 53

/*
** KEBOARD HOOK
*/
# define EVENT_KEY_PRESS   2
# define EVENT_KEY_RELEASE 3
# define EVENT_KEY_EXIT 17

/*
** CONFIGURATION
*/
# define CONFIG_R_WIDTH_MAX 1920
# define CONFIG_R_HEIGHT_MAX 1096
# define CONFIG_NUMBER 8
# define CONFIG_NO 0
# define CONFIG_SO 1
# define CONFIG_WE 2
# define CONFIG_EA 3
# define CONFIG_S 4
# define CONFIG_R 5
# define CONFIG_F 6
# define CONFIG_C 7

/*
** MAP VALUE
*/
# define MAP_ROAD '0'
# define MAP_ROAD_VAL 0
# define MAP_WALL '1'
# define MAP_WALL_VAL 1
# define MAP_SPRITE '2'
# define MAP_SPRITE_VAL 2
# define MAP_SPACE ' '
# define MAP_SPACE_VAL -1
# define MAP_BOARDER_VAL -2
# define MAP_EXCEPTION_VAL -3
# define MAP_UNUSED_VAL -4

/*
** PLAYER MOTION AND ORIENT / SPEED
*/
# define DEG2RAD 0.017453
# define RAD2DEG 57.29578
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define START_NORTH_ANGLE 0
# define START_SOUTH_ANGLE 180
# define START_WEST_ANGLE 90
# define START_EAST_ANGLE -90

/*
** player speed setting
** ROT_SPEED = 2.0 * DEG2RAD
*/
# define ROT_SPEED 0.034906
# define TRANS_SPEED 0.04

/*
** CONSTANT NUMBER
*/
# define EPSILON 0.00001

/*
** DDA ALGORITHM
*/
# define HIT_SIDE_X 0
# define HIT_SIDE_Y 1

/*
** SPRITE SCALE
*/
# define SCALE_HDIV_SPRITE 1.0
# define SCALE_WDIV_SPRITE 1.0
# define SCALE_MOVE_SPRITE 200

/*
** BMP SETTING
*/
# define BMP_HEADER_SIZE 54
# define BMP_PIXEL_SIZE 3
# define BMP_PIXEL_ALIGN 4

/*
** initialize disp and player
*/
void				init_disp_setting(t_disp *disp);

void				init_player_setting(
					t_disp *disp,
					t_player *player);

t_loop				set_loop_val(
					t_disp *dp,
					t_player *player);

/*
** run cub3d program
*/
int					run_program(
					t_disp *disp,
					t_player *player,
					int capture_flag);

int					run_raycasting(t_loop *lv);

/*
** run cub3d program
*/
int					exit_red(
					t_loop *lv,
					int flag);

int					finish_program(t_loop *lv);

/*
** parse configuration
*/
int					parse_config(
					t_disp *disp,
					char **line_buf,
					int *k);

/*
** parse map
*/
int					parse_map(
					t_disp *disp,
					char **map,
					int map_beg);

/*
** PLAYER MOTION
*/
void				move_forward(
					t_player *player,
					t_map map);

void				move_backward(
					t_player *player,
					t_map map);

void				move_left(
					t_player *player,
					t_map map);

void				move_right(
					t_player *player,
					t_map map);

void				turn_left(t_player *player);
void				turn_right(t_player *player);

/*
** VECTOR CALCULATION
*/
t_vecd				translate_vec(
					t_vecd pos,
					t_vecd dir,
					double trans);

t_vecd				rotate_vec(
					t_vecd dir,
					double theta);

/*
** calculate basic algorithm
*/
double				calc_dist(
					t_vecd p1,
					t_vecd p2);

double				calc_det(
					t_vecd v1,
					t_vecd v2);

/*
** DDA ALGORITHM CALCULATION
*/
double				dda_algorithm(
					t_player *player,
					t_hit *hp,
					t_map map);

/*
** DRAWING UNTEXTURED WALL
*/
void				draw_untex_wall(
					t_disp *disp,
					t_player *player,
					int x,
					const t_hit *hit_point);

/*
** DRAWING TEXTURED WALL
*/
int					draw_tex_wall(
					t_disp *disp,
					t_player *player,
					int x,
					t_hit *hit_point);

/*
** DRAWING TEXTURED BACKGROUND
*/
int					draw_background(
					t_disp *disp,
					t_player *player);

/*
** display drawing sprite shape
*/
int					draw_sprite(
					t_disp *disp,
					t_player *player,
					double *perp_buf);

void				sort_spr_pair(
					t_pair *spr_pair,
					int spr_cnt);

t_vecd				set_sprite_scale(
					t_draw *draw,
					t_vecd coef,
					int tex_nbr);

int					check_order(
					t_disp *disp,
					t_player *player,
					t_draw *draw,
					double *purp_buf);

void				animate_sprite(t_spr *spr);

/*
** load images from xpm files
*/
int					check_file(char *fname);

int					load_texture(
					t_tex *tex,
					char *file_name);

/*
** ft_split
*/
void				free_split_arr(char **tab);

/*
** keyboard hook from user
*/
int					key_press(
					int key,
					t_loop *lv);

int					key_release(
					int key,
					t_loop *lv);

void				key_update(t_loop *lv);

/*
** mouse hook from user
*/
int					mouse_press(
					int button,
					int x,
					int y,
					t_loop *lv);

int					mouse_release(
					int button,
					int x,
					int y,
					t_loop *lv);

int					mouse_move(
					int x,
					int y,
					t_loop *lv);

/*
** check validity
*/
int					is_number_arr(
					char **arr,
					int index_num,
					int type);

int					is_map_valid(t_map map);

int					is_secret(
					int map_data,
					t_hit *hit_point,
					int *hit_flag);

/*
** show data
*/
void				show_map_data(t_disp disp);
void				show_lst_data(t_lst *itr);

/*
** bonus setting
*/
/*
** door
*/
int					check_door_type(
					t_hit *hit_point,
					int map_data);
int					save_bmp_image(t_loop *lv);

#endif
