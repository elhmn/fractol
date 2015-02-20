/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 20:47:14 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 12:12:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

void		init_var(int *t_iter)
{
	if (t_iter)
	{
		t_iter[0] = ITER_MANDEL;
		t_iter[1] = ITER_JUL;
		t_iter[2] = ITER_MANDEL2;
	}
}

static void	aux_init_fract(t_fractol *fract)
{
	fract->vel_l = 0;
	fract->vel_r = 0;
	fract->vel_up = 0;
	fract->vel_dwn = 0;
	fract->step = (double)STEP;
	fract->step_tmp = (double)STEP;
	fract->step_aug = (double)STEP_AUG;
	fract->move = 0;
	fract->zoomed = 0;
	fract->m_x = (double)WIDTH / (double)2;
	fract->m_y = (double)HEIGH / (double)2;
	fract->axem_x = fract->m_x;
	fract->axem_y = fract->m_y;
	fract->c_x = 0;
	fract->c_y = 0;
	fract->w = WIDTH / 2.;
	fract->h = HEIGH / 2.;
	fract->jul = 0;
	fract->jul_p = 1;
	fract->help = 1;
	fract->axe = 0;
	fract->re_c = -0.772691322542185;
	fract->im_c = 0.124281466072787;
	fract->a = (HEIGH / 2.) * (1. / (double)STEP);
	fract->b = (WIDTH / 2.) * -1 * (1. / (double)STEP);
}

void		init_env(t_fractol *fract)
{
	int		*line;
	int		*endian;
	int		*bpp;

	line = &(fract->lay->line);
	endian = &(fract->lay->endian);
	bpp = &(fract->lay->bpp);
	if (!(fract->mlx = mlx_init()))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
	if (!(fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGH, TITLE)))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGH);
	if (!fract->img)
		check_errors(MALLOC, "event_handle.c", "fract->img");
	fract->img_add = mlx_get_data_addr(fract->img, bpp, line, endian);
	if (!fract->img_add)
		check_errors(MALLOC, "event_handle.c", "fract->img_add");
}

void		init_fract(t_fractol *fract, char *name)
{
	if (!fract)
		check_errors(NUL, "fractol_init.c", "fract");
	init_type(fract);
	fun_fract(fract);
	choose_type(fract, name);
	fract->color = NULL;
	fract->refresh = 1;
	if (!(fract->lay = (t_lay*)malloc(sizeof(t_lay))))
		check_errors(MALLOC, "fractol_init.c", "fract->lay");
	init_col_type(fract);
	fract->color_type = COLOR_TYPE;
	fract->col_tab = NULL;
	init_col_tab(fract, fract->color_type);
	aux_init_fract(fract);
}
