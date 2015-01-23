#include "fractol.h"
#include "check_errors.h"


void	init_palette_00(int *tab)
{
	tab[0] = COL_T0_00;
	tab[1] = COL_T0_01;
	tab[2] = COL_T0_02;
	tab[3] = COL_T0_03;
	tab[4] = COL_T0_04;
}

void	init_palette_01(int *tab)
{
	tab[0] = COL_T1_00;
	tab[1] = COL_T1_01;
	tab[2] = COL_T1_02;
	tab[3] = COL_T1_03;
	tab[4] = COL_T1_04;
}

void	init_palette_02(int *tab)
{	
	tab[0] = COL_T2_00;
	tab[1] = COL_T2_01;
	tab[2] = COL_T2_02;
	tab[3] = COL_T2_03;
	tab[4] = COL_T2_04;
}

void	init_col_type(t_fractol *fract)
{
	int		**tab;
	int		i;

	i = -1;
	fract->col_type = (int**)malloc(sizeof(int*)* COL_TYPE);
	if (!(tab = fract->col_type))
		check_errors(MALLOC, "fract_init_02.c", "tab");
	while (++i < COL_TYPE)
	{
		tab[i] = (int*)malloc(sizeof(int) * COL_NBR);
		if (!tab[i])
			check_errors(MALLOC, "fract_init_02.c", "tab[0]");
	}
	// a mettre dans un tableau de fonction
	init_palette_00(tab[0]);
	init_palette_01(tab[1]);
	init_palette_02(tab[2]);
}

void	init_col_tab(t_fractol *fract, int type)
{
	int		i;

	i = -1;
	if (!fract)
		check_errors(NUL, "frac_init_02.c", "fract");
	fract->col_tab = (int*)malloc(sizeof(int) * COL_NBR);
	if (!fract->col_tab)
		check_errors(NUL, "fract_init_02.c", "fract->col_tab");
	while (++i < COL_TYPE)
	{
		if (i == type)
		{
			fract->col_tab = fract->col_type[i];
			break;
		}
	}
	if (i == COL_TYPE)
	{
		ft_putendl("unknown color refenrence");
		exit (-1);
	}
}
