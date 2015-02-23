/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:44:01 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/22 13:17:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

int		key_release(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (key == K_ESCAPE)
	{
		destroy_fract(fract);
		exit(0);
	}
	else if (key == K_LEFT)
		fract->vel_l = 0;
	else if (key == K_RIGHT)
		fract->vel_r = 0;
	else if (key == K_UP)
		fract->vel_up = 0;
	else if (key == K_DOWN)
		fract->vel_dwn = 0;
	aux_key_01(fract, key);
	aux_key_02(fract, key);
	aux_key_03(fract, key);
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
	else if (key == K_RIGHT)
		fract->vel_r = -fract->move;
	else if (key == K_UP)
		fract->vel_up = fract->move;
	else if (key == K_DOWN)
		fract->vel_dwn = -fract->move;
	fract->refresh = 1;
	return (0);
}

void	set_frame(t_fractol *fract)
{
	fract->fractol(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
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
			put_axis(fract, 0xFF0000);
		if (fract->help)
			print_legend(fract);
	}
	return (0);
}
