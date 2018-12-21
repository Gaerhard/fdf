/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:42:14 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/21 14:22:48 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# define BUFF_SIZE 500000

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_vect
{
	int				x;
	int				y;
	int				z;
}					t_vect;

char				*ft_strjoin_free(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putstr(const char *str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *s));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_scalevect(t_vect *vector, int scale);
void				ft_lstback(t_list **begin_list, void *data, size_t size);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbrendl(int n);
void				ft_del(void *content, size_t size);
int					ft_print_return(const char *s, int fd);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_sign(int nb);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
int					ft_dotvect(const t_vect v1, const t_vect v2);
int					get_next_line(const int fd, char **line);
int					ft_lstlength(t_list *beginlist);
int					ft_free_return(char *str, int fd, void *p);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s, const char *needle);
char				*ft_strnstr(const char *s, const char *needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_convert_base(char *nbr, char *b_f, char *b_t);
char				**ft_split(char *str, char *cs);
char				**ft_strsplit(const char *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_vect				ft_prodvect(const t_vect v1, const t_vect v2);
t_vect				ft_sumvect(const t_vect v1, const t_vect v2);
t_vect				ft_setvect(int x, int y, int z);
double				ft_abs(double nb);

#endif
