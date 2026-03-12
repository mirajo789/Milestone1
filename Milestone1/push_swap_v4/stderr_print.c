/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stderr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 08:34:52 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:30:21 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	stderr_str(char *s)
{
	ft_putstr_fd(s, 2);
}

void	stderr_nbr(int n)
{
	ft_putnbr_fd(n, 2);
}
