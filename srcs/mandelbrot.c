#include "fractol.h"


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

void	mandelbrot(t_fractol *fract)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGH)
	{
		j = -1;
		while (j++)
		{

		}
	}
}
