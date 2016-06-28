/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:57:35 by gmorer            #+#    #+#             */
/*   Updated: 2016/01/04 16:20:13 by gmorer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int unsigned	i;

	i = 0;
	if (s && *s && f && *f)
	{
		while (*s)
		{
			f(i++, s++);
		}
	}
}