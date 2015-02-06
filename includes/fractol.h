#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "X.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define TITLE		"Explorateur de fractales"

///*
#define HOME
//*/

///*
//# define FT
//*/

# ifdef HOME

#  define WIDTH		400
#  define HEIGH		400

# endif

# ifdef FT

#  define WIDTH		1360
#  define HEIGH		768

# endif

# define COL_NBR	5
# define COL_TYPE	5
# define STEP_DEF	100
# define STEP_AUG	1000
# define STEP		10
# define ITER_AUG	5
# define ITER		10


# define TYPE_NBR	3
# define JULIA		0
# define MANDELBROT	1
# define KLEINIAN	2 

# define MASK_R		0xFF0000
# define MASK_G		0x00FF00
# define MASK_B		0x0000FF

/*
** triad
*/

# define COL_T0_00	0x57BBCC
# define COL_T0_01	0xFF4846
# define COL_T0_02	0x86FFCD
# define COL_T0_03	0x138699
# define COL_T0_04	0xCC3E80

# define COL_T1_00	0xBFBC8A
# define COL_T1_01	0x7F7D5C
# define COL_T1_02	0xFF8B74
# define COL_T1_03	0x40231D
# define COL_T1_04	0x400818

# define COL_T2_00	0x9BFF26
# define COL_T2_01	0xB23A1A
# define COL_T2_02	0x4967CC
# define COL_T2_03	0xFF420E
# define COL_T2_04	0x0E34B2

/*
** analogous
*/

# define COL_T3_00	0xFFD70D
# define COL_T3_01	0xE8AE0C
# define COL_T3_02	0xFFA200
# define COL_T3_03	0xE87C0C
# define COL_T3_04	0xFF650D

/*
** shades
*/

# define COL_T4_00	0x7007BF
# define COL_T4_01	0x4B057F
# define COL_T4_02	0x950AFF
# define COL_T4_03	0x250240
# define COL_T4_04	0x8609E5

# define MANDEL		"mandelbrot"
# define JUL		"julia"
# define KLEIN		"kleinian"

# define MOUSE_MOTION_UP	4
# define MOUSE_MOTION_DOWN	5
# define MOUSE_MOTION_RIGHT	7
# define MOUSE_MOTION_LEFT	6

# define K_ESCAPE 65307
# define K_UP 65362
# define K_DOWN 65364
# define K_RIGHT 65363
# define K_LEFT 65361
//# define K_ENTER 65293
//# define K_PLUS 65451
//# define K_MOINS 65453

typedef unsigned int		t_uint;
typedef struct s_color		t_color;
typedef struct s_fractol	t_fractol;
typedef struct s_lay		t_lay;
typedef void (*t_fun_fract)(t_fractol*);

struct					s_fractol
{
	char			**type;
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_add;
	int				refresh;
	double			iter;
	double			step; // can be consider as k
	double			step_tmp;
	double			im;
	double			re;
	int				*col_tab;
	int				**col_type;
	double			m_x;
	double			m_y;
	double			k;
	double			w;
	double			h;
	double			a;
	double			b;
	double			vel_l;
	double			vel_r;
	double			vel_up;
	double			vel_dwn;
	double			c_x;
	double			c_y;
	double			m_rx;
	double			m_ry;
	t_lay			*lay;
	t_color			*color;
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

struct					s_lay
{
	int		line;
	int		endian;
	int		bpp;
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
** fractol_init_02.c
*/

void		init_col_tab(t_fractol *fract, int type);
void		init_col_type(t_fractol *fract);
void		init_palette_00(int *tab);
void		init_palette_01(int *tab);
void		init_palette_02(int *tab);

/*
** destroy_type.c
*/

void		destroy_fract(t_fractol *fract);
void		destroy_type(t_fractol *fract);

/*
** draw.c
*/

void		pixel_put_img(t_fractol *fract, int x, int y, t_color *col);
t_color		*low_light(t_color *color, t_uint inc, t_uint sign);

/*
** color.c
*/

void		set_color(t_color *col);
void		print_color(t_color *color);
t_uint		rgb_to_color(unsigned int r, unsigned int g, unsigned int b);
void		set_color(t_color *col);
t_color		*init_color(t_color *color, t_uint col);

/*
** julia.c
*/

void		julia(t_fractol *fract);

/*
** mandelbrot.c
*/

void		mandelbrot(t_fractol *fract);

/*
** kleinian.c
*/

void		kleinian(t_fractol *fract);

/*
** event_handle.c
*/

void		set_frame(t_fractol *fract);
int			key_release(int key, void *param);
int			loop_hook(void *param);
int			keypress_hook(int key, void *param);

/*
** event_handle_2.c
*/

int			mouse_hook(int button, int x, int y, void *param);

#endif
