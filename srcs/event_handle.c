#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

int		key_release(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	fract = fract;
	if (key == ESCAPE)
	{
		destroy_fract(fract);
		exit(0);
	}
//	print_type("key", &key, INT); /****/
	return (0);
}

void	set_frame(t_fractol *fract)
{
	int		*line;
	int		*endian;
	int		*bpp;

	line = &(fract->lay->line);
	endian = &(fract->lay->endian);
	bpp = &(fract->lay->bpp);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGH);
	if (!fract->img)
		check_errors(MALLOC, "event_handle.c", "fract->img");
	fract->img_add = mlx_get_data_addr(fract->img, bpp, line, endian);
	if (!fract->img_add)
		check_errors(MALLOC, "event_handle.c", "fract->img_add");
	fract->fractol(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	ft_putendl("after put to window");
	mlx_destroy_image(fract->mlx, fract->img);
}

int		loop_hook(void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (fract->refresh)
	{
		set_frame(fract);
		fract->refresh = 0;
	}
	return (0);
}
