/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:48:17 by bmbarga           #+#    #+#             */
/*   Updated: 2015/02/20 09:49:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERRORS_H
# define CHECK_ERRORS_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

# define ERR			ft_putstr("Error : ")
# define ERR_VAR(var)	ft_putstr(var)
# define ERR_SP			ft_putstr(" :: ")
# define ERR_FILE(file)	ft_putstr(file)

# define ERR_MALLOC		ft_putendl("malloc")
# define ERR_NULL		ft_putendl("set to NULL")

typedef void				(*t_ferr)(void);
typedef unsigned int		t_uint;

enum	e_code
{
	MALLOC,
	NUL,
};

/*
** fun_err_01.c
*/

void			f_malloc(void);
void			f_nul(void);

/*
** check_errors.c
*/

void			check_errors(t_uint code, char *file_name, char *var_name);
void			sys_errors(char *str);

#endif
