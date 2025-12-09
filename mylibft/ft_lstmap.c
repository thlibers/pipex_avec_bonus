/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:38:49 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/22 12:11:58 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
			return (ft_lstclear(&newlist, del), NULL);
		newnode = ft_lstnew(newcontent);
		if (!newnode)
		{
			del(newcontent);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}

// void *f(void *c)
// {
// 	char *cc;
// 	char *s;
// 	int i;
// 	int len;

// 	cc = (char *)c;
// 	len = ft_strlen(s);
// 	s = malloc(len + 1);
// 	i = 0;
// 	while (cc[i])
// 	{
// 		if (cc[i] >= 'a' && cc[i] <= 'z')
// 			s[i] = cc[i] - 32;
// 		else
// 			s[i] = cc[i];
// 		i++;
// 	}
// 	s[i] = '\0';
// 	return ((void *)s);
// }

// void del(void *c)
// {
// 	free(c);
// }

// int main()
// {
// 	t_list *lst = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	t_list *node4;
// 	t_list *node5;

// 	node1 = ft_lstnew("c");
// 	node2 = ft_lstnew("a");
// 	node3 = ft_lstnew("v");
// 	node4 = ft_lstnew("a");
// 	node5 = ft_lstnew("?");
// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	ft_lstadd_back(&lst, node3);
// 	ft_lstadd_back(&lst, node4);
// 	ft_lstadd_back(&lst, node5);

// 	t_list *newlist = ft_lstmap(lst, f, del);
// 	while(newlist)
// 	{
// 		printf("%s\n", (char *)newlist->content);
// 		newlist = newlist->next;
// 	}
// 	return (0);
// }