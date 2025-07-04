#include "push_swap.h"

void	hardcode_three(t_head *pile)
{
	int		f;
	int		s;
	int		t;
	int		max;

	f = pile->first->index;
	s = pile->first->next->index;
	t = pile->first->next->next->index;
	max = pile->size - 1;
	if (f == max - 2 && s == max - 1 && t == max - 3)
		return ;
	if (f == max - 2 && s == max && t == max - 1)
	{
		rotate_a(pile);
		swap_a (pile);
		reverse_rotate_a(pile);
	}
	if (f == max - 1 && s == max - 2 && t == max)
		swap_a(pile);
	if (f == max - 1 && s == max && t == max -2)
		reverse_rotate_a(pile);
	if (f == max && s == max - 1 && t == max -2)
	{
		swap_a(pile);
		reverse_rotate_a(pile);
}
	if (f == max && s == max -2 && t == max - 1)
		rotate_a(pile);
}

void	hardcode_three_bis(t_head *pile, int max)
{
	int		f;
	int		s;
	int		t;

	f = pile->first->index;
	s = pile->first->next->index;
	t = pile->first->next->next->index;
	if (f == max - 2 && s == max - 1 && t == max - 3)
		return ;
	if (f == max - 2 && s == max && t == max - 1)
	{
		rotate_a(pile);
		swap_a (pile);
		reverse_rotate_a(pile);
	}
	if (f == max - 1 && s == max - 2 && t == max)
		swap_a(pile);
	if (f == max - 1 && s == max && t == max -2)
		reverse_rotate_a(pile);
	if (f == max && s == max - 1 && t == max -2)
	{
		swap_a(pile);
		reverse_rotate_a(pile);
}
	if (f == max && s == max -2 && t == max - 1)
		rotate_a(pile);
}

void	hardcode_chunk_two(t_head *pile, int end)
{
	int		f;
	int		s;
	int		max;

	f = pile->first->index;
	s = pile->first->next->index;
	max = end;
	if (f == max - 1 && s == max) 
		return ;
	if (f == max && s == max - 1)
		swap_a(pile);
}

void	check_top_pile(t_head *pile, int end)
{
	int		f;
	int		s;
	int		max;

	f = pile->first->index;
	s = pile->first->next->index;
	max = end;
	if (s == max - 2) 
		swap_a(pile);
	if (f == max && s == max - 1)
		swap_a(pile);
}


void	hardcode_chunk_three(t_head *pile, int end)
{
	int		f;
	int		s;
	int		t;
	int		max;

	f = pile->first->index;
	s = pile->first->next->index;
	t = pile->first->next->next->index;
	max = end; 
	if (f == max - 2 && s == max - 1 && t == max - 3)
		return ;
	if (f == max - 2 && s == max && t == max - 1)
	{
		rotate_a(pile);
		swap_a (pile);
		reverse_rotate_a(pile);
	}
	if (f == max - 1 && s == max - 2 && t == max)
		swap_a(pile);
	if (f == max - 1 && s == max && t == max -2)
	{
		rotate_a(pile);
		swap_a(pile);
		reverse_rotate_a(pile);
		swap_a(pile);
	}
	if (f == max && s == max - 1 && t == max -2)
	{
		swap_a(pile);
		rotate_a(pile);
		swap_a(pile);
		reverse_rotate_a(pile);
		swap_a(pile);
	}
	if (f == max && s == max -2 && t == max - 1)
	{
		swap_a(pile);
		rotate_a(pile);
		swap_a(pile);
		reverse_rotate_a(pile);
	}
}

void	chunk_norisk(t_head *pile_a, t_head *pile_b)
{
	int		chunk;
	int		end;
	int		start;

	chunk = 3;
	end = pile_b->size - 1;
	while (end >= 0)
	{
		start = end - chunk + 1;
		ffind_pos_in_chunk(pile_a, pile_b, start, end);
		if (start == -2)
			return ;
		ffind_pos_in_chunk(pile_a, pile_b, start, end);
		if (start == - 1)
			return (hardcode_chunk_two(pile_a, end), (void)0);
		check_top_pile(pile_a, end);	
		ffind_pos_in_chunk(pile_a, pile_b, start, end);
		hardcode_chunk_three(pile_a, end);
		end = start - 1;
	}
}

void	simplus_sort(t_head *pile_a, t_head *pile_b)
{
	half_half(pile_a, pile_b);
	durotar(pile_a, pile_b);
	chunk_norisk(pile_a, pile_b);
}	

void	half_half(t_head *pile_a, t_head *pile_b)
{
	int		max;

	max = pile_a->size - 1;
	while (pile_a->size)
	{
		push_b(pile_a, pile_b);
		if (pile_b->first->index <= max / 2)
			rotate_b(pile_b);
	}
}

void	durotar(t_head *pile_a, t_head *pile_b)
{
	int		chunk;
	int		end;
	int		start;
	int		pos;

	chunk = 3;
	end = pile_b->size - 1;
	start = end - chunk + 1;
	pos = ffind_pos_in_chunk(pile_a, pile_b, start, end); 
	while (pos != -1)
		pos = ffind_pos_in_chunk(pile_a, pile_b, start, end);
	hardcode_three_bis(pile_a, end);
}

int	ffind_pos_in_chunk(t_head *pile_a, t_head *pile_b, int start, int end)
{
	int		pos_top;
	int		pos_bot;

	pos_top = ffind_pos_top(pile_b, start, end);
	pos_bot = ffind_pos_bot(pile_b, start, end);
	if (pos_top != -1 && pos_top <= pos_bot)
	{
		ffollow_instructions_t(pile_a, pile_b, pos_top);
		return (1);
	}
	else if (pos_bot != -1 && pos_bot < pos_top)
	{
		ffollow_instructions_b(pile_a, pile_b, pos_bot);
		return (1);
	}
	else
		return (-1);
}

int	ffind_pos_top(t_head *pile_b, int start, int end)
{
	t_node	*tmp;
	int		pos;

	tmp = pile_b->first;
	pos = 0;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (pos);
		++pos;
		tmp = tmp->next;
	}
	return (-1);
}

int	ffind_pos_bot(t_head *pile_b, int start, int end)
{
	t_node *tmp;
	int pos;

	tmp = pile_b->last;
	pos = 1;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= end)
			return (pos);
		++pos;
		tmp = tmp->prev;
	}
	return (-1);
} 

void	ffollow_instructions_t(t_head *pile_a, t_head *pile_b, int pos_top)
{
	while (pos_top--)
			rotate_b(pile_b);
	push_a(pile_b, pile_a);
}

void	ffollow_instructions_b(t_head *pile_a, t_head *pile_b, int pos_bot)
{
	while (pos_bot--)
			reverse_rotate_b(pile_b);
	push_a(pile_b, pile_a);
} 
