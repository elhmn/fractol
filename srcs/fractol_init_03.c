/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:46:27 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 10:58:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

void				init_palette_00(int *tab)
{
	tab[0] = COL_T0_00;
	tab[1] = COL_T0_01;
	tab[2] = COL_T0_02;
	tab[3] = COL_T0_03;
	tab[4] = COL_T0_04;
}

t_fun_fract			choose_type(t_fractol *fract, char *name)
{
	int		i;
	int		t_iter[3];
	char	**type;

	i = -1;
	type = fract->type;
	init_var(t_iter);
	while (++i < TYPE_NBR)
		if (!ft_strcmp(type[i], name))
			break ;
	if (i == TYPE_NBR)
	{
		ft_putendl("Please choose between : julia, mandelbrot, mandel_cube");
		exit(0);
	}
	fract->fractol = fract->fun_fract[i];
	fract->iter = t_iter[i];
	return (fract->fun_fract[i]);
}

void				init_type(t_fractol *fract)
{
	fract->type = (char**)malloc(sizeof(char*) * (TYPE_NBR + 1));
	if (!fract->type)
		check_errors(NUL, "fractol_init.c", "fract->type");
	fract->type[TYPE_NBR] = NULL;
	fract->type[0] = ft_strsub(MANDEL, 0, ft_strlen(MANDEL));
	fract->type[1] = ft_strsub(JUL, 0, ft_strlen(JUL));
	fract->type[2] = ft_strsub(M_CUBE, 0, ft_strlen(M_CUBE));
}

void				fun_fract(t_fractol *fract)
{
	fract->fun_fract =
		(t_fun_fract*)malloc(sizeof(t_fun_fract) * (TYPE_NBR + 1));
	if (!fract->fun_fract)
		check_errors(NUL, "fractol_init.c", "fract->fun_fract");
	(fract->fun_fract)[TYPE_NBR] = NULL;
	fract->fun_fract[0] = mandelbrot;
	fract->fun_fract[1] = julia;
	fract->fun_fract[2] = mandel_cube;
}
