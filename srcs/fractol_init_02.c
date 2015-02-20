/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:51:38 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 12:19:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"

void	init_col_type(t_fractol *fract)
{
	int		**tab;
	int		i;

	i = -1;
	fract->col_type = (int**)malloc(sizeof(int*) * COL_TYPE);
	if (!(tab = fract->col_type))
		check_errors(MALLOC, "fract_init_02.c", "tab");
	while (++i < COL_TYPE)
	{
		tab[i] = (int*)malloc(sizeof(int) * COL_NBR);
		if (!tab[i])
			check_errors(MALLOC, "fract_init_02.c", "tab[0]");
	}
	init_palette_00(tab[0]);
	init_palette_01(tab[1]);
	init_palette_02(tab[2]);
	init_palette_03(tab[3]);
	init_palette_04(tab[4]);
	init_palette_05(tab[5]);
}

void	init_col_tab(t_fractol *fract, int type)
{
	int		i;

	i = -1;
	if (!fract)
		check_errors(NUL, "frac_init_02.c", "fract");
	while (++i < COL_TYPE)
	{
		if (i == type)
		{
			fract->col_tab = fract->col_type[i];
			break ;
		}
	}
	if (i == COL_TYPE)
	{
		ft_putendl("unknown color refenrence");
		exit (-1);
	}
}
