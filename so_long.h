
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_map
{
	int			wid;
	int			hei;
	char		**_map;
	char		**temp_map;
	int			p_count;
	int			c_count;
	int			e_count;
}	t_map;

typedef struct s_chr
{
	void	*chr_r;
	void	*chr_l;
	void	*chr_up;
	void	*chr_down;
	int		move_count;
	int		size;
	int		x;
	int		y;
}	t_chr;

typedef struct s_win
{
	t_map	*map;
	t_chr	*chr;
	void	*mlx;
	void	*win;
	void	*bg;
	void	*wall;
	void	*exit;
	void	*coin;
}	t_win;

void	map_size(char *path, t_win *map);
void	ft_error(char	*msg);
void	new_map(t_win *win, char **map, int x, int y);
void	read_map(t_win *win, char *path);
void	read_temp_map(t_win *win, char *path);
void	map_control(t_win	*win, char	**map);
void	render_map(t_win *win, char	**map, int move);
int		ft_key(int keycode, t_win *win);
void	edit_map(int keycode, t_win *win, char **map);
void	find_player(t_win *win, char **map);
void	put_score(t_win *win);
void	file_to_image(t_win *win);
void	render_others(t_win *win, char **map, int move);
void	put(t_win *win, int move, int i, int j);

#endif
