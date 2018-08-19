#include "../includes/ft_select.h"

int	check_empty_args(int argc, char **argv, int i, int j)
{
	unsigned int	spaces;
	
	while (i < argc)
	{
		spaces = 0;
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				spaces++;
			j++;
		}
		if (spaces == ft_strlen(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}	
