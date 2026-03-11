#include "libft/include/libft.h"

int main(void)
{
    t_gc    *gc;
    char    *tab;
    char    *tab2;
    char    *tab3;

    gc = NULL;
    tab = ft_calloc_gc(3, sizeof(char), &gc);
    tab = "ab";
    tab2 = ft_strdup_gc(tab, &gc);
    tab3 = ft_strjoin_gc(tab, tab2, &gc);
    ft_printf("%s %s %s\n", tab, tab2, tab3);
    ft_free_all_gc(&gc);
    return (0);
}