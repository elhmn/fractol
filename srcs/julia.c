#include "fractol.h"
#include "debug.h"
#include <stdio.h>

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

static int	is_julia(t_fractol *fract, double x, double y)
{
	int			i;
	double		tmp;
	double		im;
	double		re;

	im = y;
	re = x;
	i = -1;
	while (++i < fract->iter)
	{
		tmp = re * re - im * im + fract->re_c;
		im = 2 * im * re + fract->im_c;
		re = tmp;
		if (re * re + im * im > 4.)
			break;
	}
	if (i < fract->iter)
		return (i);
	return (-1);
}

void		julia(t_fractol *fract)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	tmp;

	i = -1;
	ft_putendl("je suis Julia");
	if (!fract->move)
	{
		fract->c_x -= ((double)(fract->w - fract->m_x) / fract->step);
		fract->c_y += ((double)(fract->h - fract->m_y) / fract->step);
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
			get_color(fract, is_julia(fract, b, a));
			pixel_put_img(fract, j, i, fract->color);
			b += 1. / fract->step;
		}
		a -= 1. / fract->step;
	}
}
