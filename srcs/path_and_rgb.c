
#include "../include/cub3d.h"

int is_direction_or_rgb(t_window *window, char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{//get path 함수 : 스페이스바 일동안에는 계속 가다가 아닌 부분을 만나면 그 부분을 경로로 저장.
	//get_rgb 함수 : RGB 값을 저장하되 쉼표, 스페이스바 혹은 숫자가 아닌 값이 들어있으면 에러이다/ 
		if ((str[i] == 'w' || str[i] == 'W') && window->map_row == 0)
			return (get_path(window, &str[i + 1], WEST));
		else if ((str[i] == 's' || str[i] == 'S') && window->map_row == 0)
			return (get_path(window, &str[i + 1], SOUTH));
		else if ((str[i] == 'n' || str[i] == 'N') && window->map_row == 0)
			return (get_path(window, &str[i + 1], NORTH));
		else if ((str[i] == 'e' || str[i] == 'E') && window->map_row == 0)
			return (get_path(window, &str[i + 1], EAST));
		else if (str[i] == 'F' && window->map_row == 0)
			return (get_rgb(window, &str[i + 1], F));
		else if (str[i] == 'C' && window->map_row == 0)
			return (get_rgb(window, &str[i + 1], C));
		else if(i == 0 && ft_isdigit(str[i]))
		{
			window->map_col = findmax(window->map_col, (int)ft_strlen(str));
			window->map_row++;
			return (MAP);
		}
	}
	return (0);
}

int get_path(t_window *window, char *path, int flag)
{
	int	i;
	t_image	*node;

	i = 0;
	while (path[i] != '\0' && ft_isspace(path[i]))
		i++;
	
	
	if (path[i] != 0)
	{
		node = find_direction(window, flag);//N, S, W, E 중에 어떤 건지 flag에 저장되어있으므로, 거기에서 맞는 N_img, S_img를 node에 담아온다. 
		node->path = path + i;
		// N , S, W, E는 define 된 값으로 (2,4,8,16 값을 갖고 있음)
		// 맞는 순서대로 경로를 저장하는지 확인하는 수단: exist_flag
		//exist_ flag 를 N , S, W, E 순으로 받으면서 2를 곱해가기 때문에, flag(N:2, S:4, W: 8, E: 16)와 exit_flag가 맞게 떨어지는지 확인한다. 
		//이후에 check_count 함수에서 16이라는 값이 맞는지 확인한다. 
		if (window->exist_flag != flag / 2)
			ft_put_error("Error: direction order\n");
		window->exist_flag *= 2;
		return (0);
	}
	else
		ft_put_error("Error: map\n");
	return (1);
}

int  get_rgb(t_window *window, char *str, int flag)
{
	int i;
	int j;
	int ret;
	int cnt;
	int	*ptr;

	i = -1;
	cnt = 0;
	while (str[++i] != '\0')
	{	
		j = 0;
		ret = 0;
		while ((ft_isspace(str[i + j]) || str[i + j] == ',') && str[i+j] != '\0')
			j++;
		i += j;
		if(!ft_isdigit(str[i]))
			ft_put_error("Error: get rgb\n");
		while (ft_isdigit(str[i]) && (str[i] != '\0'))
			ret = ret * 10 + str[i++] - '0';
		ptr = find_rgb(window, flag, cnt);
		*ptr = ret;
		cnt++;
	}
	return (0);
}
