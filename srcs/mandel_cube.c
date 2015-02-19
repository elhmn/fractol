/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 12:33:46 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 13:07:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int get_type(t_fractol *fract, int index)
{
	int		a;
	int		i;

	i = 0;
	a = fract->iter / COL_NBR;
	if (index == -1)
		return (0);
	while (++i < COL_NBR)
		if (index < a * i)
			return (i);
	return (-1);
}

static t_color	*get_color(t_fractol *fract, int index)
{
	int		i;
	int		a;

	i = get_type(fract, index);
	a = fract->iter / COL_NBR;
	a = a;
	if (!i)
		return ((fract->color = init_color(NULL, 0)));
	fract->color = init_color(NULL, fract->col_tab[i]);
	low_light(fract->color, (a * i - index), -1);
	return (fract->color);
}

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
		tmp = re * re * re - 3. * re * im * im + x;
		im = 3 * im * re * re - im * im * im + y;
		re = tmp;
		if (re * re + im * im > 4.)
			break;
	}
	if (i < fract->iter)
		return (i);
	return (-1);
}

void		mandel_cube(t_fractol *fract)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	tmp;

	i = -1;
	if (!fract->move && fract->zoomed)
	{
		fract->c_x -= ((double)(fract->w - fract->m_x) / fract->step);
		fract->c_y += ((double)(fract->h - fract->m_y) / fract->step);
		fract->zoomed = 0;
	}
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
