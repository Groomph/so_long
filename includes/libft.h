/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:25:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/10/23 14:00:45 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define BOOL int
# define TRUE 1
# define FALSE 0

# define DOFREE 1
# define DONTFREE 0

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

typedef struct s_list2
{
	int				nb;
	int				index;
	int				group;
	struct s_list2	*prev;
	struct s_list2	*next;
}					t_list2;

int					valeur_absolue(int nb);

/*
 ******************   BYTEWISE & MEMORY  ******************
*/

void				init_zero(void *pt, size_t i);

/*
 *******************  IS? FONCTIONS  *******************
*/

int					is_double_signed(long double doub);
int					is_not_number(long double doub);
int					is_infinite(long double doub);
int					is_whitespace(char c);

/*
 *******************  CHAR & STRING  *******************
*/

char				*substr(char *s, size_t start, size_t len);
char				*substr_free(char *s, size_t start, size_t len,
						BOOL freestr);
char				*strjoin(char *s1, char *s2);
char				*strjoin_free(char *s1, char *s2,
						BOOL freestr1, BOOL freestr2);
size_t				string_len(const char *s);
char				**string_split(const char *str, char c);
int					shift_right_add(char *str, char c, int i);
int					shift_left_erase(char *str, int i);
int					str_n_comp(char *str, char *str2, int stop);
char				*str_nstr_comp(char *str1, char *str2, size_t size_str2);
char				*string_duplicate(const char *original, int size);

/*
 *******************  CHAR ARRAY   *******************
*/

void				array_clear(void **array);
char				**array_string_duplicate(char **tab, int size);

/*
 *******************  NB & STRING CONVERSION  *******************
*/

int					utoa_len(unsigned long long nb, int sizebase);
int					utoa_base(unsigned long long nb, char *dest,
						char *base, int sizebase);
int					itoa_base(long long nb, char *dest,
						char *base, int sizebase);
int					atoi_windex(const char *str, int *i);
int					my_atoi(const char *str);
long int			atoli_windex(const char *str, int *i);
long int			ft_atoli(const char *str);
double				atodoub_windex(const char *str, int *i);

/*
 *******************  LINKED LIST  *******************
*/

t_list				*lst_new(int x, int y);
void				lst_addfront(t_list **alst, t_list *new);
void				lst_addback(t_list **alst, t_list *new, t_list *last);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstsecondlast(t_list *lst);
void				lst_clear(t_list **lst, void (*del)(void*));
t_list				*lst_duplicate(t_list *original);

/*
 *******************  LINKED LIST 2 *******************
*/

void				lst2_addfront(t_list2 **alst, t_list2 *new);
t_list2				*lst2_getlast(t_list2 *lst);
t_list2				*lst2_getsecondlast(t_list2 *lst, t_list2 *last);
void				lst2_addback(t_list2 **alst, t_list2 *new, t_list2 *last);
void				lst2_clear(t_list2 **lst, void (*del)(void*));
t_list2				*lst2_duplicate(t_list2 *original);

/*
 *******************  FILE DESCRIPTOR  *******************
*/

int					get_next_line(int fd, char **buffer,
						char **line, BOOL *eof);

#endif
