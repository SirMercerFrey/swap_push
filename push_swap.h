#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_head
{
	struct s_node	*first;
	struct s_node	*last;
	int				size;
}				t_head;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				val;
	int				index;
}				t_node;

t_head	*create_pile(void);
t_node	*create_element(int val);
void	ft_lst_add_back(t_head **pile, t_node *elem);
void	print_piles(t_head *pile_a, t_head *pile_b);
void	free_pile(t_head *pile);
int	is_spaces(char c);
int is_operator(char c);
int ft_atoi(char *str);
int	count_words(char *str);
char	*extract_word(char *str);
void	free_words(char **split, int i);
char    **ft_split_by_space(char *str);
void    free_split(char **split);  
int is_valid_number(char *str);
void	preambule(int argc, char **argv, t_head *pile_a);
void	swap_int(int *a, int *b);
int	partition(int *tab, int start, int end);
void	quick_sort(int *tab, int start, int end);
int	*create_tab(t_head *pile);
void give_index(t_head *pile, int *tab);
int	check_doublons(t_head *pile);
int    swap(t_head *pile);
void    swap_a(t_head *pile_a);
void    swap_b(t_head *pile_b);
void    swap_both(t_head *pile_a, t_head *pile_b);
int    push(t_head *from, t_head *to);
void    push_a(t_head *pile_b, t_head *pile_a);
void    push_b(t_head *pile_a, t_head *pile_b);
int	rotate(t_head *pile);
void	rotate_a(t_head *pile_a);
void	rotate_b(t_head *pile_b);
void	rotate_both(t_head *pile_a, t_head *pile_b);
int    reverse_rotate(t_head *pile);
void    reverse_rotate_a(t_head *pile_a);
void    reverse_rotate_b(t_head *pile_b);
void    reverse_rotate_both(t_head *pile_a, t_head *pile_b);
void    chunk_sort(t_head *pile_a, t_head *pile_b);
int is_in_chunk(t_node *node, int start, int end);
int chunk_size(t_head *pile_a);
int find_pos_in_chunk(t_head *pile_a, t_head *pile_b, int start, int end);
int find_pos_top(t_head *pile_a, int start, int end);
int find_pos_bot(t_head *pile_a, int start, int end);
void    follow_instructions_t(t_head *pile_a, t_head *pile_b, int start, int end, int pos_top);
void    follow_instructions_b(t_head *pile_a, t_head *pile_b, int start, int end, int pos_bot);
void    find_path_max(t_head *pile_a, t_head *pile_b);
int find_path_des(t_head *pile_b);
int find_path_asc(t_head *pile_b);
void    follow_instructions_d(t_head *pile_a, t_head *pile_b, int path_des);
void    follow_instructions_a(t_head *pile_a, t_head *pile_b, int path_asc);
int find_epo(t_head *pile_a, int end_plus_one);
int find_pos_epo(t_head *pile_a, int end_plus_one);
void    follow_instructions_tepo(t_head *pile_a, int pos_top);
void    follow_instructions_bepo(t_head *pile_a, int pos_bot);
void    radeux_sort(t_head *pile_a, t_head *pile_b);
int	bit_size(t_head *pile_a);
//void    first_step(t_head *pile_a, t_head *pile_b, int i);
//void    second_step(t_head *pile_a, t_head *pile_b, int i);
void    radeux_sort(t_head *pile_a, t_head *pile_b);
void    first_step(t_head *pile_a, t_head *pile_b);
void    push_bit_zero(t_head *pile_a, t_head *pile_b, int i);
void    radix_third_bit(t_head *pile_a, t_head *pile_b);
void    radix_classic(t_head *pile_a, t_head *pile_b);
void    radix_sort(t_head *pile_a, t_head *pile_b);
void    balsa_medusa(t_head *pile_a, t_head *pile_b);
void    simple_radix(t_head *pile_a, t_head *pile_b, int i);
void    movement_one(t_head *pile_a, t_head *pile_b, int i);
void    push_two_bits_zero_ab(t_head *pile_a, t_head *pile_b, int i);
void    push_one_bit_zero_ab(t_head *pile_a, t_head *pile_b, int i);
void    push_back_a(t_head *pile_a, t_head *pile_b);
void    push_back_b(t_head *pile_a, t_head *pile_b);
void    empty_reverse_radix(t_head *pile_a, t_head *pile_b, int i);
void    movement_two(t_head *pile_a, t_head *pile_b, int i);
int     push_two_bits_one_ba(t_head *pile_a, t_head *pile_b, int i);
void    push_two_bits_one_ba_bis(t_head *pile_a, t_head *pile_b, int count);
void    push_two_bits_one_ba_ter(t_head *pile_a, t_head *pile_b, int i);
void    finition(t_head *pile_a, t_head *pile_b);
void    gab_sort(t_head *pile_a, t_head *pile_b);
void    first_phase(t_head *pile_a, t_head *pile_b);
int *create_tmp_tab(t_head *pile);
int calculate_median(int *tab, t_head *pile);
void    second_phase(t_head *pile_a, t_head *pile_b);
void	print_tab(int *tab, int size);

void    hardcode_three(t_head *pile);
void	hardcode_three_bis(t_head *pile, int max);
void    hardcode_chunk_two(t_head *pile, int end);
void    check_top_pile(t_head *pile, int end);
void    hardcode_chunk_three(t_head *pile, int end);
void    chunk_norisk(t_head *pile_a, t_head *pile_b);
void    simplus_sort(t_head *pile_a, t_head *pile_b);
void    half_half(t_head *pile_a, t_head *pile_b);
void    durotar(t_head *pile_a, t_head *pile_b);
int ffind_pos_in_chunk(t_head *pile_a, t_head *pile_b, int start, int end);
int ffind_pos_top(t_head *pile_b, int start, int end);
int ffind_pos_bot(t_head *pile_b, int start, int end);
void    ffollow_instructions_t(t_head *pile_a, t_head *pile_b, int pos_top);
void    ffollow_instructions_b(t_head *pile_a, t_head *pile_b, int pos_bot);

#endif
