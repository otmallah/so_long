#include "../so_long.h"

char   **key_event(void)
{
    int i = 0;
	int x;
    int  fd = open("./test/test.ber" , O_RDONLY);
    char *str = get_next_line(fd);
    int a = ft_number_line();
    char **str2 = calloc(sizeof(char *) , (a + 1));
    while (str)
    {
        x = strlen(str);
        str2[i] = calloc(sizeof(char) , (x + 1));
        i++;
        str = get_next_line(fd);
    }
    ft_wall(str2);
    if ( idx == 0 && line == 0)
	{
		idx = find_position_index(str2);
		line = find_position_line(str2);
	}
	return str2;
}
