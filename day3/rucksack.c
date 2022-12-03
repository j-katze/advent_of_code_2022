#include "./../libft/libft.h"

char	find_common(char *comp1, char *comp2)
{
	int	i = 0, j, len = ft_strlen((char *)comp1) + 1;
	
	while (i < len)
	{
		j = 0;
		while(j < len)
		{
			if (comp1[i] == comp2[j])
				return (comp1[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	main()
{
	int		fd = open("test.txt", O_RDONLY);
	int		sum = 0;
	char	*backpack, *comp1, *comp2;
	char	common;

	while((backpack = get_next_line(fd)) != NULL)
	{
		comp1 = ft_substr(backpack, 0, ft_strlen(backpack) / 2);
		comp2 = ft_substr(backpack, ft_strlen(backpack) / 2, ft_strlen(backpack));
		common = find_common(comp1, comp2);
		if (common >= 'a' && common <= 'z')
			sum += common - 'a' + 1;
		else
			sum += common - 'A' + 27;
		ft_printf("%c, %i\n", common, sum);
		free(backpack);
		free(comp1);
		free(comp2);
	}
	close(fd);
}