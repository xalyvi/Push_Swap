#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_stack
{
	int	top;
	unsigned	capacity;
	int	*array;
}	t_stack;

/*
** Stack functions
*/

t_stack	*create_stack(unsigned capacity);
int	is_full(t_stack *stack);
int	is_empty(t_stack *stack);
int	push(t_stack *stack, int item);
int	pop(t_stack *stack);

/*
** Commands
*/

void	swap_a(t_stack *a, t_stack *b, int p);
void	swap_b(t_stack *a, t_stack *b, int p);
void	swap_ab(t_stack *a, t_stack *b, int p);
void	push_a(t_stack *a, t_stack *b, int p);
void	push_b(t_stack *a, t_stack *b, int p);
void	rotate_a(t_stack *a, t_stack *b, int p);
void	rotate_b(t_stack *a, t_stack *b, int p);
void	rotate_ab(t_stack *a, t_stack *b, int p);
void	reverse_a(t_stack *a, t_stack *b, int p);
void	reverse_b(t_stack *a, t_stack *b, int p);
void	reverse_ab(t_stack *a, t_stack *b, int p);

/*
** Utility functions
*/

int	write_rt(char *str, int rt);
int	check_args(t_stack *a);
int	push_stack(t_stack *a, int st, int en, char *argv[]);
void	print_arrs(t_stack *a, t_stack *b);
int	is_command(char *str);
int	repeating_f(int array[], int len);
int	is_sorted(t_stack *s);
int	ft_strdig(const char *str);
void	q_push_b(t_stack *a, t_stack *b);
void	optimization(t_stack *a, t_stack *b);
void	quicksort(t_stack *a, t_stack *b);

/*
** GET_NEXT_LINE functions
*/

typedef struct	s_gnl
{
	char	*buf;
	int	count;
	int	i;
	int	nl;
	int	fd;
}	t_gnl;

int	get_next_line(int const fd, char **line);

/*
** LIBFT functions
*/

typedef struct	s_list
{
	char	*content;
	size_t	content_size;
	struct s_list	*next;
}	t_list;

long	ft_atol(const char *str);
void	ft_putnbr(int n);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *s1, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstadd(t_list **alst, t_list *new);
char	*ft_strchr(const char *s, int c);

#endif
