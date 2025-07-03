#include "push_swap.h"

void	chunk_sort(t_head *pile_a, t_head *pile_b)
{
	int		chunk;
	int		end;
	int		start;
	int		pos;

	chunk = chunk_size(pile_a);
	end = pile_a->size - 1;
	while (end >= 0)
	{
		start = end - chunk + 1;
		if (start < 0)
			start = 0;
		pos = find_pos_in_chunk(pile_a, pile_b, start, end);
		while (pos != -1)
			pos = find_pos_in_chunk(pile_a, pile_b, start, end);
		if (find_epo(pile_a, end + 1))
			pos = find_pos_epo(pile_a, end + 1); 
		while (pile_b->size)
			find_path_max(pile_a, pile_b);
		end = start - 1;
	}
}

int	is_in_chunk(t_node *node, int start, int end)
{
	return (node->index >= start && node->index <= end);
}

int chunk_size(t_head *pile_a)
{
    if (pile_a->size >= 500)
        return (pile_a->size / 20);
    else if (pile_a->size >= 100)
        return (pile_a->size / 4);
	else 
		return (1);
}

int	find_pos_in_chunk(t_head *pile_a, t_head *pile_b, int start, int end)
{
	int		pos_top;
	int		pos_bot;

	pos_top = find_pos_top(pile_a, start, end);
	pos_bot = find_pos_bot(pile_a, start, end);
	if (pos_top != -1 && pos_top <= pos_bot)
	{
		follow_instructions_t(pile_a, pile_b, start, end, pos_top);
		return (1);
	}
	else if (pos_bot != -1 && pos_bot < pos_top)
	{
		follow_instructions_b(pile_a, pile_b, start, end, pos_bot);
		return (1);
	}
	else
		return (-1);
}

int	find_pos_top(t_head *pile_a, int start, int end)
{
	t_node	*tmp;
	int		pos;

	tmp = pile_a->first;
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

int	find_pos_bot(t_head *pile_a, int start, int end)
{
	t_node *tmp;
	int pos;

	tmp = pile_a->last;
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

void	follow_instructions_t(t_head *pile_a, t_head *pile_b, int start, int end, int pos_top)
{
	while (pos_top--)
	{
		if (pile_b->first && pile_b->first->index <= (start + end) / 2)
			rotate_both(pile_a, pile_b);
		else
			rotate_a(pile_a);
	}
	push_b(pile_a, pile_b);
}

void	follow_instructions_b(t_head *pile_a, t_head *pile_b, int start, int end, int pos_bot)
{
	while (pos_bot--)
	{
		if (pile_b->last && pile_b->last->index > (start + end) / 2)
			reverse_rotate_both(pile_a, pile_b);
		else
			reverse_rotate_a(pile_a);
	}
	push_b(pile_a, pile_b);
} 

void	find_path_max(t_head *pile_a, t_head *pile_b)
{
	int		path_des;
	int		path_asc;

	path_des = find_path_des(pile_b);
	path_asc = find_path_asc(pile_b);
	if (path_des != -1 && path_des <= path_asc)
		follow_instructions_d(pile_a, pile_b, path_des);
	else if (path_asc != -1 && path_asc < path_des)
		follow_instructions_a(pile_a, pile_b, path_asc);
}

int	find_path_des(t_head *pile_b)
{
	t_node *tmp;
	int		pos;
	int		pos_max;
	int		max;

	tmp = pile_b->first;
	max = -1;
	pos = 0;
	pos_max = -1;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos_max = pos;
		}
		++pos;
		tmp = tmp->next;
	}
	return (pos_max);
}

int	find_path_asc(t_head *pile_b)
{
	t_node *tmp;
	int		pos;
	int 	pos_max;
	int		max;

	tmp = pile_b->last;
	max = -1;
	pos = 1;
	pos_max = -1;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			pos_max = pos;
		}
		++pos;
		tmp = tmp->prev;
	}
	return (pos_max);
}

void	follow_instructions_d(t_head *pile_a, t_head *pile_b, int path_des)
{
	if (path_des == 1)
	{
		swap_b(pile_b);
		push_a(pile_b, pile_a);
	}
	else
	{
		while (path_des--)
			rotate_b(pile_b);
		push_a(pile_b, pile_a);
	}
}

void	follow_instructions_a(t_head *pile_a, t_head *pile_b, int path_asc)
{
	while (path_asc--)
		reverse_rotate_b(pile_b);
	push_a(pile_b, pile_a);
}

int	find_epo(t_head *pile_a, int end_plus_one)
{
	t_node	*tmp;

	tmp = pile_a->first;
	while (tmp)
	{
		if (tmp->index == end_plus_one)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_pos_epo(t_head *pile_a, int end_plus_one)
{
	int		pos_top;
	int		pos_bot;

	pos_top = find_pos_top(pile_a, end_plus_one, end_plus_one);
	pos_bot = find_pos_bot(pile_a, end_plus_one, end_plus_one);
	if (pos_top != -1 && pos_top <= pos_bot)
	{
		follow_instructions_tepo(pile_a, pos_top);
		return (1);
	}
	else if (pos_bot != -1 && pos_bot < pos_top)
	{
		follow_instructions_bepo(pile_a, pos_bot);
		return (1);
	}
	else
		return (-1);
}

void	follow_instructions_tepo(t_head *pile_a, int pos_top)
{
	while (pos_top--)
			rotate_a(pile_a);
}

void	follow_instructions_bepo(t_head *pile_a, int pos_bot)
{
	while (pos_bot--)
			reverse_rotate_a(pile_a);
} 
