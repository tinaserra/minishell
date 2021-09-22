/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:48:41 by vserra            #+#    #+#             */
/*   Updated: 2021/09/22 01:11:49 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

/*
** STRING ------------------------------------------------------------------- **
*/

char	*ft_del_last_char(char *s);
void	ft_free_tab(char **tab);
int		ft_get_next_line(int fd, char **line);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_print_tab(char **halo, int size);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putstr_non_printable(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strcdup(char *str, int c);
char	*ft_strchr(char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *s1);
char	*ft_strndup(char *s1, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strs_tab_size(char **tab);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_free(char *s1, char *s2, int ctrl);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strncat(char *s1, const char *s2, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strndup(char *s1, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strs_tab_size(char **tab);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char *s, unsigned int start, size_t len);

/*
** NUMBERS ------------------------------------------------------------------ **
*/

int		ft_atoi_base(char *str, char *base);
long	ft_atoi(const char *str);
int		ft_check_base(char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(int nbr, char *base);
char	*ft_itoa(int n);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_fd(int n, int fd);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, unsigned int size);
void	ft_swap(int *a, int *b);

/*
** LIST --------------------------------------------------------------------- **
*/

t_list	*ft_lstadd_at(t_list *l, void *data, int pos);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstcreate(void *data);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstfind_pos(t_list *lst, int pos);
t_list	*ft_lstfree_at(t_list *l, int pos);
t_list	*ft_lstfree(t_list *l);
void	*ft_lstget_at(t_list *l, int pos);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstprint(t_list *l);
void	ft_lstset_at(t_list *l, void *data, int pos);
int		ft_lstsize(t_list *l);

/*
** MEMORY ------------------------------------------------------------------- **
*/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_realloc(void *ptr, size_t size);
#endif