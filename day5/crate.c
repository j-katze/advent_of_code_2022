#include "./../libft/libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int	main()
{
	FILE	*fp;
	int		quantity, stack_from, stack_to, from_len; 
	int		i;
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	read;

	char	**stacks;
	stacks = malloc(sizeof(char *) * 9);
	stacks[0] = ft_strdup("BWN");
	stacks[1] = ft_strdup("LZSPTDMB");
	stacks[2] = ft_strdup("QHZWR");
	stacks[3] = ft_strdup("WDVJZR");
	stacks[4] = ft_strdup("SHMB");
	stacks[5] = ft_strdup("LGNJHVPB");
	stacks[6] = ft_strdup("JQZFHDLS");
	stacks[7] = ft_strdup("WSFJGQB");
	stacks[8] = ft_strdup("ZWMSCDJ");
	
	
	// stacks[0] = ft_strdup("ZN");
	// stacks[1] = ft_strdup("MCD");
	// stacks[2] = ft_strdup("P");
	fp = fopen("crate_input.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	i = 0;
	while (i < 9)
	{
		printf("%d:	%s\n", i, stacks[i]);
		i++;
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		i = 0;
		while (!ft_isdigit(line[i]))
			i++;
		quantity = ft_atoi(&line[i++]);
		while (ft_isdigit(line[i]))
		 i++;
		while (!ft_isdigit(line[i]))
			i++;
		stack_from = ft_atoi(&line[i++]);
		stack_from--;
		while (!ft_isdigit(line[i]))
			i++;
		stack_to = ft_atoi(&line[i]);
		stack_to--;
		printf("%s\n", line);
		while (quantity > 0)
		{
			from_len = ft_strlen(stacks[stack_from]) - 1;
			strcat(stacks[stack_to], &stacks[stack_from][from_len]);
			stacks[stack_from] = ft_substr(stacks[stack_from], 0, from_len);
			quantity--;
		}
		i = 0;
		while (i < 9)
		{
			printf("%d:	%s\n", i + 1, stacks[i]);
			i++;
		}
		// free(line);
	}
}