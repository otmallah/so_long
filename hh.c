
#include "so_long.h"

char	*utils_move_down(void)
{
	char *str;
	static int a;
	char *c = ft_itoa(a);
	str = ft_strjoin("move num : ", c);
	a++;
	return str;
}

int main(void)
{
    int a = 1;
    while (a < 100)
    {
        char *c = utils_move_down();
        printf("%s \n", c);
        a++;
    }
    // char *str = ft_strjoin("mouve number ", c);
    // printf("%s \n", str);
}