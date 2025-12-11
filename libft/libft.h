/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 15:05:37 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

//		Handle strings

int		str_len(const char *s);
void	*mem_set(void *s, int c, size_t n);
void	*mem_cpy(void *dest, const void *src, size_t n);
void	*mem_move(void *dest, const void *src, size_t n);
int		str_cpy(char *dest, char *src);
int		strl_cpy(char *dst, const char *src, size_t size);
int		str_chr(const char *s, int c);
int		strn_cmp(const char *s1, const char *s2, size_t n);
int		strn_str(const char *big, const char *little, size_t len);
char	*str_dup(const char *s);
char	**split(char *s, char c);

//		Handle numbers

int		a_toi(const char *nptr);
long	a_tol(const char *nptr);
int		check_if_int(char *s);
char	*i_toa(int n);
int		min(int i, int j);
int		max(int i, int j);
int		putnbr_base(long nbr, char *base, int fd);
int		putunbr_base(unsigned long nbr, char *base, int fd);

//		Handle arrays

int		int_chr(const int *arr, int n, int arrsize);
int		*arr_dup(int *arr, int size);
void	print_arr(int *arr, int arrsize);

//		Handle frees / errors

int		rtint_free(int rt, void *p);
void	*rtptr_free(void *rt, void *p);
int		rtint_ffree(int rt, void **p);
void	*rtptr_ffree(void *rt, void **p);
int		write_rtint(char *s, int rt, int fd);
void	*write_rtptr(char *s, void *rt, int fd);

//		ft_printf

int		ft_printf(const char *s, ...);
int		print_char(va_list args);
int		print_str(va_list args);
int		print_pointer(va_list args);
int		print_int(va_list args);
int		print_unint(va_list args);
int		print_hex(va_list args);
int		print_caphex(va_list args);
int		print_percent(va_list args);

#endif
