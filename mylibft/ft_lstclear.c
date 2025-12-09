/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:45:31 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/22 13:11:01 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void del(void *c)
// {
// 	free(c);
// 	printf("%s\n", "free");
// }

// // void del(void *c)
// // {
// // 	char *s = (char *)c;

// // 	s = "00";
// // 	printf("%s\n", s);
// // }

// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = ft_lstnew(ft_strdup("/1/"));
// 	node2 = ft_lstnew(ft_strdup("/2/"));
// 	node3 = ft_lstnew(ft_strdup("/3/"));
// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	ft_lstadd_back(&lst, node3);

// 	// while(lst)
// 	// {
// 	// 	printf("old content : %s\n", (char *)lst->content);
// 	// 	lst = lst->next;
// 	// }
// 	// lst = NULL;
// 	ft_lstclear(&lst, del);
// 	// while(lst)
// 	// {
// 	// 	printf("new content :%s\n", (char *)lst->content);
// 	// 	lst = lst->next;
// 	// }
// 	return (0);
// }