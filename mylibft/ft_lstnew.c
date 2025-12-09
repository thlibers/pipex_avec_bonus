/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlibers <thlibers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:19:05 by thlibers          #+#    #+#             */
/*   Updated: 2025/10/21 16:13:20 by thlibers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*noeud;

	noeud = malloc(sizeof(t_list));
	if (noeud == NULL)
		return (NULL);
	noeud->content = content;
	noeud->next = NULL;
	return (noeud);
}

// int main()
// {
// 	t_list *test;

// 	test = ft_lstnew("/salut/");
// 	printf ("new node content = %s", (char *)test->content);
// 	return (0);
// }