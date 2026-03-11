#include "libft/include/libft.h"

int main(int ac, char **av)
{
    t_gc    *gc;
    // char    *tab;
    char    **tab2;
    int     i;

    i = 0;
    (void)ac;
    gc = NULL;
    tab2 = ft_split_space_gc(av[1], ' ', av[2], &gc);
    if (!tab2)
        ft_free_all_gc(&gc);
    while (tab2[i])
    {
        ft_printf("%s\n", tab2[i]);
        i++;
    }
    ft_free_all_gc(&gc);
    return (0);
}