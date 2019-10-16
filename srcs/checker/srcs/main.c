#include "../includes/checker.h"

int main(int ac, char **av)
{
	ac = 0;
	int fd;
	(void)av;
	char *str;

	fd = open(av[1], O_RDONLY);

	while (get_next_line(fd, &str) != 0)
		ft_printf("%s\n", str);

	return 0;
}