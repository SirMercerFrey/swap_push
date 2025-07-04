#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_head	*pile_a;
	t_head	*pile_b;
	int		*tab;

	pile_a = create_pile();
	pile_b = create_pile();
	if (argc < 2)
		return (printf("\n"));
	preambule(argc, argv, pile_a);
	tab = create_tab(pile_a);
	quick_sort(tab, 0, pile_a->size - 1);
	give_index(pile_a, tab);
	if (check_doublons(pile_a))
		return (printf("Error\n"));
//	print_piles(pile_a, pile_b);
//	chunk_sort(pile_a, pile_b);
//	radeux_sort(pile_a, pile_b);
//	radix_sort(pile_a, pile_b);
//	balsa_medusa(pile_a, pile_b);
//	gab_sort(pile_a, pile_b);
	simplus_sort(pile_a, pile_b);
//	hardcode_three(pile_a);
//	print_piles(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
