
#include "so_long.h"

int	close_frame(t_win *win)
{
	int		i;

	i = -1;
	while (++i < win->map->hei)
		free(win->map->_map[i]);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_win *win)
{
	if (keycode == 65307)
		close_frame(win);
	else if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
		edit_map(keycode, win, win->map->_map);
	else if (keycode == 65361 || keycode == 65363)
		edit_map(keycode, win, win->map->_map);
	else if (keycode == 65364 || keycode == 65362)
		edit_map(keycode, win, win->map->_map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	*win;

	if (argc == 2 && !ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5))
	{
		win = ft_calloc(1, sizeof(t_win));
		win->map = ft_calloc(1, sizeof(t_map));
		win->chr = ft_calloc(1, sizeof(t_chr));
		win->mlx = mlx_init();
		map_size(argv[1], win);
		win->win = mlx_new_window(win->mlx,
				64 * win->map->wid, 64 * win->map->hei, "Space Game");
		read_map(win, argv[1]);
		map_control(win, win->map->_map);
		mlx_hook(win->win, 2, 1L << 0, ft_key, win);
		mlx_hook(win->win, 17, 0, close_frame, win);
		render_map(win, win->map->_map, 97);
		mlx_loop(win->mlx);
	}
	else
		ft_error("Invalid input.");
	return (0);
}
