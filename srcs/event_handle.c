#include "fractol.h"
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
