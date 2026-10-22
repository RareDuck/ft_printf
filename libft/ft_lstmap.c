/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:18:03 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/29 00:24:37 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*safe_lstnew_f(t_list *lst, void *(*f)(void *))
{
	t_list	*new_lst;
	void	*content;

	content = f((*lst).content);
	if (content == NULL)
		return (NULL);
	new_lst = ft_lstnew(content);
	if (new_lst == NULL)
	{
		free(content);
		return (NULL);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new = safe_lstnew_f(lst, f);
	if (new == NULL)
		return (NULL);
	lst = (*lst).next;
	while (lst != NULL)
	{
		temp = safe_lstnew_f(lst, f);
		if (temp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = (*lst).next;
	}
	return (new);
}
