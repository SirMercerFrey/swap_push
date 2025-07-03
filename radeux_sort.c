#include "push_swap.h"

/*void	radeux_sort(t_head *pile_a, t_head *pile_b)
{
	int		bits;
	int		i;

	bits = bit_size(pile_a);
//	printf("bits = %d\n", bits);
	i = 0;
	while (i + 1 < bits)
	{
//		printf("first step\n");
		first_step(pile_a, pile_b, i);
	//	print_piles(pile_a, pile_b);
	//	printf("second step\n");
		second_step(pile_a, pile_b, i);
	//	print_piles(pile_a, pile_b);
		i += 2;
	}
	if (bits % 2 == 1)
	{
	//	printf("last second step\n");
		second_step(pile_a, pile_b, i);
	//	print_piles(pile_a, pile_b);
	}
}*/

int	bit_size(t_head *pile_a)
{
	int		bits;

	bits = 0;
	while ((pile_a->size - 1) >> bits != 0)
		++bits;
	return (bits);
}

/*void	first_step(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;

	size = pile_a->size;
	while (size--)
	{
		if ((pile_a->first->index >> (i + 1) & 1) == 0)
		{
			push_b(pile_a, pile_b);
			if ((pile_b->first->index >> i & 1) == 0)
				rotate_b(pile_b);
		}
		else
			rotate_a(pile_a);
	}
}

void	second_step(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;

	size = pile_a->size;
	while (size--)
	{
		if ((pile_a->first->index >> i & 1) == 0)
			push_b(pile_a, pile_b);
		else
			rotate_a(pile_a);
	}
	while (pile_b->first)
		push_a(pile_b, pile_a);
}*/

void	radeux_sort(t_head *pile_a, t_head *pile_b)
{
	first_step(pile_a, pile_b);
	radix_classic(pile_a, pile_b);
}

void	first_step(t_head *pile_a, t_head *pile_b)
{
	push_bit_zero(pile_a, pile_b, 1);
	push_bit_zero(pile_a, pile_b, 0);
	while (pile_a->first)
		push_b(pile_a, pile_b);
	radix_third_bit(pile_a, pile_b);
}

void	push_bit_zero(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;

	size = pile_a->size;
	while (size--)
	{
		if ((pile_a->first->index >> i & 1) == 0)
		{
			push_b(pile_a, pile_b);
			if (i > 0 && ((pile_b->first->index >> (i - 1) & 1) == 0))
				rotate_b(pile_b);
		}
		else
			rotate_a(pile_a);
	}
}

void	radix_third_bit(t_head *pile_a, t_head *pile_b)
{
	int		size;

	size = pile_b->size;
	while (size--)
	{
		if ((pile_b->first->index >> 2 & 1) == 1)
			push_a(pile_b, pile_a);
		else
			rotate_b(pile_b);
	}
	while (pile_b->first)
		push_a(pile_b, pile_a);
}

void	radix_classic(t_head *pile_a, t_head *pile_b)
{
	int		bits;
	int		size;
	int		i;

	i = 3;
	bits = bit_size(pile_a);
	while (i < bits)
	{
		size = pile_a->size;
		while (size--)
		{
			if ((pile_a->first->index >> i & 1) == 0)
				push_b(pile_a, pile_b);
			else
				rotate_a(pile_a);
		}
		while (pile_b->first)
			push_a(pile_b, pile_a);
		++i;
	}
}

void	radix_sort(t_head *pile_a, t_head *pile_b)
{
	int		bits;
	int		size;
	int		i;

	i = 0;
	bits = bit_size(pile_a);
	while (i < bits)
	{
		size = pile_a->size;
		while (size--)
		{
			if ((pile_a->first->index >> i & 1) == 0)
				push_b(pile_a, pile_b);
			else
				rotate_a(pile_a);
		}
		while (pile_b->first)
			push_a(pile_b, pile_a);
		++i;
	}
}
