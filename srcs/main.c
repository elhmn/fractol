#include "fractol.h"
#include "debug.h"
int					main(int ac, char **av)
{
	t_fractol		fract;

	if (ac > 1)
	{
		init_fract(&fract, av[1]);
		fract.fractol(&fract);
		init_env(&fract);
		mlx_key_hook(fract.win, key_release, &fract);
//		mlx_expose_hook();
		mlx_loop(fract.mlx);
		destroy_fract(&fract);
	}
	else
		ft_putendl("hey bud give me a fractal name");
	return (0);
}
