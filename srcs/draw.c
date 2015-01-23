/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:13:51 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 19:37:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

void		pixel_put_img(t_fractol *fract, int x, int y, t_color *col)
{
	int		size;
	char	*image;
	t_lay	lay;
	int		b;

	lay = *(fract->lay);
	image = fract->img_add;
	if (col && image)
	{
		size = lay.line;
		b = lay.bpp / 8;
		x *= b;
		if (size > 0 && (y < HEIGH && y >= 0)
				&& (x >= 0 && x + lay.bpp / 8 < lay.line))
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}

static void		aux_low_light(t_color *color, t_uint inc)
{
	if ((int)color->r - (int)inc > 0)
		color->r -= inc;
	else
		color->r = 0;
	if ((int)color->g - (int)inc > 0)
		color->g -= inc;
	else
		color->g = 0;
	if (((int)color->b - (int)inc) > 0)
		color->b -= inc;
	else
		color->b = 0;
}

t_color				*low_light(t_color *color, t_uint inc, t_uint sign)
{
	if (color)
	{
		if (sign > 0)
		{
			if ((int)color->r + (int)inc < 256)
				color->r += inc;
			else
				color->r = 255;
			if ((int)color->g + (int)inc < 256)
				color->g += inc;
			else
				color->g = 255;
			if ((int)color->b + (int)inc < 256)
				color->b += inc;
			else
				color->b = 255;
		}
		else
			aux_low_light(color, inc);
		color->color = rgb_to_color(color->r, color->g, color->b);
	}
	return (color);
}
