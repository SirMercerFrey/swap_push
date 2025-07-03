#include "push_swap.h"

t_head	*create_pile(void)
{
	t_head	*pile;

	pile = malloc(sizeof(t_head));
	if (!pile)
		return (NULL);
	pile->first = NULL;
	pile->last = NULL;
	pile->size = 0;
	return (pile);
}

t_node	*create_element(int val)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->prev = NULL;
	elem->val = val;
	elem->index = -1;
	return (elem);
}

void	ft_lst_add_back(t_head **pile, t_node *elem)
{
	if ((*pile)->size == 0)
	{
		(*pile)->first = elem;
		(*pile)->last = elem;
		++(*pile)->size;
		return ;
	}
	(*pile)->last->next = elem;
	elem->prev = (*pile)->last;
	(*pile)->last = elem;
	++(*pile)->size;
}

void	print_piles(t_head *pile_a, t_head *pile_b)
{
	t_node	*tmp;

	if (!pile_a || !pile_b)
		return ;
	tmp = pile_a->first;
	while (tmp)
	{
		printf("\\_%d_/ [%d]\n", tmp->val, *&(tmp->index));
		tmp = tmp->next;
	}
	printf(" pile a (%d elements)\n", pile_a->size);
	tmp = pile_b->first;
	while (tmp)
	{
		printf("\\_%d_/ [%d]\n", tmp->val, *&(tmp->index));
		tmp = tmp->next;
	}
	printf(" pile b (%d elements)\n", pile_b->size);
}

void	free_pile(t_head *pile)
{
	t_node	*tmp;

	if (!pile)
		return ;
	while (pile->first)
	{
		tmp = pile->first;
		pile->first = pile->first->next;
		free(tmp);
	}
	free(pile);
}
