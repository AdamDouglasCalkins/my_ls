#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>

typedef	struct		s_list
{
    char		*fname;
    long int		datenum;
    long int		datensec;
    struct s_list	*next;
}			t_list;

int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
t_list			*ft_create_elem(char *str, long int dateint, long int dnsec);
void			ft_list_push_back(t_list **begin_list,
				char *str, long int dateint,long int dnsec);
void			nodeSwap(t_list **head_list, int index);
int			isDateSort(t_list *begin_list);
int			isFnameSort(t_list *begin_list);
int			findNodePlace(t_list *begin_list);
int			findNodeNamePlace(t_list *begin_list);
void			printList(t_list *begin_list, int aflag);
void			deleteList(t_list* head_ref);
int			month_to_int(char a, char b, char c);
int			setaflag(char *str);
int			settflag(char *str);
void			startList(char *str, int aflag, int tflag);
int			main(int argc, char** argv);

#endif
