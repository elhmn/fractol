#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define TITLE	"Explorateur de fractales"
# define WIDTH	1920
# define HEIGH	1080

# define TYPE_NBR	3
# define JULIA		0
# define MANDELBROT	1
# define KLEINIAN	2 

# define MANDEL		"mandelbrot"
# define JUL		"julia"
# define KLEIN		"kleinian"

# define ESCAPE		65307

typedef unsigned int		t_uint;
typedef struct s_color		t_color;
typedef struct s_fractol	t_fractol;
typedef void (*t_fun_fract)(t_fractol*);

struct					s_fractol
{
	char			**type;
	void			*win;
	void			*mlx;
	void			*img;
	t_fun_fract		*fun_fract;
	t_fun_fract		fractol;
};

struct					s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

/*
** fractol_init.c
*/

void		init_type(t_fractol *fract);
void		init_fract(t_fractol *fract, char *name);
void		init_env(t_fractol *fract);
void		fun_fract(t_fractol *fract);
t_fun_fract	choose_type(t_fractol *fract, char *name);

/*
** destroy_type.c
*/

void		destroy_fract(t_fractol *fract);
void		destroy_type(t_fractol *fract);

/*
** draw.c
*/

void		pixel_put_img(t_fdf *fdf, int x, int y, t_color *col);

/*
** color.c
*/

void		set_color(t_color *col);
void		print_color(t_color *color);
t_uin		rgb_to_color(unsigned int r, unsigned int g, unsigned int b);
void		set_color(t_color *col);
t_color	*init_color(t_color *color, t_uint col);

/*
** julia.c
*/

void		julia(t_fractol *fractol);

/*
** mandelbrot.c
*/

void		mandelbrot(t_fractol *fractol);

/*
** kleinian.c
*/

void		kleinian(t_fractol *fractol);

/*
** event_handle.c
*/

int			key_release(int key, void *param);


#endif
