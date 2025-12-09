/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:41:44 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/22 12:45:01 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	count = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = ft_lstnew("..1..");
// 	node2 = ft_lstnew("..2..");
// 	node3 = ft_lstnew("..3..");
// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	ft_lstadd_back(&lst, node3);
// 	printf("nb de node = %d\n", ft_lstsize(lst));
// 	// while(lst)
// 	// {
// 	// 	printf("%s\n", (char *)lst->content);
// 	// 	lst = lst->next;
// 	// }
// 	return (0);
// }