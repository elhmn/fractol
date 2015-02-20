/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:43:52 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 10:09:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_mandel(t_fractol *fract, double x, double y)
{
	int			i;
	double		tmp;
	double		im;
	double		re;

	im = fract->im;
	re = fract->re;
	i = -1;
	while (++i < fract->iter)
	{
		tmp = re * re - im * im + x;
		im = 2 * im * re + y;
		re = tmp;
		if (re * re + im * im > 4.)
			break ;
	}
	if (i < fract->iter)
		return (i);
	return (-1);
}

void		mandelbrot(t_fractol *fract)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	tmp;

	i = -1;
	change_c(fract);
	a = fract->c_y + fract->h * (1. / fract->step);
	tmp = fract->c_x - fract->w * (1. / fract->step);
	while (++i < HEIGH)
	{
		j = -1;
		b = tmp;
		while (++j < WIDTH)
		{
			fract->im = 0;
			fract->re = 0;
			get_color(fract, is_mandel(fract, b, a));
			pixel_put_img(fract, j, i, fract->color);
			b += 1. / fract->step;
		}
		a -= 1. / fract->step;
	}
}
