/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:40 by tmoragli          #+#    #+#             */
/*   Updated: 2024/11/20 02:11:49 by tmoragli         ###   ########.fr       */
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
	return (0);
}