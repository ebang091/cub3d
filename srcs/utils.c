
#include "../include/cub3d.h"

t_image	*find_direction(t_window *window, int flag)
{
	if (flag == NORTH)
		return (&window->N_img);
	else if (flag == EAST)
		return (&window->E_img);
	else if (flag == SOUTH)
		return (&window->S_img);
	else if (flag == WEST)
		return (&window->W_img);
	else 
		return (NULL);
}

int	*find_rgb(t_window *window, int flag, int i)
{
	printf("flag = %d cnt = %d", flag,  i);
	if (flag == F && i == 0)
		return (&(window->floor.r));
	else if (flag == F && i == 1)
		return (&(window->floor.g));
	else if (flag == F && i == 2)
		return (&(window->floor.b));
	else if (flag == C && i == 0)
		return (&(window->ceiling.r));
	else if(flag == C && i == 1)
		return (&(window->ceiling.g));
	else if (flag == C && i == 2)
		return (&(window->ceiling.b));
	else
		{
			ft_put_error("error: F C value\n");
			return (0);
		}
}

int	findmax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int alphatodefnum(char ch)
{
	if (ch == 'W')
		return (WEST);
	else if (ch == 'N')
		return (NORTH);
	else if (ch == 'S')
		return (SOUTH);
	else if (ch == 'E')
		return (EAST);
	else 
		return (1);
}

int	**return_array(int row, int col)
{
	int		**tmp;
	int		i;

	i = -1;
	tmp = (int **)malloc(sizeof(int*) * row);
	if(!tmp)
		ft_put_error("Error malloc\n");
	while (++i <= row)
	{
		tmp[i] = (int *)malloc(sizeof(int) * col);
		if (!tmp[i])
		{
			ft_clean(tmp, i);
			ft_put_error("Error\n");			
		}
	}
	return (tmp);
}