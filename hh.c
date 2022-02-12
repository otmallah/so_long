
#include "so_long.h"

char	*utils_move_down(void)
{
	char *str;
	static int a = 152;
	char *c = ft_itoa(a);
	str = ft_strjoin("move num : ", c);
    printf("%s 95\n", str);
	a++;
	return str;
}

int main(void)
{
    int a = 1;
        char *c = utils_move_down();
        printf("%s \n", c);
        a++;
}