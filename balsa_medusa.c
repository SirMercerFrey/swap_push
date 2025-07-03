#include "push_swap.h"

void	balsa_medusa(t_head *pile_a, t_head *pile_b)
{
	int		bits;
	int		i;

	bits = bit_size(pile_a);
	printf("bit_size = %d\n", bits);
	i = 0;
	while (i < bits)
	{
		if (i + 1 == bits)
			return (simple_radix(pile_a, pile_b, i), (void)0);
		movement_one(pile_a, pile_b, i);
		if (i + 2 == bits)
			return (push_back_a(pile_b, pile_a), (void)0);
//		printf("push back to b\n");
		push_back_b(pile_a, pile_b);
//		print_piles(pile_a, pile_b);
		if (i + 3 == bits)
			return (empty_reverse_radix(pile_a, pile_b, i), (void)0);
		movement_two(pile_a, pile_b, i);
		if (i + 4 == bits)
			return ;
		i += 4;
	}
}

void	simple_radix(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;
	int		tic;
	int		tac;

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
	tic = 16;
	while (tic--)
		push_b(pile_a, pile_b);
	tac = 16;
	while (tac--)
	{
		reverse_rotate_b(pile_b);
		push_a(pile_b, pile_a);
	}
}

void	movement_one(t_head *pile_a, t_head *pile_b, int i)
{
//	printf("push two bits zero\n");
	push_two_bits_zero_ab(pile_a, pile_b, i);
//	print_piles(pile_a, pile_b);
//	printf("push one bit zero\n");
	push_one_bit_zero_ab(pile_a, pile_b, i);
//	print_piles(pile_a, pile_b);
}

void	push_two_bits_zero_ab(t_head *pile_a, t_head *pile_b, int i)
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

void	push_one_bit_zero_ab(t_head *pile_a, t_head *pile_b, int i)
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
}

void	push_back_a(t_head *pile_b, t_head *pile_a)
{
	while (pile_b->first)
		push_a(pile_b, pile_a);
	finition(pile_a, pile_b);
//	print_piles(pile_a, pile_b);
}

void	push_back_b(t_head *pile_a, t_head *pile_b)
{
	while (pile_a->first)
		push_b(pile_a, pile_b);
}

void	empty_reverse_radix(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;

	size = pile_b->size;
	while (size--)
	{
		if ((pile_b->first->index >> (i + 2) & 1) == 1)
			push_a(pile_b, pile_a);
		else
			rotate_b(pile_b);
	}
	while (pile_b->first)
		push_a(pile_b, pile_a);
	finition(pile_a, pile_b);
}

void	movement_two(t_head *pile_a, t_head *pile_b, int i)
{
	int		count;

//	printf("push two bits one ba\n");
	count = push_two_bits_one_ba(pile_a, pile_b, i);
//	print_piles(pile_a, pile_b);
//	printf("push two bits one ba (bis)\n");
	push_two_bits_one_ba_bis(pile_a, pile_b, count);
//	printf("push two bits one ba (ter)\n");
	push_two_bits_one_ba_ter(pile_a, pile_b, i);
//	print_piles(pile_a, pile_b);

}

int		push_two_bits_one_ba(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;
	int		count;

	count = 0;
	size = pile_b->size;
	while (size--)
	{
		if ((pile_b->first->index >> (i + 3) & 1) == 1)
		{
			push_a(pile_b, pile_a);
			if ((pile_a->first->index >> (i + 2) & 1) == 0)
			{
				rotate_a(pile_a);
				++count;
			}
		}
		else
			rotate_b(pile_b);
	}
	return (count);
}

void	push_two_bits_one_ba_bis(t_head *pile_a, t_head *pile_b, int count)
{
	int		tmp;

	tmp = count;
	while (tmp--)
	{
		reverse_rotate_a(pile_a);
		push_b(pile_a, pile_b);
	}
//	printf("fisrt step\n");
//	print_piles(pile_a, pile_b);
	tmp = count;
//	printf("second step\n");
	while (tmp--)
		push_a(pile_b, pile_a);
//	print_piles(pile_a, pile_b);
}

void	push_two_bits_one_ba_ter(t_head *pile_a, t_head *pile_b, int i)
{
	int		size;

	size = pile_b->size;
	while (size--)
	{
		if ((pile_b->first->index >> (i + 2) & 1) == 1)
			push_a(pile_b, pile_a);
		else
			rotate_b(pile_b);
	}
	size = pile_b->size;
	while (size--)
		push_a(pile_b, pile_a);
}

void	finition(t_head *pile_a, t_head *pile_b)
{
	int		tic;
	int		tac;

	tic = 16;
	tac = 16;
	while (pile_b->first)
		push_a(pile_b, pile_a);
	tic = 16;
	while (tic--)
		push_b(pile_a, pile_b);
	tac = 16;
	while (tac--)
	{
		reverse_rotate_b(pile_b);
		push_a(pile_b, pile_a);
	}
}
	
