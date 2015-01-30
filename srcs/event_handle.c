#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

int		key_release(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	fract = fract;
	if (key == K_ESCAPE)
	{
		destroy_fract(fract);
		exit(0);
	}
	if (key == K_LEFT)
		fract->vel_l = 0;
	if (key == K_RIGHT)
		fract->vel_r = 0;
	if (key == K_UP)
		fract->vel_up = 0;
	if (key == K_DOWN)
		fract->vel_dwn = 0;
//	print_type("key", &key, INT); /****/
	return (0);
}

int		keypress_hook(int key, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	fract = fract;
	if (key == K_LEFT)
		fract->vel_l = MOVE_X;
	if (key == K_RIGHT)
		fract->vel_r = -MOVE_X;
	if (key == K_UP)
		fract->vel_up = MOVE_Y;
	if (key == K_DOWN)
		fract->vel_dwn = -MOVE_X;
//	print_type("key", &key, INT); /*********/
	fract->refresh = 1;
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

void	move_center(t_fractol *fract)
{
	fract->c_x += fract->vel_l;
	fract->c_x += fract->vel_r;
	fract->c_y += fract->vel_dwn;
	fract->c_y += fract->vel_up;
}

int		loop_hook(void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (fract->refresh)
	{
		set_frame(fract);
		move_center(fract);
		fract->refresh = 0;
		mlx_pixel_put(fract->mlx, fract->win, fract->mouse_x, fract->mouse_y, 0xFFFFFF); /**************/
	}
	return (0);
}
