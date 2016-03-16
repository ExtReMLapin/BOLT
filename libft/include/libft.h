/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:18:07 by pfichepo          #+#    #+#             */
/*   Updated: 2015/12/03 16:18:05 by pfichepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define BUFF_SIZE 1
# define INTBLTLIMIT -2147466666

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_buffer
{
	int				fd;
	char			*buf;
}					t_buffer;

typedef struct		s_slist
{
	char			c;
	struct s_slist	*next;
	int				fd;
}					t_slist;

typedef struct		s_point
{
	struct s_point	*next;
	int				x;
	int				y;
	int				z;
	int				x_2d;
	int				y_2d;
	int				x_2dw;
	int				y_2dw;
}					t_point;

int					ft_isascii(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *rs1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(int const fd, char **line);
void				ft_putstr_force(char const *s, int len);
int					table_hasvalue(t_list *t, void *value);
void				printtable(t_list *tbl);
int					table_getsize(t_list *t);
void				error(char const *s);
void				errornohalt(char const *s);
void				table_insert(t_list *t, int pos, t_list *new);
char				**cleartbl(char **tbl);
void				printcharchar(char **tbl);
char				**file_totbl(char *file);
char				*rem_nonnum(char *str);
char				*str_replace(char *orig, char *rp, char *wt);
char				*str_replace2(char *orig, char *rp, char *wt);
char				*ft_strflip(char *s);
t_point				*chrrtocor(int **itbl);
int					ft_tbllen(char **tbl);
int					ft_tbllenskip(char **tbl);
int					ft_strisdigit(char *str);
int					**charrtointt(char **tbl);
int					nbrintlen(int *tbl);
void				printintint(int **tbl);
int					**reallocint(int **tbl);
t_point				*ft_ptsnew(int x, int y, int z);
int					pointsnb(t_point *pt);
void				freecharstr(char **tbl);
#endif
