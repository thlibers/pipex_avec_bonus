/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:48:37 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/21 16:13:13 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// int main()
// {
// 	t_list *node;
// 	t_list *tmp;

// 	node  = ft_lstnew("/100/");
// 	ft_lstadd_back(&node, ft_lstnew("/110/"));
// 	ft_lstadd_back(&node, ft_lstnew("/150/"));

// 	tmp = ft_lstlast(node);
// 	printf("last node : %s", (char *)tmp->content);
// 	return (0);
// }