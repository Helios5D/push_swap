/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:37:14 by hdaher            #+#    #+#             */
/*   Updated: 2024/07/11 14:44:43 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Includes

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

//Part I - Libc functions

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
int		ft_strcmp(char	*s1, char	*s2);
void	free_char_tab(char **tab);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

// Part II - Additional functions

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_argv(int size, char **strs, char *sep);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// ft_printf

// ft_printf.c //

int		ft_printf(const char *str, ...);
int		put_arg(char format, va_list args, int *count);

// tools_1.c //

void	ft_printnbr_hex(unsigned int nbr, int is_upper, int *count);
void	ft_printnbr(int n, int *count);
void	ft_printunsignednbr(unsigned int n, int *count);
void	ft_printptr_rec(unsigned long nbr, char *base, int *count);
void	ft_printptr(unsigned long ptr, int *count);

// tools_2.c //

void	ft_printchar(char c, int *count);
void	ft_printstr(char *str, int *count);

// ftd_printf

// ftd_printf.c //

int		ftd_printf(int fd, const char *str, ...);
int		put_arg_fd(char format, va_list args, int *count, int fd);

// tools_1.c //

void	ft_printnbr_hex_fd(unsigned int nbr, int is_upper, int *count, int fd);
void	ft_printnbr_fd(int n, int *count, int fd);
void	ft_printunsignednbr_fd(unsigned int n, int *count, int fd);
void	ft_printptr_rec_fd(unsigned long nbr, char *base, int *count, int fd);
void	ft_printptr_fd(unsigned long ptr, int *count, int fd);

// tools_2.c //

void	ft_printchar_fd(char c, int *count, int fd);
void	ft_printstr_fd(char *str, int *count, int fd);

#endif
