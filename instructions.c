#include "push_swap.h"

int	swap(t_head *pile)
{
	t_node	*first;
	t_node	*second;

	if (!pile || pile->size < 2)
		return (0);
	first = pile->first;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	pile->first = second;
	if (first->next == NULL)
		pile->last = first;
	return (1);
}

void	swap_a(t_head *pile_a)
{
	if (swap(pile_a))
		printf("sa\n");
}

void	swap_b(t_head *pile_b)
{
	if (swap(pile_b))
		printf("sb\n");
}

void	swap_both(t_head *pile_a, t_head *pile_b)
{
	if (swap(pile_a) && swap(pile_b))
		printf("ss\n");
}

int	push(t_head *from, t_head *to)
{
	t_node	*node;

	if (!from || from->size == 0)
		return (0);
	node = from->first;
	from->first = node->next;
	if (from->first)
		from->first->prev = NULL;
	else
		from->last = NULL;
	from->size--;
	node->next = to->first;
	if (to->first)
		to->first->prev = node;
	else
		to->last = node;
	node->prev = NULL;
	to->first = node;
	to->size++;
	return (1);
}

void	push_a(t_head *pile_b, t_head *pile_a)
{
	if (push(pile_b, pile_a))
		printf("pa\n");
}

void	push_b(t_head *pile_a, t_head *pile_b)
{
	if (push(pile_a, pile_b))
		printf("pb\n");
}
