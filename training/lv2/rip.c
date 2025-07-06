#include <unistd.h>

ft_len (char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void check_rip (char *target, int len, int i, int *small, int lvl)
{
    
}

void rip (char *target, int len, int i, int small, int lvl)
{

}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        int len = ft_len (av[1]);
        char *target = av[1];
        int small = -1;
        int i = 0;
        while (i < len)
        {
            if (target[i] != ')' && target[i] != '(')
                return 1;
            i++;
        }
        check_rip (target, len, 0, &small, 0);
        rip (target, len, 0, small, 0);
    }
    else
    {
        if (av[0][1] == '\0')
            write (1, "\n", 1);
    }

    return 0;
}