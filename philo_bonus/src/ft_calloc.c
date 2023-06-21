/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:58:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/21 16:58:50 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*tmp_ptr;
	int		tmp_res;
	int		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tmp_res = nmemb * size;
	if (tmp_res / size != nmemb)
		return (NULL);
	ptr = malloc(tmp_res);
	if (ptr == NULL)
		return (ptr);
	i = 0;
	tmp_ptr = ptr;
	while (i < tmp_res)
	{
		tmp_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
