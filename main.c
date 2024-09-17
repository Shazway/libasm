/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:40 by tmoragli          #+#    #+#             */
/*   Updated: 2024/09/18 00:50:32 by tmoragli         ###   ########.fr       */
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
	printf("Result: %ld, Errno: %d\n", ft_strlen(0), errno);
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
	printf("---------------------------------------\n");
	return (0);
}