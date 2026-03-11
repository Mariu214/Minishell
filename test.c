#include "libft/include/libft.h"

int main(void)
{
    t_gc    *gc;
    char    *tab;
    char    *tab2;

    gc = NULL;
    tab = ft_calloc_gc(3, sizeof(char), &gc);
    tab = "ab";
    tab2 = ft_calloc_gc(6, sizeof(char), &gc);
    tab2 = "abc";
    ft_printf("%s %s\n", tab, tab2);
    ft_free_all_gc(&gc);
    return (0);
}