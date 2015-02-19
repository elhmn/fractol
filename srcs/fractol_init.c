/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 20:47:14 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 12:31:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
#include "check_errors.h"

void	init_var(int *t_iter)
{
	if (t_iter)
	{
		t_iter[0] = ITER_MANDEL;
		t_iter[1] = ITER_JUL;
		t_iter[2] = ITER_MANDEL2;
	}
}

t_fun_fract	choose_type(t_fractol *fract, char *name)
{
	int		i;
	int		t_iter[3];
	char	**type;
	
	i = -1;
	type = fract->type;
	init_var(t_iter);
	while (++i < TYPE_NBR)
		if (!ft_strcmp(type[i], name))
			break;
	if (i == TYPE_NBR)
	{
		ft_putendl("Please choose between : julia, mandelbrot, mandel_cube");
		exit(0);
	}
	fract->fractol = fract->fun_fract[i];
	fract->iter = t_iter[i]; 
	return (fract->fun_fract[i]);
}


void	init_type(t_fractol *fract)
{
	fract->type = (char**)malloc(sizeof(char*) * (TYPE_NBR + 1));
	if (!fract->type)
		check_errors(NUL, "fractol_init.c", "fract->type");
	fract->type[TYPE_NBR] = NULL;
	fract->type[0] = ft_strsub(MANDEL, 0, ft_strlen(MANDEL));
	fract->type[1] = ft_strsub(JUL, 0, ft_strlen(JUL));
	fract->type[2] = ft_strsub(M_CUBE, 0, ft_strlen(M_CUBE));
}

void	fun_fract(t_fractol *fract)
{
	fract->fun_fract = (t_fun_fract*)malloc(sizeof(t_fun_fract) * (TYPE_NBR + 1));
	if (!fract->fun_fract)
		check_errors(NUL, "fractol_init.c", "fract->fun_fract");
	(fract->fun_fract)[TYPE_NBR] = NULL;

	fract->fun_fract[0] = mandelbrot;
	fract->fun_fract[1] = julia;
	fract->fun_fract[2] = mandel_cube;
}

void	init_env(t_fractol *fract)
{
	if (!(fract->mlx = mlx_init()))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
	if (!(fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGH, TITLE)))
		check_errors(MALLOC, "fractol_init.c", "fract->mlx");
}

void	init_fract(t_fractol *fract, char *name)
{
	if (!fract)
		check_errors(NUL, "fractol_init.c", "fract");
	init_type(fract);
//	print_fract(fract); /****************/
	fun_fract(fract);
	choose_type(fract, name);
	fract->color = NULL;
	fract->refresh = 1;
	if (!(fract->lay = (t_lay*)malloc(sizeof(t_lay))))
		check_errors(MALLOC, "fractol_init.c", "fract->lay");
	init_col_type(fract);
	fract->color_type = COLOR_TYPE;
	init_col_tab(fract, fract->color_type); //changer le code couleur
	fract->vel_l = 0;
	fract->vel_r = 0;
	fract->vel_up = 0;
	fract->vel_dwn = 0;
	fract->step = (double)STEP;
	fract->step_tmp = (double)STEP;
	fract->step_aug = (double)STEP_AUG;
	fract->move = 0;
	fract->zoomed = 0;
	fract->m_x = (double)WIDTH / (double)2;
	fract->m_y = (double)HEIGH / (double)2;
	fract->axem_x = fract->m_x;
	fract->axem_y = fract->m_y;
	fract->c_x = 0;
	fract->c_y = 0;
	fract->w = WIDTH / 2.;
	fract->h = HEIGH / 2.;
	fract->jul = 0;
	fract->jul_p = 1;
	fract->help = 1;
	fract->axe = 0;
	fract->re_c = -0.772691322542185;
	fract->im_c = 0.124281466072787;
	fract->a = (HEIGH / 2.) * (1. / (double)STEP);
	fract->b = (WIDTH / 2.) * -1 * (1. / (double)STEP);
}
