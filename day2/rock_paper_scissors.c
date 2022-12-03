#include "./../libft/libft.h"

static char	*find_strat(char *line)
{
	char	*strat;

	if (ft_strchr(line, 'A'))
		{
			if (ft_strchr(line, 'X'))
				strat = "A Z";
			else if (ft_strchr(line, 'Y'))
				strat = "A X";
			else if (ft_strchr(line, 'Z'))
				strat = "A Y";
		}
		else if (ft_strchr(line, 'B'))
		{
			if (ft_strchr(line, 'X'))
				strat = "B X";
			else if (ft_strchr(line, 'Y'))
				strat = "B Y";
			else if (ft_strchr(line, 'Z'))
				strat = "B Z";
		}
		else if (ft_strchr(line, 'C'))
		{
			if (ft_strchr(line, 'X'))
				strat = "C Y";
			else if (ft_strchr(line, 'Y'))
				strat = "C Z";
			else if (ft_strchr(line, 'Z'))
				strat = "C X";
		}
	return(strat);
}

int main()
{
	int		fd = open("game_input.txt", O_RDONLY);
	int		score = 0;
	char	*line, *strat;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		strat = find_strat(line);
		if (ft_strchr(strat, 'X'))
		{
			score += 1;
			if (ft_strchr(strat, 'A'))
				score += 3;
			else if (ft_strchr(strat, 'C'))
				score += 6;
		}
		else if (ft_strchr(strat, 'Y'))
		{
			score += 2;
			if (ft_strchr(strat, 'A'))
				score += 6;
			else if (ft_strchr(strat, 'B'))
				score += 3;
		}
		else if (ft_strchr(strat, 'Z'))
		{
			score += 3;
			if (ft_strchr(strat, 'B'))
				score += 6;
			else if (ft_strchr(strat, 'C'))
				score += 3;
		}
		free(line);
	}
	ft_printf("%d", score);
}