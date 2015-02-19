/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:43:57 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 06:54:15 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"

/*
** problemes a resoudre ::
**	1- modifier la variable de julia en gardant une image centree
**	2- pouvoir definir un nombre d'iteration pour
**		chaque fractal (histoire d'avoir un meilleur rendu pour julia)
**	3- un button pour l'affichage ou non de l'axe
**	4- un button pour revenir a l'instant fract->step = STEP
**		&& axe au centre && fract->iter = ITER
*/

int					main(int ac, char **av)
{
	t_fractol		fract;

	if (ac > 1)
	{
		init_fract(&fract, av[1]);
		init_env(&fract);
		mlx_key_hook(fract.win, key_release, &fract);
		mlx_mouse_hook(fract.win, mouse_hook, &fract);
		mlx_hook(fract.win, KeyPress, KeyPressMask, keypress_hook, &fract);
		mlx_loop_hook(fract.mlx, loop_hook, &fract);
		mlx_expose_hook(fract.win, expose_hook, &fract);
		mlx_loop(fract.mlx);
		destroy_fract(&fract);
	}
	else
		ft_putendl("hey bud give me a fractal name");
	return (0);
}
