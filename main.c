/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:40 by tmoragli          #+#    #+#             */
/*   Updated: 2024/11/22 00:40:50 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libasm.h"

// Main de tests pour la lib
int main(void)
{
	//ft_strlen
	printf("---------------FT_STRLEN---------------\n");
	printf("Result: %ld, Errno: %d\n", ft_strlen("Hello World\n"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen("test"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen("H"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen("\0"), errno);
	// printf("Result: %ld, Errno: %d\n", ft_strlen(0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");
	//ft_strcpy
	printf("---------------FT_STRCPY---------------\n");
	char dest[128];
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s] Errno: %d\n", ft_strcpy(dest, "Hello, world!\n"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, "test"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, "HA"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, "H"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, "\0"), errno);
	bzero(dest, 128 * sizeof(char));
	// printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, 0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");
	//ft_strcpy
	printf("---------------FT_STRCMP---------------\n");
	printf("s1[Hello] s2[No]   : %d\n", ft_strcmp("Hello", "No"));
	printf("s1[No]    s2[Hello]: %d\n", ft_strcmp("No", "Hello"));
	printf("s1[No]    s2[No]   : %d\n", ft_strcmp("No", "No"));
	printf("s1[On]    s2[No]   : %d\n", ft_strcmp("On", "No"));
	printf("s1[No]    s2[On]   : %d\n", ft_strcmp("No", "On"));
	printf("s1[]      s2[]     : %d\n", ft_strcmp("", ""));
	//printf("s1[]      s2[]     : %d\n", ft_strcmp(0, 0)); // -> Should crash like the original function
	printf("---------------------------------------\n");
	printf("---------------FT_WRITE---------------\n");
	ft_write(1, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	ft_write(1, "\n", 1);
	printf("Errno: %d\n", errno);
	ft_write(1, "", 0);
	printf("Errno: %d\n", errno);
	char c = 'H';
	ft_write(1, &c, 1);
	printf("\nErrno: %d\n", errno);
	c = '\n';
	ft_write(1, &c, 1);
	printf("Errno: %d\n", errno);
	ft_write(42, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	ft_write(1, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	ft_write(1, NULL, 1);
	printf("Errno: %d\n", errno);
	ft_write(1, "Hello", 0);
	printf("Errno: %d\n", errno);
	int fd = open("/dev/full", O_RDONLY);
	ft_write(fd, "Hello", 5);
	printf("Errno: %d\n", errno);
	close(fd);
	printf("--------------------------------------\n");
	return (0);
}