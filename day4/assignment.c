#include "./../libft/libft.h"

int	main()
{
	int 	fd = open("assignment_input.txt", O_RDONLY);
	int		overlap_count = 0, elf1id1, elf1id2, elf2id1, elf2id2;
	int		i, j, k;
	char	*line;

	while((line = get_next_line(fd)) != NULL)
	{
		i = 0;
		while (line[i++])
		{
			j = 0;
			k = j;
			while(line[j] != '-')
				j++;
			elf1id1 = ft_atoi(ft_substr(line, k, j));
			j++;
			k = j;
			while(line[j] != ',')
				j++;
			elf1id2 = ft_atoi(ft_substr(line, k, j));
			j++;
			k = j;
			while(line[j] != '-')
				j++;
			elf2id1 = ft_atoi(ft_substr(line, k, j));
			j++;
			k = j;
			while(line[j] != ',')
				j++;
			elf2id2 = ft_atoi(ft_substr(line, k, j));
		} 
		if((elf1id1 <= elf2id1 && elf1id2 >= elf2id2) || (elf2id1 <= elf1id1 && elf2id2 >= elf1id2)
			|| (elf1id1 <= elf2id1 && elf1id2 >= elf2id1) || (elf2id1 <= elf1id1 && elf2id2 >= elf1id1))
			overlap_count++;
		ft_printf("%d, %d, %d, %d,	%d\n", elf1id1, elf1id2, elf2id1, elf2id2, overlap_count);
		free(line);
	}
}