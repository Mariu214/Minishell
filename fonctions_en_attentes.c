void   search_pwd(char **envp)
{
    int i;

    i = 0;
    while (envp[i] && !ft_strnstr(envp[i], "PWD", 1000))
        i++;
    printf("%s\n", ft_strnstr(envp[i], "PWD", 1000));
}