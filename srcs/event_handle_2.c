#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

int		mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (!fract)
		check_errors(NUL, "event_handle_2.c", "fract");
	if (button == MOUSE_MOTION_UP)
		fract->step += 10;
	if (button == MOUSE_MOTION_DOWN)
		fract->step -= 10;
	print_type("button", &button, INT);
	print_type("x", &x, INT);
	print_type("y", &y, INT);
	fract->refresh = 1;
	return (0);
}
