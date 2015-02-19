/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:44:05 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 13:08:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

int		motion_notify(int x, int y, void *param)
{
	t_fractol	*fract;

	fract = (void*)param;
	fract = fract;
//	printf("x = [%d] && ", x); /***********/
//	printf("y = [%d]\n", y); /***********/
	fract->refresh = 1;
	fract->axem_x = x;
	fract->axem_y = y;
	if (fract->jul_p)
	{
		
		if (fract->jul == 1)
		{
			fract->re_c = ((double)(fract->w - fract->axem_x) / fract->step);
			fract->im_c = ((double)(fract->h - fract->axem_y) / fract->step);
		}
		else
		{
			if (x < fract->w)
			{
				fract->re_c += (double)INC_RE;
				fract->im_c += (double)INC_IM;
			}
			else
			{
				fract->re_c -= (double)INC_RE;
				fract->im_c -= (double)INC_IM;
			}
		}
	}
	return (0);
}

void	put_axis(t_fractol *fract, t_uint color)
{
	int		i;

	if (fract)
	{
		i = -1;
		while (++i < HEIGH)
			mlx_pixel_put(fract->mlx, fract->win, fract->axem_x, i, color);
		i = -1;
		while (++i < WIDTH)
			mlx_pixel_put(fract->mlx, fract->win, i, fract->axem_y, color);
	}
}

int		expose_hook(void *param)
{
	t_fractol *fract;

	fract = (t_fractol*)param;
	fract->refresh = 1;
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (!fract)
		check_errors(NUL, "event_handle_2.c", "fract");
	fract->m_x = x;
	fract->m_y = y;
	fract->zoomed = 1;
	if (button == MOUSE_MOTION_UP)
	{
		fract->step += STEP_DEF;
		if (fract->step - fract->step_tmp >= fract->step_aug)
		{
			fract->iter += ITER_AUG;
			fract->step_tmp = fract->step;
			fract->step_aug += (double)STEP_AUGUP;
		}
	}
	else if (button == MOUSE_MOTION_DOWN)
	{
		if (fract->step > STEP_DEF)
			fract->step -= STEP_DEF;
		if (fract->step_tmp - fract->step >= fract->step_aug)
		{
			if (fract->iter >= ITER_AUG)
			{
				fract->iter -= ITER_AUG;
				fract->step_tmp = fract->step;
				if (fract->step_aug > STEP_AUG + STEP_AUGUP)
				fract->step_aug -= (double)STEP_AUGUP;
			}
		}
	}
	fract->refresh = 1;
	return (0);
}
