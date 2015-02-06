#include "fractol.h"
#include "check_errors.h"
#include "debug.h"

/*
static void mouse_move_center(t_fractol *fract, int x, int y, int sign)
{
	if (sign >= 0)
	{
		fract->c_x = fract->c_x + (double)((double)WIDTH / 2. - x);
		fract->c_y = fract->c_y + (double)((double)HEIGH / 2. - y);
	}
	else
	{
		fract->c_x = fract->c_x - (double)((double)WIDTH / 2. - x);
		fract->c_y = fract->c_y - (double)((double)HEIGH / 2. - y);
	}
	fract->pre_c_x = fract->c_x;
	fract->pre_c_y = fract->c_y;
}
*/

int		mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fract;

	fract = (t_fractol*)param;
	if (!fract)
		check_errors(NUL, "event_handle_2.c", "fract");
	if (button == MOUSE_MOTION_UP)
	{
		fract->step += STEP_DEF;
		if (fract->step - fract->step_tmp >= STEP_AUG)
		{
			fract->iter += ITER_AUG;
			fract->step_tmp = fract->step;
		}
		fract->m_x = x;
		fract->m_y = y;
	}
	if (button == MOUSE_MOTION_DOWN)
	{
		if (fract->step > STEP_DEF)
			fract->step -= STEP_DEF;
		if (fract->step_tmp - fract->step >= STEP_AUG)
		{
			if (fract->iter >= ITER_AUG)
			{
				fract->iter -= ITER_AUG;
				fract->step_tmp = fract->step;
			}
		}
		fract->m_x = x;
		fract->m_y = y;
	}
	print_type("button", &button, INT);
	print_type("x", &x, INT);
	print_type("y", &y, INT);
	fract->refresh = 1;
	fract->k = fract->step;
	//Ce sont mes coords m_x qui sont fausse
	return (0);
}
