#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((str1[i] == str2[i]) && (i < n) && str1[i] && str2[i])
	{
		if (i == n - 1)
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

void char_to_digit(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (!ft_strncmp(line + i, "one", 3))
			line[i+1] = '1';
		else if (!ft_strncmp(line + i, "two", 3))
			line[i+1] = '2';
		else if (!ft_strncmp(line + i, "three", 5))
			line[i+1] = '3';
		else if (!ft_strncmp(line + i, "four", 4))
			line[i+1] = '4';
		else if (!ft_strncmp(line + i, "five", 4))
			line[i+1] = '5';
		else if (!ft_strncmp(line + i, "six", 3))
			line[i+1] = '6';
		else if (!ft_strncmp(line + i, "seven", 5))
			line[i+1] = '7';
		else if (!ft_strncmp(line + i, "eight", 5))
			line[i+1] = '8';
		else if (!ft_strncmp(line + i, "nine", 4))
			line[i+1] = '9';	
		i++;
	}
}

int	sum_of_line(char *line)
{
	int	sum = 0;
	int start = 0;
	int end = ft_strlen(line) - 1;
	while (line[start])
	{
		if (line[start] >= '0' && line[start] <= '9')
		{
			sum += (line[start] - '0') * 10;
			break ;
		}
		start++;
	}
	while (end >= 0)
	{
		if (line[end] >= '0' && line[end] <= '9')
		{
			sum += (line[end] - '0');
			break ;
		}
		end--;
	}
	return (sum);
}


int	main()
{
	char	*line;
	int		sum = 0;

	while ((line = get_next_line(0)))
	{
		char_to_digit(line);
		sum += sum_of_line(line);
		free(line);
	}
	printf("%d\n", sum);
	return (0);
}
