#include "../includes/checker.h"

int		check_int(char **str)
{
    int     i;
    t_numb  *numb;

    i = 0;
    while(str[i])
    {
        if (ft_atoi(str[i]) < -2147483648 || ft_atoi(str[i]) > 2147483647))
        {
            numb->ch = ft_atoi(str[i]);
            numb->next = numb;
        }
    }

	
}

int		check_instruct(char *str)
{
	if (str != "sa" || str != "sb" || str != "ss" || str != "pa"
		|| str != "pb" || str != "ra" || str != "rb" || str != "rr"
		|| str != "rra" || str != "rrb" || str != "rrr")
		return (print_error());
	return (1);
}
