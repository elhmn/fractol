/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:44:01 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 13:15:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

void	string_put(t_fractol *fract, int x, int y, char *str)
{
	t_uint		color;

	if (fract->iter > 200)
		color = 0;
	else
		color = 0xFFFFFF;
	mlx_string_put(fract->mlx, fract->win, x, y, color, str);
}

void	print_legend(t_fractol *fract)
{
	string_put(fract, WIDTH - 250, HEIGH - 220, "Keys :: :D");
	string_put(fract, WIDTH - 250, HEIGH - 200, "1- ENTER to print axis.");
	string_put(fract, WIDTH - 250, HEIGH - 180, "2- SPACE to change JULIA type.");
	string_put(fract, WIDTH - 250, HEIGH - 160, "3- P to pause/resume JULIA variable.");
	string_put(fract, WIDTH - 250, HEIGH - 140, "4- DIRECTIONAL key to explore.");
	string_put(fract, WIDTH - 250, HEIGH - 120, "5- SCROLL in/out to zoom.");
	string_put(fract, WIDTH - 250, HEIGH - 100, "6- 1 / 2 / 3 / 4 / 5 / 6 to change color.");
	string_put(fract, WIDTH - 250, HEIGH - 80, "7- Click LEFT to center to axis position.");
	string_put(fract, WIDTH - 250, HEIGH - 60, "8- + / - to increase/decrease iteration.");
	string_put(fract, WIDTH - 250, HEIGH - 40, "9- H show/hide the legend.");
	string_put(fract, WIDTH - 250, HEIGH - 20, "10- ESCAPE to quit.");
}

int		key_release(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (key == K_ESCAPE)
	{
		destroy_fract(fract);
		exit(0);
	}
	if (key == K_LEFT)
		fract->vel_l = 0;
	if (key == K_RIGHT)
		fract->vel_r = 0;
	if (key == K_UP)
		fract->vel_up = 0;
	if (key == K_DOWN)
		fract->vel_dwn = 0;
	if (key == K_SPACE)
	{
		if (fract->jul == 1)
		{
			fract->re_c = -0.772691322542185;
			fract->im_c = 0.124281466072787;
			fract->jul = 0;
		}
		else
			fract->jul = 1;
	}
	if (key == K_ENTER)
	{
		if (!fract->axe)
			fract->axe = 1;
		else
			fract->axe = 0;
	}
	if (key == K_1)
	{
		fract->color_type = 0;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_2)
	{
		fract->color_type = 1;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_3)
	{
		fract->color_type = 2;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_4)
	{
		fract->color_type = 3;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_5)
	{
		fract->color_type = 4;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_6)
	{
		fract->color_type = 5;
		init_col_tab(fract, fract->color_type); //changer le code couleur
	}
	if (key == K_P)
	{
		if (!fract->jul_p)
			fract->jul_p = 1;
		else
			fract->jul_p = 0;
	}
	if (key == K_H)
	{
		if (!fract->help)
			fract->help = 1;
		else
			fract->help = 0;
	}
	if (key == K_PLUS)
	{
		if (fract->iter <= 5000.)
			fract->iter += 100;
	}
	if (key == K_MOINS)
	{
		if (fract->iter >= 100.)
			fract->iter -= 100;
	}
	fract->move = 0;
	fract->refresh = 1;
	return (0);
}

int		keypress_hook(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (fract->step > 0.)
		fract->move = (double)MOVE / fract->step;
	else
		fract->move = 0.;
	if (key == K_LEFT)
		fract->vel_l = fract->move;
	if (key == K_RIGHT)
		fract->vel_r = -fract->move;
	if (key == K_UP)
		fract->vel_up = fract->move;
	if (key == K_DOWN)
		fract->vel_dwn = -fract->move;
	fract->refresh = 1;
	return (0);
}

void	set_frame(t_fractol *fract)
{
	int		*line;
	int		*endian;
	int		*bpp;

	line = &(fract->lay->line);
	endian = &(fract->lay->endian);
	bpp = &(fract->lay->bpp);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGH);
	if (!fract->img)
		check_errors(MALLOC, "event_handle.c", "fract->img");
	fract->img_add = mlx_get_data_addr(fract->img, bpp, line, endian);
	if (!fract->img_add)
		check_errors(MALLOC, "event_handle.c", "fract->img_add");
	fract->fractol(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	mlx_destroy_image(fract->mlx, fract->img);
}

void	move_center(t_fractol *fract)
{
	fract->c_x += fract->vel_l;
	fract->c_x += fract->vel_r;
	fract->c_y += fract->vel_dwn;
	fract->c_y += fract->vel_up;
}

int		loop_hook(void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (fract->refresh)
	{
		set_frame(fract);
		move_center(fract);
		fract->refresh = 0;
		if (fract->axe)
			put_axis(fract, 0xFF0000); /********** OPTIONELLE ********/
		if (fract->help)
			print_legend(fract);
	}
	return (0);
}
