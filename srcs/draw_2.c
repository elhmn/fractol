/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:25:07 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 10:26:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

void			put_axis(t_fractol *fract, t_uint color)
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
