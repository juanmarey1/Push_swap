#include "inc/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}


void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void    push_a(t_list **stack_a, t_list **stack_b)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack_b)->next;
    new = ft_lstnew((*stack_b)->content);
    ft_lstadd_front(stack_a, new);
    (*stack_b)->content = NULL;
    (*stack_b)->next = NULL;
    free(*stack_b);
    *stack_b = lsta;
    printf("pa\n");
}

void    push_b(t_list **stack_a, t_list **stack_b)
{
    t_list *new;
    t_list *lsta;

    lsta = (*stack_a)->next;
    new = ft_lstnew((*stack_a)->content);
    ft_lstadd_front(stack_b, new);
    (*stack_a)->content = NULL;
    (*stack_a)->next = NULL;
    free(*stack_a);
    *stack_a = lsta;
    printf("pb\n");
}

void    reverse_rotate_a(t_list **stack_a)
{
    t_list *lst_first;

    lst_first = (*stack_a);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack_a, lst_first->next);
    lst_first->next = NULL;
    printf("rra\n");
}

void    reverse_rotate_b(t_list **stack_b)
{
    t_list *lst_first;

    lst_first = (*stack_b);
    while (lst_first->next->next != NULL)
        lst_first = lst_first->next;
    ft_lstadd_front(stack_b, lst_first->next);
    lst_first->next = NULL;
    printf("rrb\n");
}

void    reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
    t_list *lst_first;
    t_list *lst_first2;

    lst_first = (*stack_a);
    while (lst_first->next->next != NULL)
        lst_first = (lst_first)->next;
    ft_lstadd_front(stack_a, lst_first->next);
    lst_first->next = NULL;
    lst_first2 = (*stack_b);
    while (lst_first2->next->next != NULL)
        lst_first2 = lst_first2->next;
    ft_lstadd_front(stack_b, lst_first2->next);
    lst_first2->next = NULL;
    printf("rrr\n");
}

void    rotate_a(t_list **stack_a)
{
    t_list  *lst_first;
    
    lst_first = *stack_a;
    while ((*stack_a)->next != NULL)
        (*stack_a) = (*stack_a)->next;
    (*stack_a)->next = lst_first;
    (*stack_a) = (*stack_a)->next->next;
    lst_first->next = NULL;
    printf("ra\n");
}

void    rotate_b(t_list **stack_b)
{
    t_list  *lst_first;
    
    lst_first = *stack_b;
    while ((*stack_b)->next != NULL)
        (*stack_b) = (*stack_b)->next;
    (*stack_b)->next = lst_first;
    (*stack_b) = (*stack_b)->next->next;
    lst_first->next = NULL;
    printf("rb\n");
}

void    rotate_ab(t_list **stack_a, t_list **stack_b)
{
    t_list  *lst_first;
    t_list  *lst_first2;
    
    lst_first = *stack_a;
    while ((*stack_a)->next != NULL)
        (*stack_a) = (*stack_a)->next;
    (*stack_a)->next = lst_first;
    (*stack_a) = (*stack_a)->next->next;
    lst_first->next = NULL;
    lst_first2 = *stack_b;
    while ((*stack_b)->next != NULL)
        (*stack_b) = (*stack_b)->next;
    (*stack_b)->next = lst_first2;
    (*stack_b) = (*stack_b)->next->next;
    lst_first2->next = NULL;
    printf("rr\n");
}

void    swap_a(t_list **stack_a)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack_a;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    printf("sa\n");
}

void    swap_b(t_list **stack_b)
{
    t_list  *lst;
    void    *aux;
    
    lst = *stack_b;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    printf("sb\n");
}

void    swap_ab(t_list **stack_a, t_list **stack_b)
{
    t_list  *lst;
    t_list  *lst2;
    void    *aux;
    
    lst = *stack_a;
    aux = lst->content;
    lst->content = lst->next->content;
    lst->next->content = aux;
    lst2 = *stack_b;
    aux = lst2->content;
    lst2->content = lst2->next->content;
    lst2->next->content = aux;
    printf("ss\n");
}

int main(void)
{
    t_list  **stack_a;
    t_list  **stack_b;
    t_list  *new;
    int     i = 0;

    stack_a = (t_list **)malloc(sizeof(t_list*));
    stack_b = (t_list **)malloc(sizeof(t_list*));
    new = ft_lstnew("1");
    ft_lstadd_back(stack_a, new);
    new = ft_lstnew("2");
    ft_lstadd_back(stack_a, new);
    new = ft_lstnew("3");
    ft_lstadd_back(stack_a, new);
    new = ft_lstnew("4");
    ft_lstadd_back(stack_a, new);
    new = ft_lstnew("5");
    ft_lstadd_back(stack_a, new);
    new = *stack_a;
    while (++i < 5)
    {
        printf("%s\n", (char *)(*stack_a)->content);
        (*stack_a) = (*stack_a)->next;
    }
    printf("%s\n", (char *)(*stack_a)->content);
    (*stack_a) = new;
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    printf("%s\n", (char *)(*stack_a)->content);
    printf("%s\n", (char *)(*stack_b)->content);
    swap_a(stack_a);
    swap_b(stack_b);
    printf("%s\n", (char *)(*stack_a)->content);
    printf("%s\n", (char *)(*stack_a)->next->content);
    printf("%s\n", (char *)(*stack_a)->next->next);
    printf("%s\n", (char *)(*stack_b)->content);
    printf("%s\n", (char *)(*stack_b)->next->content);
    printf("%s\n", (char *)(*stack_b)->next->next->content);
    swap_a(stack_a);
    swap_b(stack_b);
    printf("%s\n", (char *)(*stack_a)->content);
    printf("%s\n", (char *)(*stack_a)->next->content);
    printf("%s\n", (char *)(*stack_a)->next->next);
    printf("%s\n", (char *)(*stack_b)->content);
    printf("%s\n", (char *)(*stack_b)->next->content);
    printf("%s\n", (char *)(*stack_b)->next->next->content);
    swap_ab(stack_a, stack_b);
    printf("%s\n", (char *)(*stack_a)->content);
    printf("%s\n", (char *)(*stack_a)->next->content);
    printf("%s\n", (char *)(*stack_a)->next->next);
    printf("%s\n", (char *)(*stack_b)->content);
    printf("%s\n", (char *)(*stack_b)->next->content);
    printf("%s\n", (char *)(*stack_b)->next->next->content);
/*     printf("%s\n", (char *)(*stack_a)->next->content);
    printf("%s\n", (char *)(*stack_b)->next->content); */
    return (0);
}