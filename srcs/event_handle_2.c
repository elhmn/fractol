/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:44:05 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/06 22:08:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

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
	if (button == MOUSE_MOTION_DOWN)
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
