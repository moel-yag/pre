typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int     sw;
    t_list  *curr = lst;
    while (lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            sw = lst->data;
            lst->data = lst->next->data;
            lst->next->data = sw;
            lst = curr;
        }
        else
            lst = lst->next;
    }
    lst = curr;
    return lst;
}
