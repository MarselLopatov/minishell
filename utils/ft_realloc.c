#include "../includes/minishell.h"

void	*ft_realloc(void *old, size_t new_size)
{
	void	*new;
	size_t	i;

	new = malloc(new_size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		((char *)new)[i] = ((char *)old)[i];
		i++;
	}
	free(old);
	return (new);
}
