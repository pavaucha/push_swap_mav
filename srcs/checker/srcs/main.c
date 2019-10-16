#include "../includes/checker.h"

int		recup_number(int i, char **arg)
{
	int		j;

	j = 1;
	while(j <= i)
	{
		check_int(ft_strsplit(arg[j], ' '));
		j++;
	}
}

int		main(int ac, char **av)
{
	char	*str;
	int 	ret;

	if (av < 2)
		return (0);
	while ((ret = get_next_line(0, &str)) > 0)
	{
		if (str[0] == '\0' || str[0] == '\n')
			break;
		free(str);
	}
	return (0);	
}