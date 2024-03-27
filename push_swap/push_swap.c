/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:06:33 by fhosgor           #+#    #+#             */
/*   Updated: 2024/03/27 15:58:04 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = ft_stacklen(av, 0);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.sizea = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free (stack.a);
		return ;
	}
	stack.sizeb = 0;
	while (++i < size)
		stack.a[i] = ft_psatoi(av[i], &stack, 0, 1);
	ft_checkdup(&stack, size, 0, 1);
	ft_sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int argc, char **av)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = 3;
	if (argc > 1)
	{
		if (argc > 2)
		{
			tmp2 = ft_strjoin(av[1], av[2]);
			while (argc != j)
			{
				tmp = ft_strjoin(tmp2, av[j++]);
				free(tmp2);
				tmp2 = tmp;
			}
			av = ft_split(tmp2, ' ');
		}
		else
			av = ft_split(*++av, ' ');
		if (!*av)
			return (write(2, "Error\n", 6));
		ft_push_swap(av);
	}
}
