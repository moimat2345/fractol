/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateon <mateon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:57:31 by matnusko          #+#    #+#             */
/*   Updated: 2025/10/12 13:00:34 by mateon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// list struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//////////////////////////////////////////////////////////////////////
// Part 1

// conversion
int		ft_atoi(const char *nptr);

// memory
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

// string
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

// char tests
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// char convert
int		ft_tolower(int c);
int		ft_toupper(int c);

//////////////////////////////////////////////////////////////////////
// Part 2

// string allocation
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

// string with function
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// output on fd
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//////////////////////////////////////////////////////////////////////
// Bonus Part
// list creation
t_list	*ft_lstnew(void *content);

// list add
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

// list size / last
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// list delete
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

// list iterate / map
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//printf fonctions
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(unsigned long long ptr);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long long num, int uppercase);
int		ft_putpointer(void *ptr);
int		ft_putunbr(unsigned int n);
int		ft_printf(const char *str, ...);

//get_next_line fonctions
char	*get_next_line_get(int fd);
size_t	ft_strlen(const char *s);
int		find_newline(const char *s);
char	*extract_line(char *buffer);
char	*update_buffer(char *buffer);
char	*read_file(int fd, char *buffer);

#endif