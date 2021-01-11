/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:52:22 by ksuzuki           #+#    #+#             */
/*   Updated: 2021/01/11 14:44:50 by ksuzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <libgen.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int i;
	int n;
	int fd[MAX_FD];
	char *p;
	int flag = 1;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd[i] = open(argv[i], 0);
			i++;
		}
		while (flag)
		{
			i = 1;
			flag = 0;
			while (i < argc)
			{
				if (fd[i] && (n = get_next_line(fd[i], &p)) == 0)
				{
					close(fd[i]);
					fd[i] = 0;
				}
				if (p != NULL)
				{
					flag = 1;
				}
				else
					n = 0;
				printf("%d: ", n);
				printf("%s, ", p);
				free(p);
				p = NULL;
				i++;
			}
			printf("\n");
		}
		// while ((n = get_next_line(fd[i], &p)) > 0)
		// {
		// 	while (i < argc)
		// 	printf("%s\n", p);
		// }
		// if (n == 0)
		// 	printf("%s\n", p);
		// printf("%d\n", i);
	}
	else
	{
		while ((n = get_next_line(0, &p)) > 0)
		{
			printf("%s\n", p);
		}
	}
	
	return (0);
}
