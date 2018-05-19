/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:22:37 by obamzuro          #+#    #+#             */
/*   Updated: 2018/05/16 13:58:40 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_putnbr_common(t_number *n, char base, char top, t_buffer *buff)
{
	intmax_t	j;
	int			a;
	char		*baseline;

	if (top)
		baseline = "FEDCBA9876543210123456789ABCDEF";
	else
		baseline = "fedcba9876543210123456789abcdef";
	j = 1;
	while (--(n->nbrsize))
		j *= base;
	while (j)
	{
		a = n->num / j % base;
		a = baseline[a + 15];
		pf_write(a, buff);
		j /= base;
	}
}

void		pf_uputnbr_common(t_unumber *n, char base, char top, t_buffer *buff)
{
	uintmax_t	j;
	int			a;
	char		*baseline;

	if (top)
		baseline = "0123456789ABCDEF";
	else
		baseline = "0123456789abcdef";
	j = 1;
	while (--(n->nbrsize))
		j *= base;
	while (j)
	{
		a = n->num / j % base;
		a = baseline[a];
		pf_write(a, buff);
		j /= base;
	}
}
