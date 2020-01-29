/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 01:55:18 by sgah              #+#    #+#             */
/*   Updated: 2019/10/16 14:35:28 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*last;

	if (*alst && new)
	{
		last = *alst;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
	else if (!(*alst) && new)
		*alst = new;
}
