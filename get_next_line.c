#include "get_next_line.h"

void ft_clean_list(t_list **list)
{
    t_list *last_node;
    t_list *left_node;
    int i;
    int k;
    char *buf;

    buf = malloc(BUFFER_SIZE + 1);
    left_node = malloc(sizeof(t_list));
    if (!buf || !left_node)
        return ;
    last_node = ft_lstlast(*list);
    i = 0;
    k = 0;
    while (last_node->str_buff[i] && last_node->str_buff[i] != '\n')
        ++i;
    while (last_node->str_buff[i] && last_node->str_buff[++i])
        buf[k++] = last_node->str_buff[i];
    buf[k] = '\0';
    left_node->str_buff = buf;
    left_node->next = NULL;
    ft_dealloc(list, left_node, buf);
}
char *ft_get_line(t_list *list)
{
    int str_len;
    char *line;
    if (!list)
        return (NULL);
    str_len = ft_len_to_newline(list);
    line = malloc(str_len + 1);
    if (!line)
        return (NULL);
    ft_copy(list , line);
    return (line);
}

void ft_appand_to_list(t_list **list, char *buf)
{
    t_list *new_node;
    t_list *last_node;

    last_node = ft_lstlast(*list); // ??
    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    if (!last_node)
        *list = new_node;
    else
        last_node->next = new_node;
    new_node->str_buff = buf;
    new_node->next = NULL;
}
void    ft_read_into_list(t_list **list, int fd)
{
    int bytes_read;
    char *buf;

    while (!ft_found_newline(*list))
    {
        buf = malloc(BUFFER_SIZE + 1); //!
        if (!buf)
            return ;
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (!bytes_read)
        {
            free(buf);
            return ;       
        }
        buf[bytes_read] = '\0';
        ft_appand_to_list(list, buf);
    }
    
}
char *get_next_line(int fd)
{
    static t_list *list;
    char           *line;

    list = NULL; //! we need to initia static /any Vt
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0) 
        return (NULL);  
    ft_read_into_list(&list, fd);
    if (!list)
        return (NULL);
    line = ft_get_line(list);
    ft_clean_list(&list);
    return (line);
}
