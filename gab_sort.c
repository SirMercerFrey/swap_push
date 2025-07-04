#include "push_swap.h"

void	gab_sort(t_head *pile_a, t_head *pile_b)
{
	push_b(pile_a, pile_b);
	first_phase(pile_a, pile_b);
	while (pile_b->size)
		push_a(pile_b, pile_a);
	push_b(pile_a, pile_b);
	first_phase(pile_a, pile_b);
	second_phase(pile_a, pile_b);
}

void	first_phase(t_head *pile_a, t_head *pile_b)
{
	int		*tab_tmp;
	int		median;

	while (pile_a->size)
	{
		tab_tmp = create_tmp_tab(pile_b);
		quick_sort(tab_tmp, 0, pile_b->size - 1);
		print_tab(tab_tmp, pile_b->size);
		if (tab_tmp)
			median = calculate_median(tab_tmp, pile_b);
		push_b(pile_a, pile_b);
		if (tab_tmp && pile_b->first->index < median)
			rotate_b(pile_b);
		print_piles(pile_a, pile_b);
		free(tab_tmp);
	}
}

int *create_tmp_tab(t_head *pile)
{
    int     *tab;
    int     i;  
    t_node  *tmp;

    if (!pile)
        return (NULL);
    tab = malloc(sizeof(int) * pile->size);
    if (!tab)
        return (NULL);
    tmp = pile->first;
    i = 0;
    while (tmp && i < pile->size)
    {   
        tab[i] = tmp->index;
        tmp = tmp->next;
        ++i;
    }   
    return (tab);
}

int	calculate_median(int *tab, t_head *pile)
{
	int		median;
	int		size;

	size = pile->size;
	if (size % 2 == 1)
		median = tab[size / 2];
	else
	{
		median = tab[size / 2] + tab[size / 2 + 1] ; 
		median /= 2;
	}
	printf("median = %d\n", median);
	return (median);
}

void	second_phase(t_head *pile_a, t_head *pile_b)
{
	while (pile_b->size)
		find_path_max(pile_a, pile_b);
}	

void	print_tab(int *tab, int size)
{
	int		i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i != size - 1)
			printf(", ");
		++i;
	}
	printf("]\n");
}
