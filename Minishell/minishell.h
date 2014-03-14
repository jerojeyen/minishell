#ifndef			__MINISHELL_H__
# define		__MINISHELL_H__


/*
**	Defines
*/

# define RETURN_EXIT -2
# define RETURN_ERROR -1
# define RETURN_SUCCESS 0
# define PROMPT "minishell $>"

/*
**	Structures
*/

typedef struct	s_env
{
  char		*name;
  char		*value;
  struct s_env	*next;
}		t_env;

typedef struct	s_info
{
  t_env		*env;
  char		**tab_cmd;
  char		*cmd;
}		t_info;

typedef struct	s_cmd
{
  char		*name;
  int		(*ptr_func)(t_info *info);
}		t_cmd;

typedef struct	s_string
{
  char			*st;
  struct s_string	*next;
}		t_string;

/*
**	Prototypes
*/

void		my_putchar(char c);
char		*read_line();
char		*clear_line(char*);
int		do_exit(t_info *);
int		do_env(t_info *);
int		do_pwd(t_info *);
int		do_cd(t_info *);
int		do_setenv(t_info *);
int		do_unsetenv(t_info *);
char		**make_table(char *line, char*);
char		*my_memset(int len, char c);
char		*epure(char *line, t_info *);
char		*my_getenv(t_info *info, char *name);
char		*strdup(const char *s);
void		free_ls(t_string **ls);
char		*do_new_line(t_string *ls);
char		*replace_other_tild(char *str, t_info *info);
char		*my_strcat(char *dest, char *src);

#endif			/* __MINISHELL_H__ */
