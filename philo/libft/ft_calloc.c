/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:03:15 by gbricot           #+#    #+#             */
/*   Updated: 2023/06/12 15:03:32 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philo.h"

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
