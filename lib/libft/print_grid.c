
#include "libft.h"

void	print_grid(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_putstr_fd(arr[i], STDOUT_FILENO);
		write(1, "\n", 1);
		i++;
	}
}
