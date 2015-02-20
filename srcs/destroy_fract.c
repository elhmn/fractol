/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:12:09 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 12:32:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "check_errors.h"

void	destroy_type(t_fractol *fract)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = fract->type;
	while (++i < TYPE_NBR)
		free(tmp[i]);
	free(fract->type);
}

void	destroy_col_type(t_fractol *fract)
{
	int		i;

	i = -1;
	if (fract->col_type)
	{
		while (++i < COL_TYPE)
			free(fract->col_type[i]);
		free(fract->col_type);
	}
}

void	destroy_fract(t_fractol *fract)
{
	if (!fract)
		check_errors(NUL, "destroy_fract.c", "fract");
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	destroy_type(fract);
	mlx_destroy_image(fract->mlx, fract->img);
	if (fract->fun_fract)
		free(fract->fun_fract);
	if (fract->col_tab)
		free(fract->col_tab);
	if (fract->lay)
		free(fract->lay);
}
