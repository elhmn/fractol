/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 10:33:50 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/18 19:33:07 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "fractol.h"

enum	e_type
{
	INT,
	CHAR
};

/*
** debug_01.h
*/

void		print_type(char *str, void *elem, int type);
void		print_fract_type(char **type);
void		print_fract(t_fractol *fractol);

#endif
