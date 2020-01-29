/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:25:23 by sgah              #+#    #+#             */
/*   Updated: 2019/10/16 00:21:35 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*first;
	t_list	*the_one;

	if (!f && !lst)
		return (NULL);
	if (!(first = ft_lstnew(f(lst->content))))
		return (NULL);
	the_one = first;
	lst = lst->next;
	while (lst)
	{
		if (!(the_one->next = ft_lstnew(f(lst->content))))
			return (NULL);
		the_one = the_one->next;
		lst = lst->next;
	}
	return (first);
}
