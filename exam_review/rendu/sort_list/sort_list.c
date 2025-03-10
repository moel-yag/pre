#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// typedef struct  s_list
// {
//     struct s_list   *next;
//     void            *data;
// }               t_list;


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int tmp_n;
    t_list *tmp = lst;

    while (lst->next)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            tmp_n = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp_n;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return lst;
}
