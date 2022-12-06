#include "./../libft/libft.h"

int main()
{
	int fd = open("decode.txt", O_RDONLY);
	char *line;
	int i = 0, j, k, found, p;
	char temp[14] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};

	if ((line = get_next_line(fd)) == NULL)
		exit (1);
	while (line[i])
	{
		j = 0;
		p = i;
		while (temp[j])
		{
			temp[j] = line[p];
			p++;
			j++;
		}
		ft_printf("%s\n", temp);
		j = 0;
		found = 1;
		while (temp[j])
		{
			k = j + 1;
			while (temp[k])
			{
				if (temp[j] == temp[k])
					found = 0;
				k++;
			}
			j++;
		}
		if (found == 1)
		{
			ft_printf("%i", i + 14);
			free(line);
			exit(1);
		}
		i++;
	}
	free(line);
}