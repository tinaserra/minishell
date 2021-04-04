#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char *s1, char *set);
void	ft_putstr_fd(int fd, char *s);
int		ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
int		get_next_line(int fd, char **line);
char	**ft_split(char *str, char *charset);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
char	*ft_itoa(int n);
int		ft_strs_tab_size(char **tab);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_isdigit(int c);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_realloc(void *ptr, size_t size);
int     ft_strcmp(char *s1, char *s2);
#endif