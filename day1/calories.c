
#include "./../libft/libft.h"

int main()
{
	int	fd = open("calories_input.txt", O_RDONLY);
	char	*line;
	int	read, temp = 0, max1 = 0, max2 = 0, max3 = 0, out;

	while((line = get_next_line(fd)) != NULL)
	{
		read = ft_atoi(line);
		free(line);
		if (read != 0)
			temp += read;
		else
		{
			if (max1 < temp)
			{
				max2 = max1;
				max1 = temp;
			}
			else if (max2 < temp)
			{
				max3 = max2;
				max2 = temp;
			}
			else if (max3 < temp)
				max3 = temp;
			temp = 0;
		}
	}
	close(fd);
	out = max1 + max2 + max3;
	ft_printf("top 3:		%d\n", max3);
	ft_printf("top 2:		%d\n", max2);
	ft_printf("top 1:		%d\n", max1);
	ft_printf("top total:	%d\n", out);
}