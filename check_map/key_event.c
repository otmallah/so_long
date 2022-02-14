#include "../so_long.h"

char   **key_event(char *file, t_long *index)
{
    int i = 0;
	int x;
    int  fd = open(file , O_RDONLY);
    char *str = get_next_line(fd);
    int a = ft_number_line(index->file);
    char **str2 = calloc(sizeof(char *) , (a + 1));
    while (str)
    {
        x = strlen(str);
        str2[i] = calloc(sizeof(char) , (x + 1));
        i++;
        free(str);
        str = get_next_line(fd);
    }
    ft_wall(str2, index);
    if ( index->idx == 0 && index->line == 0)
	{
		index->idx = find_position_index(str2);
		index->line = find_position_line(str2);
	}
    free(str);
    close(fd);
	return str2;
}

char   **key_event_enemy(char *file, t_long *index)
{
    int i = 0;
	int x;
    int  fd = open(file , O_RDONLY);
    char *str = get_next_line(fd);
    int a = ft_number_line(index->file);
    char **str2 = calloc(sizeof(char *) , (a + 1));
    while (str)
    {
        x = strlen(str);
        str2[i] = calloc(sizeof(char) , (x + 1));
        i++;
        free(str);
        str = get_next_line(fd);
    }
    ft_wall(str2, index);
    free(str);
    close(fd);
	return str2;
}