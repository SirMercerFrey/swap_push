#include "push_swap.h"

void	swap(t_head *pile)
{
	t_node	*first;
	t_node	*second;

	if (!pile || pile->size < 2)
		return ;
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
}

void	swap_a(t_head *pile_a)
{
	swap(pile_a);
	printf("sa\n");
}

void	swap_b(t_head *pile_b)
{
	swap(pile_b);
	printf("sb\n");
}

void	swap_both(t_head *pile_a, t_head *pile_b)
{
	swap(pile_a);
	swap(pile_b);
	printf("ss\n");
}

void	push(t_head *from, t_head *to)
{
	t_node	*node;

	if (!from || from->size == 0)
		return ;
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
}

void	push_a(t_head *pile_b, t_head *pile_a)
{
	push(pile_b, pile_a);
	printf("pa\n");
}

void	push_b(t_head *pile_a, t_head *pile_b)
{
	push(pile_a, pile_b);
	printf("pb\n");
}
