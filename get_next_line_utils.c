#include "get_next_line.h"

t_list *ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}
void ft_copy(t_list *list, char *line)
{
	int i;
	int k;
	if (!list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list-> str_buff[i])
		{
			if (list->str_buff[i] == '\n')
			{
				line[k++] = '\n';
				line[k] = '\0';
				return ;
			}
			line[k++] = list->str_buff[i++];
		}
		list = list->next;
	}
	line[k] = '\0';
}
int ft_found_newline(t_list *list)
{
    int i;

	if (!list)
		return (0);

	while (list)
	{
		i = 0;
		while (list->str_buff[i] && i < BUFFER_SIZE)
		{
			if (list->str_buff[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);	
}

int ft_len_to_newline(t_list *list)
{
	int i;
	int len;

	if (!list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_buff[i] != '\0')
		{
			if (list->str_buff[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}


void ft_dealloc(t_list **list, t_list *left_node, char *buf)
{
    t_list *temp;

	if (*list == NULL)
		return ;
	//TODO free list
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buff);
		free(*list);
		*list = temp;
	}
	*list = NULL; // initia with NULL ot avoid problems
	if (left_node->str_buff[0])
		*list = left_node;
	//TODO free left_node it nothing left
	else 
	{
		free(buf);
		free(left_node);
	}
	}



