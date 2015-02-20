/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 11:05:20 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 11:21:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

void		aux_key_01(t_fractol *fract, int key)
{
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
	else if (key == K_ENTER)
	{
		if (!fract->axe)
			fract->axe = 1;
		else
			fract->axe = 0;
	}
	else if (key == K_A)
		choose_type(fract, JUL);
	else if (key == K_S)
		choose_type(fract, MANDEL);
	else if (key == K_D)
		choose_type(fract, M_CUBE);
}

static void	aux_k_02(t_fractol *fract, int key)
{
	if (key == K_4)
	{
		fract->color_type = 3;
		init_col_tab(fract, fract->color_type);
	}
	else if (key == K_5)
	{
		fract->color_type = 4;
		init_col_tab(fract, fract->color_type);
	}
	else if (key == K_6)
	{
		fract->color_type = 5;
		init_col_tab(fract, fract->color_type);
	}
}

void		aux_key_02(t_fractol *fract, int key)
{
	if (key == K_1)
	{
		fract->color_type = 0;
		init_col_tab(fract, fract->color_type);
	}
	else if (key == K_2)
	{
		fract->color_type = 1;
		init_col_tab(fract, fract->color_type);
	}
	else if (key == K_3)
	{
		fract->color_type = 2;
		init_col_tab(fract, fract->color_type);
	}
	aux_k_02(fract, key);
}

void		aux_key_03(t_fractol *fract, int key)
{
	if (key == K_P)
	{
		if (!fract->jul_p)
			fract->jul_p = 1;
		else
			fract->jul_p = 0;
	}
	else if (key == K_H)
	{
		if (!fract->help)
			fract->help = 1;
		else
			fract->help = 0;
	}
	else if (key == K_PLUS)
	{
		if (fract->iter <= 5000.)
			fract->iter += 20;
	}
	else if (key == K_MOINS)
	{
		if (fract->iter >= 20.)
			fract->iter -= 20;
	}
}
