// #include "../../include/minishell.h"

// char    *dollar(char *envp[], char *str)
// {
//     int     i;
//     int     j;
//     char    *temp;

//     i = 0;
//     if (!envp || !str)
//         return (NULL);
//     while (envp[i])
//     {
//         j = 0;
//         while (envp[i][j] && envp[i][j] != '=')
//             j++;
//         temp = ft_substr(envp[i], 0, j);
//         if (temp)
//         {
//             if (strcmp(temp, str) == 0)
//             {
//                 free(temp);
//                 return (ft_substr(envp[i], j + 1, ft_strlen(envp[i])));
//             }
//         }
//         i++;
//     }
//     free(temp);
//     return (NULL);
// }