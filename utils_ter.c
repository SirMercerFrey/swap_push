#include "push_swap.h"

int		count_words(char *str)
{
	int		count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_spaces(*str) && !in_word)
		{
			count += 1;
			in_word = 1;
		}
		if (is_spaces(*str))
			in_word = 0;
		++str;
	}
	return (count);
}

char	*extract_word(char *str)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] && !is_spaces(str[len]))
		++len;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[len] = '\0';
	return (word);
}

void	free_words(char **split, int i)
{
	while (i > 0)
	{
		--i;
		free (split[i]);
	}
	free(split);
}

char	**ft_split_by_space(char *str)
{
	int		words;
	int		i;
	char	**split;

	words = count_words(str);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str && is_spaces(*str))
			++str;
		split[i] = extract_word(str);
		if (!split[i])
		{
			free_words(split, i);
			return (NULL);
		}
		while (*str && !is_spaces(*str))
			++str;
		++i;
	}
	split[words] = NULL;
	return (split);
}

void	free_split(char **split)
{
	int	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}
