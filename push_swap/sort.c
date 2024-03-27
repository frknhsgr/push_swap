/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:05 by fhosgor           #+#    #+#             */
/*   Updated: 2024/02/19 15:31:16 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tmp(int *tmps, int size)
{
	int	i;
	int	n;
	int	tmp;

	i = 0;
	while (i < size)
	{
		n = i + 1;
		while (n < size)
		{
			if (tmps[i] > tmps[n])
			{
				tmp = tmps[i];
				tmps[i] = tmps[n];
				tmps[n] = tmp;
			}
			n++;
		}
		i++;
	}
}

void	ft_sort3(t_stack *st)
{
	if (st->a[0] > st->a[1] && st->a[0] < st->a[2] && st->a[1] < st->a[2])
		ft_sa(st);
	if (st->a[0] > st->a[1] && st->a[0] > st->a[2] && st->a[1] > st->a[2])
	{
		ft_sa(st);
		ft_rra(st);
	}
	if (st->a[0] > st->a[1] && st->a[0] > st->a[2] && st->a[1] < st->a[2])
		ft_ra(st);
	if (st->a[0] < st->a[1] && st->a[0] < st->a[2] && st->a[1] > st->a[2])
	{
		ft_sa(st);
		ft_ra(st);
	}
	if (st->a[0] < st->a[1] && st->a[0] > st->a[2] && st->a[1] > st->a[2])
		ft_rra(st);
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_checks(stack->a, stack->sizea, 0) == 0)
	{
		if (size == 2)
			ft_sa(stack);
		else if (size == 3)
			ft_sort3(stack);
		else
			ft_qsa(stack, size, 0, 0);
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, char c)
{
	if (c == 'a')
		ft_pa(stack);
	else
		ft_pb(stack);
	len--;
	return (len);
}
