#include "cub3d.h"

int	check_color_range(int r, int g, int b)
{
	int	ret;

	ret = 0;
	if (!(r >= 0 && r <= 255))
		ret |= 1;
	if (!(g >= 0 && g <= 255))
		ret |= 1;
	if (!(b >= 0 && b <= 255))
		ret |= 1;
	return (ret);
}

int		is_number_arr(char **arr, int index_num, int type)
{
	int	k;
	int	i;

	k = 0;
	while (arr[k])
	{
		i = 0;
		while (arr[k][i])
		{
			if (!(arr[k][i] >= 48 && arr[k][i] <= 57))
				return (ERR_PARSE);	
			++i;
		}
		++k;
	}
	if (index_num != k)
		return (ERR_PARSE);
	if (type == CONFIG_F || type == CONFIG_C)
		if(check_color_range(ft_atoi(arr[0]), ft_atoi(arr[1]), ft_atoi(arr[2])))
			return (ERR_PARSE);
	return (0);
}


