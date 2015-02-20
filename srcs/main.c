/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:43:57 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 12:05:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"

/*
** problemes a resoudre ::
**	0- modifier la var de julia en fonction de la position de la souris a l'ecran																			DONE.
**	1- modifier la variable de julia en gardant une image centree						DONE
**	2- pouvoir definir un nombre d'iteration pour
**		chaque fractal (histoire d'avoir un meilleur rendu pour julia)					DONE
**	3- un button pour l'affichage ou non de l'axe
					DONE
**	4- un button pour modifier la var iter
**	5- s'assurer de la modification de la var d'iter de mandelebrot
	lors du zoom-
					DONE
** 6- button pour modifier la couleur
					DONE
** 7- afficher une legende en fonction de la fractal
					DONE
** 8- implementer la fractal madel cube
					DONE
** 9- changement du type de fractal en appuyant sur une touche
					DONE
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
		mlx_hook(fract.win, MotionNotify, PointerMotionMask, motion_notify, &fract);
		mlx_expose_hook(fract.win, expose_hook, &fract);
		mlx_loop(fract.mlx);
		destroy_fract(&fract);
	}
	else
		ft_putendl("hey bud give me a fractal name");
	return (0);
}
