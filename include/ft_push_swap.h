/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srolland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:31:34 by srolland          #+#    #+#             */
/*   Updated: 2019/03/23 20:31:15 by srolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_lst
{
	int				n;
	int				ind;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

typedef struct	s_stack
{
	t_lst		*top;
	t_lst		*bottom;
	int			max;
	int			min;
	int			med;
	int			moy;
	int			cap;
}				t_stack;

typedef struct	s_xuita
{
	int			print;
	int			index;
	int			loop;
	int			mov_1;
	int			mov_2;
	int			id;
	int			min;
	int			max;
	int			med;
	int			*arr;
	int			iter;
}				t_xuita;

/*
** Commands
*/

void			swap_a(t_stack *a, t_stack *b, int p, int x);
void			swap_b(t_stack *a, t_stack *b, int p, int x);
void			swap_ab(t_stack *a, t_stack *b, int p, int x);
void			push_a(t_stack *a, t_stack *b, int p, int x);
void			push_b(t_stack *a, t_stack *b, int p, int x);
void			rotate_a(t_stack *a, t_stack *b, int p, int x);
void			rotate_b(t_stack *a, t_stack *b, int p, int x);
void			rotate_ab(t_stack *a, t_stack *b, int p, int x);
void			reverse_a(t_stack *a, t_stack *b, int p, int x);
void			reverse_b(t_stack *a, t_stack *b, int p, int x);
void			reverse_ab(t_stack *a, t_stack *b, int p, int x);

/*
** Utility functions
*/

int				*ft_get_argv(char **argv, int *argc, t_lst **list);
char			**get_ruby(char *argv, int *argc);
void			free_rub(char **argv);
int				ft_check_sort(t_stack *a, t_stack *b, int check);
int				ft_check_sort_b(t_stack *a, t_stack *b);
int				*push_arg(char *argv[], int amnt);
int				*sort_arr(int *arr, int amnt);
void			free_list(t_xuita *xuita, t_stack *a, t_stack *b, int *arr);
void			free_stack(t_stack *stack);
void			ft_free_arr(int *arr, int amnt);
void			ft_lst_free(t_lst *curr);
t_stack			*ft_create_stack(t_lst *list, int *arr, int amnt);
t_lst			*ft_create_lst(int *arr, int amnt);
t_stack			*ft_init_stack(void);
t_xuita			*ft_init_xuita(int *arr, t_stack *a, int print);
void			ft_sort_three_a(t_stack *a, t_stack *b, int check, int print);
void			ft_sort_three_b(t_stack *a, t_stack *b, int print);
void			ft_get_min(t_xuita *xuita);
void			ft_get_max(t_xuita *xuita);
int				ft_get_med(t_lst *list, int amnt);
void			ft_get_med_2(t_xuita *xuita);
void			do_rotate_b(t_xuita *xuita, t_stack *a, t_stack *b);
void			do_reverse_b(t_xuita *xuita, t_stack *a, t_stack *b);
void			ft_check_move(t_xuita *xuita, t_stack *a, t_stack *b);
void			push_shit_to_a(t_xuita *xuita, t_stack *a, t_stack *b);
void			push_to_a(t_stack *a, t_stack *b, int print);
void			push_to_b(t_stack *a, t_stack *b, int count, int print);
void			do_rotate_a(t_xuita *xuita, t_stack *a, t_stack *b);
void			do_reverse_a(t_xuita *xuita, t_stack *a, t_stack *b);
void			push_shit_to_b(t_xuita *xuita, t_stack *a, t_stack *b);
int				get_iter_number(int n);
void			ft_init_stack_param(t_stack *stack);
void			print_stacks(t_stack *a, t_stack *b);
int				is_command(char *str);
int				repeating_f(int array[], int len);
int				ft_is_ra(t_xuita *xuita, t_stack *a);
int				ft_is_rra(t_xuita *xuita, t_stack *a);
int				ft_is_rb(t_xuita *xuita, t_stack *b);
int				ft_is_rrb(t_xuita *xuita, t_stack *b);
int				ft_strdig(const char *str);

int				get_line(char **line);

/*
** LIBFT functions
*/

intmax_t		ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
