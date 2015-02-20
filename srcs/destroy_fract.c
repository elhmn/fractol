/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:12:09 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 10:12:27 by bmbarga          ###   ########.fr       */
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

void	destroy_fract(t_fractol *fract)
{
	if (!fract)
		check_errors(NUL, "destroy_fract.c", "fract");
	destroy_type(fract);
	if (fract->win)
		mlx_destroy_window(fract->mlx, fract->win);
	if (fract->fun_fract)
		free(fract->fun_fract);
	if (fract->color)
		free(fract->color);
	if (fract->lay)
		free(fract->lay);
}
