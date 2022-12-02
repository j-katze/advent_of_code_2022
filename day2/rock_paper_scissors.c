#include "./../libft/libft.h"

int main()
{
	int		fd = open("game_input.txt", O_RDONLY);
	int		score = 0;
	char	*line;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strchr(line, 'X'))
		{
			score += 1;
			if (ft_strchr(line, 'A'))
				score += 3;
			else if (ft_strchr(line, 'C'))
				score += 6;
		}
		else if (ft_strchr(line, 'Y'))
		{
			score += 2;
			if (ft_strchr(line, 'A'))
				score += 6;
			else if (ft_strchr(line, 'B'))
				score += 3;
		}
		else if (ft_strchr(line, 'Z'))
		{
			score += 3;
			if (ft_strchr(line, 'B'))
				score += 6;
			else if (ft_strchr(line, 'C'))
				score += 3;
		}
	}
	ft_printf("%d", score);
}