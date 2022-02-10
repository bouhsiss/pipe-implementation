/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:15:22 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/02/07 15:15:24 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		findp(char **envp);
char	**ft_split(char *s, char c);
char	*ft_paths(char **envp, int p, char *cmd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	free_array(char **arr);

#endif
