#include "push_swap.h"

static int	ft_isspace(const char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

int ft_atol(const char *str) // Function to convert a string to a long integer
{
    int sign;
    long long res;

    sign = 1;
    res = 0;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (ft_isdigit(*str))
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return ((int)(res * sign));
}