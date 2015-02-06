/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:43:57 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/06 22:17:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "debug.h"
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
