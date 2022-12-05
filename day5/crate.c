#include "./../libft/libft.h"
#include <strings.h>
#include <stdio.h>

int	main()
{
	int		fd = open("test.txt", O_RDONLY);
	int		quantity, stack_from, stack_to; 
	int		i;
	char	*line, temp;

	char	stack1[100] = {'Z', 'N'};
	char	stack2[100] = {'M', 'C', 'D'};
	char	stack3[100] = {'P'};

	ft_printf("%s\n%s\n%s\n", stack1, stack2, stack3);
	while ((line = get_next_line(fd)) != NULL)
	{
		i = 0;
		while (!ft_isdigit(line[i]))
			i++;
		quantity = ft_atoi(&line[i++]);
		while (!ft_isdigit(line[i]))
			i++;
		stack_from = ft_atoi(&line[i++]);
		while (!ft_isdigit(line[i]))
			i++;
		stack_to = ft_atoi(&line[i]);
		ft_printf("%d, %d, %d\n", quantity, stack_from, stack_to);
		
	}
}