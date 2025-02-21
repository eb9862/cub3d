/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:15 by eunhwang          #+#    #+#             */
/*   Updated: 2024/02/29 21:42:12 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	putnbr_fd_positive(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	putnbr_fd_positive(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static void	putnbr_fd_negative(int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	putnbr_fd_negative(n / 10, fd);
	c = (n % 10) * (-1) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n > 0)
		putnbr_fd_positive(n, fd);
	else
	{
		write(fd, "-", 1);
		putnbr_fd_negative(n, fd);
	}
}

/*int main(void)
{
	int fd = 1;
	int n = -2147483648;
	ft_putnbr_fd(n, fd);
}*/
