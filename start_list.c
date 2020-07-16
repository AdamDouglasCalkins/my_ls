#include "my_ls.h"

int     ft_strlen(char *str)
{
        int i = 0;
        while (str[i])
                i++;
        return (i);
}

int ft_strcmp(char *s1, char *s2)
{
        int i;
        i = 0;

        while (s1[i])
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }
        return (s1[i] - s2[i]);

}

t_list    *ft_create_elem(char *str, long int dateint, long int dnsec)
{
    t_list *tmp;

    tmp = malloc(sizeof(t_list));
    if (tmp)
    {
        tmp->next = 0;
        tmp->fname = (char*)malloc(sizeof(char) * ((ft_strlen(str)) + 1));
        strcpy(tmp->fname, str);
        tmp->datenum = dateint;
        tmp->datensec = dnsec;
    }
    return (tmp);
}

void    ft_list_push_back(t_list **begin_list, char *str, long int dateint, long int dnsec)
{
    t_list    *tmp;

    tmp = *begin_list;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = ft_create_elem(str, dateint, dnsec);
    }
    else
        *begin_list = ft_create_elem(str, dateint, dnsec);
}
