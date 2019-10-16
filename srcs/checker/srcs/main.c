#include "../includes/checker.h"

int main(int ac, char **av)
{
	(void)av;
	char *str;
	int ret;

	for (int i = 0; i < ac; i++)
		ft_printf("av[%d] = %s\n", i, av[i]);
	while ((ret = get_next_line(0, &str)) != 0)
	{
		if (str[0] == '\0' || str[0] == '\n')
			break;
		free(str);
	}
	return 0;
}