/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <mmanuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:55:44 by mgalvez           #+#    #+#             */
/*   Updated: 2025/02/05 19:10:43 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int			is_child;
	char		**envp;
	int			envp_len;
	int			exit_code;
	int			*pid_tab;
	int			pid_tab_len;
}	t_data;

typedef struct s_cmd
{
	char			**args;
	int				argc;
	int				fd_in;
	int				fd_out;
	int				to_close_fd;
}	t_cmd;

// GENERAL

void	ft_kill(t_cmd *cmd, t_data *data);
int		exec_builtins(t_cmd *cmd, t_data *data);

//	VISUAL

void	get_title(void);
char	*get_prompt(void);

//SIGNAL

void	signal_handler_init(void);
void	signal_handler_inchild(void);
void	signal_handler_child(void);

// PARSING

char	**ft_line_spliter(char const *s);
void	init_tokenization(char **input, t_data *data);
int		syntax_parsing(char **line, t_data *data);
int		ft_isbuiltin(char *arg);

//EXPAND

char	**ft_checkexpand(char **input, t_data *data);
char	*get_expand_value(char *env_value, int double_quote, t_data *data);
char	*join_parts(char **parts, int *expand_index,
			int double_quote, t_data *data);
char	**get_parts(char *input, int *expand_index, int *double_quote);
int		parse_expand_quotes(char **input);
char	**split_expand_result(char **input, int *index);
char	**ft_split_quotes(char const *s);
char	*expand_passquotes(char *input, int i);

//TOKENIZATION

void	tokenize_builtin(char **line, t_data *data);
void	tokenize_other(char **line, t_data *data, int cmd_index, int i);
int		find_lens(char **line, int *i, int *cmd_len, int *args_len);
int		parse_cmd(t_cmd *cmd, char **line, int cmd_len, int args_len);

// REDIRECT

int		get_redirect_fd(t_cmd *cmd, char **line, int i);
char	*unquote_filename(char *filename);
int		get_heredoc_fd(char *limiter, char *name);

// UNQUOTE

void	ft_unquote(char **input);

//	BUILTINS

int		ft_echo(t_cmd *cmd);
int		ft_cd(t_cmd *cmd, t_data *data);
int		ft_pwd(t_cmd *cmd);
int		ft_env(t_cmd *cmd, t_data *data, char *prefix);
int		ft_export(t_data *data, t_cmd *cmd);
int		ft_unset(t_data *data, t_cmd *cmd);
int		ft_exit(t_cmd *cmd, t_data *data);

//	ENV
char	*parse_var_name(char *arg);
int		get_env_size(char **data);
int		get_env_index(char *env_var, t_data *data);
char	**realloc_envp(char **old_envp, size_t new_size);
int		add_env_var(t_data *data, t_cmd *cmd, char *var_name, int cmdi);
int		remove_env_var(t_data *data, t_cmd *cmd, int cmdi);
int		set_env_var(t_data *data, char *var_name, char *value);
char	*get_env_var(t_data *data, char *var_name);

//EXEC

void	ft_exec(t_cmd *cmd, t_data *data, char **line, int cmd_index);
char	*check_path(t_data *data, char *cmd_path);
char	*ft_findpath(t_data *data, char *cmd);

#endif
