/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:28:40 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 19:33:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "fractol.h"
#include "check_errors.h"

void		print_type(char *str, void *elem, int type)
{
	int		*nbr;
	char	*car;

	if (type == INT)
	{
		nbr = (int*)elem;
		ft_putstr(str);
		ft_putstr(" = [");
		ft_putnbr(*nbr);
		ft_putendl("]");
	}
	if (type == CHAR)
	{
		car = (char*)elem;
		ft_putstr(str);
		ft_putstr(" = [");
		ft_putstr(car);
		ft_putendl("]");
	}
}

void	print_fract_type(char **type)
{
	int		i;

	i = -1;
	if (!type)
		check_errors(NUL, "debug_01.c", "fract");
	while (++i < TYPE_NBR)
	{
		ft_putstr("type[");
		ft_putnbr(i);
		ft_putstr("] : [");
		ft_putstr(type[i]);
		ft_putendl("]");
	}
}

void	print_fract(t_fractol *fract)
{
	if (!fract)
		check_errors(NUL, "debug_01.c", "fract");
	print_fract_type(fract->type);
}
