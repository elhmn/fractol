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

void		pixel_put_img(t_fdf *fdf, int x, int y, t_color *col)
{
	int		size;
	char	*image;
	t_lay	lay;
	int		b;

	lay = *(fdf->lay);
	image = fdf->img;
	if (col && image)
	{
		size = lay.line;
		b = lay.bpp / 8;
		x *= b;
		if (size > 0 && (y < fdf->heigh && y >= 0)
				&& (x >= 0 && x + lay.bpp / 8 < lay.line))
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}