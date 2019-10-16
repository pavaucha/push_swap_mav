#include "srcs/checker/includes/checker.h"

int main(int ac, char **av)
{
	ac = 0;
	int fd;
	(void)av;

	fd = open(av[1], O_RDONLY);
	ft_printf("fd = %d\n", fd);
	return 0;
}