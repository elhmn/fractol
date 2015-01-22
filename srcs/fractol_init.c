#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

t_fun_fract	choose_type(t_fractol *fract, char *name)
{
	int		i;
	char	**type;
	
	i = -1;
	type = fract->type;
	while (++i < TYPE_NBR)
		if (!ft_strcmp(type[i], name))
			break;
	if (i == TYPE_NBR)
	{
		ft_putendl("Please choose between : julia, mandelbrot, kleinian");
		exit(0);
	}
	fract->fractol = fract->fun_fract[i];
	return (fract->fun_fract[i]);
}


void	init_type(t_fractol *fract)
{
	fract->type = (char**)malloc(sizeof(char*) * (TYPE_NBR + 1));
	if (!fract->type)
		check_errors(NUL, "fractol_init.c", "fract->type");
	fract->type[TYPE_NBR] = NULL;
	fract->type[0] = ft_strsub(MANDEL, 0, ft_strlen(MANDEL));
	fract->type[1] = ft_strsub(JUL, 0, ft_strlen(JUL));
	fract->type[2] = ft_strsub(KLEIN, 0, ft_strlen(KLEIN));
}

void	fun_fract(t_fractol *fract)
{
	fract->fun_fract = (t_fun_fract*)malloc(sizeof(t_fun_fract) * (TYPE_NBR + 1));
	if (!fract->fun_fract)
		check_errors(NUL, "fractol_init.c", "fract->fun_fract");
	(fract->fun_fract)[TYPE_NBR] = NULL;
	fract->fun_fract[0] = mandelbrot;
	fract->fun_fract[1] = julia;
	fract->fun_fract[2] = kleinian;
}


void	init_env(t_fractol *fract)
{
	if (!(fract->mlx = mlx_init()))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
	if (!(fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGH, TITLE)))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
}

void	init_fract(t_fractol *fract, char *name)
{
	if (!fract)
		check_errors(NUL, "fractol_init.c", "fract");
	init_type(fract);
	print_fract(fract); /****************/
	fun_fract(fract);
	choose_type(fract, name);
}
