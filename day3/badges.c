#include "./../libft/libft.h"

char	find_common(char *backpack1, char *backpack2, char *backpack3)
{
	int	i = 0, j, k;
	
	while (backpack1[i])
	{
		j = 0;
		while(backpack2[j])
		{
			k = 0;
			while(backpack3[k])
			{
				if (backpack1[i] == backpack2[j] && backpack1[i] == backpack3[k])
					return (backpack1[i]);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main()
{
	int		fd = open("rucksack_input.txt", O_RDONLY);
	int		sum = 0;
	char	*backpack1, *backpack2, *backpack3;
	char	common;

	while((backpack1 = get_next_line(fd)) != NULL)
	{
		backpack2 = get_next_line(fd);
		backpack3 = get_next_line(fd);
		common = find_common(backpack1, backpack2, backpack3);
		if (common >= 'a' && common <= 'z')
			sum += common - 'a' + 1;
		else
			sum += common - 'A' + 27;
		ft_printf("%c, %i\n", common, sum);
		free(backpack1);
		free(backpack2);
		free(backpack3);
	}
	close(fd);
}