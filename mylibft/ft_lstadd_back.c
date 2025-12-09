/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:01:12 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/22 10:59:26 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = ft_lstnew("bien");
// 	node2 = ft_lstnew("cava");
// 	node3 = ft_lstnew("salut");
// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	ft_lstadd_back(&lst, node3);
// 	while(lst)
// 	{
// 		printf("%s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// 	return (0);
// }