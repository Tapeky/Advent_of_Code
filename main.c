/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:05:27 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/04 15:49:28 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

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

int check_hitbox(char **input, int start, int end, int pos)
{
	int y = pos - 1;
	int index = 0;

	while (index < 3)
	{
		int x = start - 1;
		while (x <= end + 1)
		{
			printf("%c", input[y][x]);
			if ((!is_number(input[y][x])) && (input[y][x] != '.'))
			{
				printf(" %c, aaa", input[y][x]);
				return 1;
			}		
			x++;
		}
		y++;
		index++;
	}
	return 0;
}

int add_number(char **input, int start, int end, int pos)
{
	//printf("Je suis dans add_number\n");
	char	*number = NULL;
	int		sum = 0;

	number = (char *)malloc((end - start + 2) * sizeof(char));
	if (!number)
		return 0;
	int i = 0;
	for (int j = start; j <= end; j++)
	{
		number[i] = input[pos][j];
		i++;
	}
	number[i] = '\0';
	sum = ft_atoi(number);
	//printf("sum = %d      ", sum);
	free(number);
	return sum;
}


int main(void)
{
    char	**input;
    int		i;
	int		j;
	int		start;
	int		end;
	int		sum = 0;

    input = (char **)malloc(sizeof(char *) * 150);
    if (!input)
        return (0);
    input[150] = '\0';
	// On remplis notre tableau avec toutes les lignes de l'entrée standard
	i = 0;
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
				end = j - 1;
				printf("\n start = %d   end = %d\n", start, end);
				if (check_hitbox(input, start, end, i))
					sum += add_number(input, start, end, i);
			}
			j++;
		}
		//printf("%s", input[i]);
		i++;
	}
	printf("\nPart 1 : %d\n", sum);
    return (0);
}