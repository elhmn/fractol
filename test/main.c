#include <stdio.h>

void	mouse_coord(double *x, double *y)
{
	double	c_x;
	double	c_y;
	double	m_x;
	double	m_y;
	double	q;

	q = 4;
	c_x = 10;
	c_y = 10;
	m_x = 11;
	m_y = 11;

	*x = (m_x - c_x) * (1 / q);
	*y = (-m_y + c_y) * (1 / q);
}

int		main(void)
{
	double		x;
	double		y;

	x = -1;
	y = -1;
	mouse_coord(&x, &y);
	printf("x = [%lf], y = [%lf]\n", x, y);
}
