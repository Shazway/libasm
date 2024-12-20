/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:26:40 by tmoragli          #+#    #+#             */
/*   Updated: 2024/12/21 17:16:17 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libasm.h"

int main(void)
{
	#ifndef LIBASM
	//ft_strlen
	printf("---------------FT_STRLEN---------------\n");
	printf("Result: %ld, Errno: %d\n", ft_strlen("Hello World\n"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen("test"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen("H"), errno);
	printf("Result: %ld, Errno: %d\n", ft_strlen(""), errno);
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
	printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, ""), errno);
	bzero(dest, 128 * sizeof(char));
	// printf("Dest: [%s], Errno: %d\n", ft_strcpy(dest, 0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");

	//ft_strcmp
	printf("---------------FT_STRCMP---------------\n");
	printf("s1[Hello] s2[No]   : %d\n", ft_strcmp("Hello", "No"));
	printf("s1[No]    s2[Hello]: %d\n", ft_strcmp("No", "Hello"));
	printf("s1[No]    s2[No]   : %d\n", ft_strcmp("No", "No"));
	printf("s1[On]    s2[No]   : %d\n", ft_strcmp("On", "No"));
	printf("s1[No]    s2[On]   : %d\n", ft_strcmp("No", "On"));
	printf("s1[]      s2[]     : %d\n", ft_strcmp("", ""));
	printf("s1[ ]     s2[]     : %d\n", ft_strcmp(" ", ""));
	printf("s1[]      s2[ ]     : %d\n", ft_strcmp("", " "));
	//printf("s1[]      s2[]: %d\n", ft_strcmp(0, 0)); // -> Should crash like the original function
	printf("---------------------------------------\n");

	//ft_write
	printf("---------------FT_WRITE---------------\n");
	// Regular tests
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

	// Error tests
	ft_write(42, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	ft_write(1, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	errno = 0;
	ft_write(1, NULL, 1);
	errno = 0;
	printf("Errno: %d\n", errno);
	ft_write(1, "Hello", 0);
	printf("Errno: %d\n", errno);
	errno = 0;

	int fd = open("/dev/full", O_RDONLY);
	ft_write(fd, "Hello", 5);
	printf("Errno: %d\n", errno);
	close(fd);
	errno = 0;
	printf("--------------------------------------\n");

	//ft_read
	printf("---------------FT_READ---------------\n");
	// Normal txt with \n at the end and 13 characters total
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 13);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);

	// Normal txt with \n at the end 6 size read after reading whole file
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 6);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Normal txt with \n at the end 6 size read (reopoened file)
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 6);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Normal txt with \n at the end 0 size read
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 0);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	fd = open("./ressources/normal.txt", O_RDONLY);
	// Normal txt with \n at the end 32 size read
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 32);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// One char
	fd = open("./ressources/one.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Empty file
	fd = open("./ressources/empty.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Write only opened file
	fd = open("./ressources/normal.txt", O_WRONLY);
	bzero(dest, sizeof(char) * 128);
	ft_read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);
	errno = 0;

	// Random file descriptor
	bzero(dest, sizeof(char) * 128);
	ft_read(42, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	printf("-------------------------------------\n");

	//ft_strdup
	errno = 0;
	printf("---------------FT_STRDUP---------------\n");
	char *dst;
	dst = ft_strdup("Hello World\n");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = ft_strdup("test");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = ft_strdup("H");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = ft_strdup("\0");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = ft_strdup("");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	// printf("Result: [%s], Errno: %d\n", ft_strdup(0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");
	#else
	//strlen
	printf("---------------STRLEN---------------\n");
	printf("Result: %ld, Errno: %d\n", strlen("Hello World\n"), errno);
	printf("Result: %ld, Errno: %d\n", strlen("test"), errno);
	printf("Result: %ld, Errno: %d\n", strlen("H"), errno);
	printf("Result: %ld, Errno: %d\n", strlen(""), errno);
	printf("Result: %ld, Errno: %d\n", strlen("\0"), errno);
	// printf("Result: %ld, Errno: %d\n", strlen(0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");

	//strcpy
	printf("---------------STRCPY---------------\n");
	char dest[128];
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s] Errno: %d\n", strcpy(dest, "Hello, world!\n"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", strcpy(dest, "test"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", strcpy(dest, "HA"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", strcpy(dest, "H"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", strcpy(dest, "\0"), errno);
	bzero(dest, 128 * sizeof(char));
	printf("Dest: [%s], Errno: %d\n", strcpy(dest, ""), errno);
	bzero(dest, 128 * sizeof(char));
	// printf("Dest: [%s], Errno: %d\n", strcpy(dest, 0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");

	//strcmp
	printf("---------------STRCMP---------------\n");
	printf("s1[Hello] s2[No]   : %d\n", strcmp("Hello", "No"));
	printf("s1[No]    s2[Hello]: %d\n", strcmp("No", "Hello"));
	printf("s1[No]    s2[No]   : %d\n", strcmp("No", "No"));
	printf("s1[On]    s2[No]   : %d\n", strcmp("On", "No"));
	printf("s1[No]    s2[On]   : %d\n", strcmp("No", "On"));
	printf("s1[]      s2[]     : %d\n", strcmp("", ""));
	printf("s1[ ]     s2[]     : %d\n", strcmp(" ", ""));
	printf("s1[]      s2[ ]     : %d\n", strcmp("", " "));
	//printf("s1[]      s2[]: %d\n", strcmp(0, 0)); // -> Should crash like the original function
	printf("---------------------------------------\n");

	//write
	printf("---------------WRITE---------------\n");
	// Regular tests
	write(1, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	write(1, "\n", 1);
	printf("Errno: %d\n", errno);
	write(1, "", 0);
	printf("Errno: %d\n", errno);
	char c = 'H';
	write(1, &c, 1);
	printf("\nErrno: %d\n", errno);
	c = '\n';
	write(1, &c, 1);
	printf("Errno: %d\n", errno);

	// Error tests
	write(42, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	write(1, "Hello World!\n", 14);
	printf("Errno: %d\n", errno);
	errno = 0;
	write(1, NULL, 1);
	errno = 0;
	printf("Errno: %d\n", errno);
	write(1, "Hello", 0);
	printf("Errno: %d\n", errno);
	errno = 0;

	int fd = open("/dev/full", O_RDONLY);
	write(fd, "Hello", 5);
	printf("Errno: %d\n", errno);
	close(fd);
	errno = 0;
	printf("--------------------------------------\n");

	//read
	printf("---------------READ---------------\n");
	// Normal txt with \n at the end and 13 characters total
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 13);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);

	// Normal txt with \n at the end 6 size read after reading whole file
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 6);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Normal txt with \n at the end 6 size read (reopoened file)
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 6);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Normal txt with \n at the end 0 size read
	fd = open("./ressources/normal.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 0);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	fd = open("./ressources/normal.txt", O_RDONLY);
	// Normal txt with \n at the end 32 size read
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 32);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// One char
	fd = open("./ressources/one.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Empty file
	fd = open("./ressources/empty.txt", O_RDONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);

	// Write only opened file
	fd = open("./ressources/normal.txt", O_WRONLY);
	bzero(dest, sizeof(char) * 128);
	read(fd, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	close(fd);
	errno = 0;

	// Random file descriptor
	bzero(dest, sizeof(char) * 128);
	read(42, dest, 1);
	printf("[%s]\n", dest);
	printf("Errno: %d\n", errno);
	printf("-------------------------------------\n");

	//strdup
	errno = 0;
	printf("---------------STRDUP---------------\n");
	char *dst;
	dst = strdup("Hello World\n");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = strdup("test");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = strdup("H");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = strdup("\0");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	dst = strdup("");
	printf("Result: [%s], Errno: %d\n", dst, errno);
	free(dst);

	// printf("Result: [%s], Errno: %d\n", strdup(0), errno); // -> Should crash like the original function
	printf("---------------------------------------\n");
	#endif

	return (0);
}
