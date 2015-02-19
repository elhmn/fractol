/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:32:40 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/19 07:02:42 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "X.h"

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

int		motion_notify(int x, int y, void *param)
{
	t_env	*env;

	env = (void*)param;
	env = env;
	printf("x = [%d] && ", x);
	printf("y = [%d]\n", y);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;
	
	env.mlx = NULL;
	env.win = NULL;
	av = av;
	if (ac)
	{
		env.mlx = mlx_init();
		if (!env.mlx)
		{
			printf("error mlx_init\n");
			return (-1);
		}
		env.win = mlx_new_window(env.mlx, 400, 400, "je suis con");
		if (!env.win)
		{
			printf("error mlx_new_window\n");
			return (-1);
		}
		mlx_hook(env.win, MotionNotify, PointerMotionMask, motion_notify, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
