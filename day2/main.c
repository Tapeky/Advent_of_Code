/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:53:57 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/03 23:55:34 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int is_valid(char *line)
{
	int i = 0;
	int red = 0;
	int green = 0;
	int blue = 0;

	while (line[i] != ':')
		i++;
	i += 2;
	while (line[i] != '\0')
	{
		if (is_number(line[i]) && is_number(line[i + 1]))
		{
			if (line[i + 3] == 'g')
			{
				green = ((line[i] - '0') * 10) + (line[i + 1] - '0');
				printf("green: %d\n", green);
			}
			else if (line[i + 3] == 'r')
				red = ((line[i] - '0') * 10) + (line[i + 1] - '0');
			else if (line[i + 3] == 'b')
				blue = ((line[i] - '0') * 10) + (line[i + 1] - '0');
		}
		else if (is_number(line[i]) && !is_number(line[i - 1]))
		{
			if (line[i + 2] == 'g')
			{
				green = line[i] - '0';
				printf("green: %d\n", green);
			}
			else if (line[i + 2] == 'r')
				red = line[i] - '0';
			else if (line[i + 2] == 'b')
				blue = line[i] - '0';
		}
		if (line[i] == ';')
		{
			if (red > 12 || green > 13 || blue > 14)
				return (0);
			else
				red = 0, green = 0, blue = 0;
		}
		i++;
	}
	return (red <= 12 && green <= 13 && blue <= 14);
}

int part2(char *line)
{
	int i = 0;
	int red = 0;
	int green = 0;
	int blue = 0;

	while (line[i] != ':')
		i++;
	i += 2;
	while (line[i] != '\0')
	{
		if (is_number(line[i]) && is_number(line[i + 1]))
		{
			if (line[i + 3] == 'g')
				green = (((line[i] - '0') * 10) + (line[i + 1] - '0')) > green ? ((line[i] - '0') * 10) + (line[i + 1] - '0') : green;
			else if (line[i + 3] == 'r')
				red = (((line[i] - '0') * 10) + (line[i + 1] - '0')) > red ? ((line[i] - '0') * 10) + (line[i + 1] - '0') : red;
			else if (line[i + 3] == 'b')
				blue = (((line[i] - '0') * 10) + (line[i + 1] - '0')) > blue ? ((line[i] - '0') * 10) + (line[i + 1] - '0') : blue;
		}
		else if (is_number(line[i]) && !is_number(line[i - 1]))
		{
			if (line[i + 2] == 'g')
				green = (line[i] - '0') > green ? line[i] - '0' : green;
			else if (line[i + 2] == 'r')
				red = (line[i] - '0') > red ? line[i] - '0' : red;
			else if (line[i + 2] == 'b')
				blue = (line[i] - '0') > blue ? line[i] - '0' : blue;
		}
		i++;
	}
	return (red * green * blue);
}

int main()
{
	char *line;
	int i = 1;
	int sum = 0;
	int res_part2 = 0;

	while ((line = get_next_line(0)))
	{
		if (is_valid(line))
		{
			printf("%s\n", line);
			sum += i;
		}
		res_part2 += part2(line);
		free(line);
		i++;
	}
	printf("Result Part 1 = %d\n", sum);
	printf("Result Part 2 = %d\n", res_part2);
    return (0);
}
