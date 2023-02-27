/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:22:40 by ebang             #+#    #+#             */
/*   Updated: 2023/02/24 17:02:53 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void		ft_lstclear(t_list **lst, void (*del)(void *));

void		ft_lstiter(t_list *lst, void (*f)(void *));

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

size_t		ft_strlen(const char *s);

void		*ft_memset(void *s, int a, size_t b);

void		*ft_bzero(void *b, size_t s);

void		*ft_memcpy(void *dst, const void *a, size_t b);

void		*ft_memmove(void *b, const void *a, size_t c);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t		ft_strlcat(char *s1, const char *s2, size_t n);

int			ft_toupper(int a);
int			ft_tolower(int a);

char		*ft_strchr(const char *s, int a);

char		*ft_strrchr(const char *s, int c);

int			ft_strncmp(const char *s, const char *s1, size_t n);

void		*ft_memchr(const void *b, int a, size_t n);

int			ft_memcmp(const void *b, const void *s1, size_t n);

char		*ft_strnstr(const char*s1, const char *s2, size_t n);

int			ft_atoi(const char *str);

void		*ft_calloc(size_t n1, size_t n2);

char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

char		*ft_strtrim(char const *s1, char const *s2);

char		*ft_itoa(int n);

char		**ft_split(char const *s, char c);

char		*ft_strmapi(char const *a, char (*f)(unsigned int, char));

void		ft_striteri(char *a, void ((*f)(unsigned int, char*)));

void		ft_putchar_fd(char a, int b);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *a, int fd);

void		ft_putnbr_fd(int a, int b);

#endif
