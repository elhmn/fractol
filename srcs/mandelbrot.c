#include "fractol.h"
#include "debug.h"
#include <stdio.h>

/*
Trace la fractale de Mandelbrot
void mandelbrot(SDL_Surface* ecran, long zoom, long iteration_max, double x_zoom, double y_zoom, double h) {
	double c_x, c_y , a, b, tmp;
	int i, x, y;

	double abs_min = x_zoom - h;
	double abs_max = x_zoom + h;
	double ord_min = y_zoom - h;
	double ord_max = y_zoom + h;

	for(x = 0; x < LARGEUR; x++) {
		for(y = 0; y < HAUTEUR; y++) {
			 Fractale de Mandelbrot : un peu de mathématique...
			   Zn+1 = Zn² + (x + iy)
			   Zo = 0
			   On colorie en noir si le module de Zn+1 ne tend pas vers +oo

			   On convertit la suite complexe en suite réelle :
Re: a = a² - b² + x
Im: b = 2ab + y
Ao = Bo = 0 

			a = 0;
			b = 0;
			i = 0;

			c_x = (double)x / zoom + abs_min;
			c_y = (double)y / zoom + ord_min;


			while((a*a + b*b) < 4.0 && i < iteration_max) {
				tmp = a;
				a = a*a - b*b + c_x;
				b = 2*tmp*b + c_y;
				i++;
			}


			 Coloration de la fractale 

			if(i == iteration_max) colorerPixel(ecran, x, y, 255, 255, 255);
			else {
				if(i * 100 / iteration_max < 50) colorerPixel(ecran, x, y, i*255/(iteration_max*0.75), 0, i*255/(iteration_max*0.75));
				else colorerPixel(ecran, x, y, 255, i*255/iteration_max, 0); 
			}

		}
	}
}
*/

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
		tmp = re * re - im * im + x;
		im = 2 * im * re + y;
		re = tmp;
		if (re * re + im * im > 4.)
			break;
	}
	if (i < fract->iter) // suite divergente
		return (i); //return la vitesse de divergence
	return (-1);
}

void		mandelbrot(t_fractol *fract)
{
	int		i;
	int		j;
	double	a;
	double	b;
	double	tmp;
	double	m_x;
	double	m_y;

	i = -1;
	ft_putendl("je suis Mandelbrot");/************/

/*
** determiner les coord du pt M dans C
*/

	printf(" fract->c_x = [%.40lf]\n", (double)fract->c_x);/********/
	printf(" fract->c_y =  [%.40lf]\n", (double)fract->c_y);/*********/
	printf("MOusE_KEY BEFORE\n");
	printf(" fract->m_x = [%.40lf]\n", (double)fract->m_x);/********/
	printf(" fract->m_y =  [%.40lf]\n", (double)fract->m_y);/*********/
	m_x = (double)(1. / fract->k) * (fract->m_x - fract->c_x);
	m_y = (double)(1. / fract->k) * (double)(fract->c_y - fract->m_y);
	printf("MOusE_KEY AFTER\n");
	printf(" fract->m_x = [%.40lf]\n", (double)m_x);/********/
	printf(" fract->m_y =  [%.40lf]\n", (double)m_y);/*********/

	b = (double)1 / (double)fract->k; /****/
	printf("k = [%lf]\n", fract->k);/*******/
	printf("1 / k = [%lf]\n", b);/*******/

	a = m_y + fract->h * (1. / fract->k);
	tmp = m_x - fract->w * (1. / fract->k);
	while (++i < HEIGH)
	{
		j = -1;
		if (!i)
		{
			printf("BEFORE\n"); /******/
			printf("fract->a = [%.40lf]\n", (double)a);/********/
		}
		b = tmp;
		while (++j < WIDTH)
		{
			if (!j && !i)
			{
				printf("BEFORE\n"); /******/
				printf("fract->b =  [%.40lf]\n", b);/*********/
			}
			fract->im = 0;
			fract->re = 0;
			get_color(fract, is_mandel(fract, b, a));
			pixel_put_img(fract, j, i, fract->color);
			b += 1. / fract->k;
		}
		a -= 1. / fract->k;
	}
	ft_putendl("je sors de Mandelbrot");
}
