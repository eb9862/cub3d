/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunhwang <eunhwang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:50:52 by eunhwang          #+#    #+#             */
/*   Updated: 2024/06/11 17:17:17 by eunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int	check_newline(char *s)
{
	int	idx;

	idx = 0;
	if (s == NULL)
		return (-1);
	while (*(s + idx) != '\0')
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

char	*update_backup(char *backup, int idx)
{
	int		i;
	char	*new_backup;

	i = 0;
	if (idx == -1)
		return (NULL);
	while (*(backup + idx + 1 + i) != '\0')
		i++;
	new_backup = malloc(sizeof(char) * (i + 1));
	if (new_backup == NULL)
		return (0);
	i = 0;
	while (*(backup + idx + 1 + i) != '\0')
	{
		*(new_backup + i) = *(backup + idx + 1 + i);
		i++;
	}
	*(new_backup + i) = '\0';
	free(backup);
	return (new_backup);
}

char	*check_last(int idx, ssize_t r_bytes, char **addr_backup)
{
	char	*res;

	if (idx == -1 && r_bytes <= 0)
	{
		res = malloc(sizeof(char) *(gnl_strlen(*addr_backup) + 1));
		if (res == NULL)
			return (0);
		gnl_strlcpy(res, *addr_backup, gnl_strlen(*addr_backup) + 1);
		free(*addr_backup);
		*addr_backup = NULL;
	}
	else
	{
		res = malloc(sizeof(char) * (idx + 2));
		if (res == NULL)
			return (0);
		gnl_strlcpy(res, *addr_backup, idx + 2);
		*addr_backup = update_backup(*addr_backup, idx);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*backup[4096];
	ssize_t		r_bytes;
	char		lines[BUFFER_SIZE + 1];
	char		*res;
	int			idx;

	r_bytes = 1;
	while (check_newline(backup[fd]) == -1 && r_bytes > 0)
	{
		r_bytes = read(fd, lines, BUFFER_SIZE);
		lines[r_bytes] = 0;
		if (r_bytes <= 0 && backup[fd] == NULL)
			return (NULL);
		backup[fd] = gnl_strjoin(backup[fd], lines);
	}
	idx = check_newline(backup[fd]);
	if ((idx == -1 && r_bytes <= 0) && *(backup[fd]) == '\0')
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	res = check_last(idx, r_bytes, &(backup[fd]));
	return (res);
}

/*#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd1 = open("./test.txt", O_RDONLY);
    int fd2 = open("./test", O_RDONLY);
	
    int l1 = 1;
    int l2 = 1;
	if (fd1 > 0 && fd2 > 0)
	{
		for (int i = 0; i < 2; i++)
        {
			char *s = get_next_line(fd1);
			printf("1 - %i : %s", l1, s);
			free(s);
            l1++;
        }
        for (int i = 0; i < 3; i++)
        {
			char *s = get_next_line(fd2);
			printf("2 - %i : %s", l2, s);
			free(s);
            l2++;
        }
        for (int i = 0; i < 3; i++)
        {
			char *s = get_next_line(fd1);
            printf("1 - %i : %s", l1, s);
			free(s);
            l1++;
        }
        for (int i = 0; i < 2; i++)
        {
			char *s = get_next_line(fd2);
            printf("2 - %i : %s", l2, s);
			free(s);
            l2++;
        }
        for (int i = 0; i < 4; i++)
        {
			char *s = get_next_line(fd1);
            printf("1 - %i : %s", l1, s);
			free(s);
            l1++;
        }
        for (int i = 0; i < 4; i++)
        {
			char *s = get_next_line(fd2);
            printf("2 - %i : %s", l2, s);
			free(s);
            l2++;
        }
        for (int i = 0; i < 3; i++)
        {
			char *s = get_next_line(fd1);
            printf("1 - %i : %s", l1, s);
			free(s);
            l1++;
        }
        for (int i = 0; i < 3; i++)
        {
			char *s = get_next_line(fd2);
            printf("2 - %i : %s", l2, s);
			free(s);
            l2++;
        }
		close(fd1);
        close(fd2);
	}
}*/
