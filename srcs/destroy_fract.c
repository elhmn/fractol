#include "fractol.h"
#include "check_errors.h"

void	destroy_type(t_fractol *fract)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = fract->type;
	while (++i < TYPE_NBR)
		free(tmp[i]);
	free(fract->type);
}

void	destroy_fract(t_fractol *fract)
{
	if (!fract)
		check_errors(NUL, "destroy_fract.c", "fract");
	destroy_type(fract);
	mlx_destroy_window(fract->mlx, fract->win);
	free(fract->fun_fract);
}
