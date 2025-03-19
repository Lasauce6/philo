/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:18:40 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/17 12:04:22 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static inline bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static const char	*valid_input(const char *str, t_data *data)
{
	int			len;
	const char	*nbr;

	len = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-')
		error_exit("Only positive numbres are allowed\n", data);
	if (!ft_isdigit(*str))
		error_exit("Input is invalid\n", data);
	nbr = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		error_exit("Value to big\n", data);
	return (nbr);
}

int	ft_atoi(const char *str, t_data *data)
{
	size_t	i;
	long	n;
	int		sign;

	str = valid_input(str, data);
	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - '0';
	return (n * sign);
}

long	ft_atol(const char *str, t_data *data)
{
	long	nb;

	nb = 0;
	str = valid_input(str, data);
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*str++ - 48);
	if (nb > INT_MAX)
		error_exit("Value to big\n", data);
	return (nb);
}
