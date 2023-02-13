
#include "cub3d.h"

t_image	*find_direction(t_window *window, int flag)
{
	if (flag == NORTH)
		return (window->N_img);
	else if (flag == EAST)
		return (window->E_img);
	else if (flag == SOUTH)
		return (window->S_img);
	else if (flag == WEST)
		return (window->W_img);
}

int	*find_rgb(t_window *window, int flag, int i)
{
	if (flag == F)
	{
		if(i == 0)
			return (&(window->floor.r));
		else if (i == 1)
			return (&(window->floor.g));
		else if (i == 2)
			return (&(window->floor.b));
		
	}	
	else if (flag == C)
	{
		if(i == 0)
			return (&(window->ceiling.r));
		else if (i == 1)
			return (&(window->ceiling.g));
		else if (i == 2)
			return (&(window->ceiling.b));
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
		return WEST;
	else if (ch == 'N')
		return NORTH;
	else if (ch == 'S')
		return SOUTH;
	else if (ch == 'E')
		return EAST;
}

char	**return_array(int row, int col)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = (char **)malloc(sizeof(char*)*i);
	if(!tmp)
		ft_put_error("Error\n");
	while (++i <= row)
	{
		tmp[i] = (char*)malloc(sizeof(char)*col);
		if (!tmp[i])
		{
			ft_clean(tmp, i);
			ft_put_error("Error\n");			
		}
	}
	return (tmp);
}