# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char		*str_buff;
	struct s_list	*next;
}		t_list;

char *get_next_line(int fd);
void    ft_read_into_list(t_list **list, int fd);
void ft_appand_to_list(t_list **list, char *buf);
char *ft_get_line(t_list *list);
void ft_clean_list(t_list **list);

t_list *ft_lstlast(t_list *lst);
void ft_copy(t_list *list, char *line);
int ft_found_newline(t_list *list);
int ft_len_to_newline(t_list *list);
void ft_dealloc(t_list **list, t_list *left_node, char *buf);

# endif