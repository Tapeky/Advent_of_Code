/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:27 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/04 13:49:08 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sum;

	sum = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
			return (sum * sign);
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum * sign);
}

int is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_hitbox(char **input, int start, int end, int pos)
{
	int x = start - 1;
	int y = pos - 1;
	int index = 0;

	while (index < 3)
	{
		while (input[y][x] != '\n')
		{
			if (input[y][x] == input[pos][start])
				x += (end - start) + 1;
			else if (input[y][x] != '.')
				return (1);
			x++;
		}
		y++;
		index++;
	}
	return (0);
}

int add_number(char **input, int start, int end, int pos)
{
	char	*number = 0;
	int		sum = 0;

	number = ft_calloc(end - start + 1, sizeof(char));
	if (!number)
		return (0);
	while (start < end)
	{
		number[start] = input[pos][start];
		start++;
	}
	sum = ft_atoi(number);
	return (sum);
}


int main(void)
{
    char	**input;
    int		i;
	int		j;
	int		start;
	int		end;
	int		sum;

    input = (char **)malloc(sizeof(char *) * 10);
    if (!input)
        return (0);
    input[10] = '\0';
    i = 0;

	// On remplis notre tableau avec toutes les lignes de l'entrée standard
	while (input[i] = get_next_line(0)) 
		i++;
	i = 0;
	while (input[i])
	{
		j = 0;
		start = 0;
		end = 0;
		while (input[i][j])
		{
			if (is_number(input[i][j]))
			{
				start = j;
				while (is_number(input[i][j]))
					j++;
				end = j;
				if (check_hitbox(input, start, end, i))
					sum += add_number(input, start, end, i);
			}
			j++;
		}
		i++;
	}
	printf("Part 1 : %d\n", sum);
    return (0);
}