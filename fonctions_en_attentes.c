// flemme de faire un truc constructifs, ca cest bien cest simple


void   search_pwd(char **envp)
{
    int i;

    i = 0;
    while (envp[i] && !ft_strnstr(envp[i], "PWD", 1000))
        i++;
    printf("%s\n", ft_strnstr(envp[i], "PWD", 1000));
}

void   env(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
        printf("%s\n", envp[i]);
}