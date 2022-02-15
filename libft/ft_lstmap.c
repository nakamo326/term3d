/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totaisei <totaisei@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 00:01:02 by totaisei          #+#    #+#             */
/*   Updated: 2022/02/15 19:59:26 by totaisei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*target;
	t_list	*res;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	res = ft_lstnew((*f)(lst->content));
	if (!res)
		return (NULL);
	target = lst->next;
	while (target)
	{
		tmp = ft_lstnew((*f)(target->content));
		if (!tmp)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		target = target->next;
	}
	return (res);
}
