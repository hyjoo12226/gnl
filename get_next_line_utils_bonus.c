/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjoo <hyjoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:53:32 by hyjoo             #+#    #+#             */
/*   Updated: 2021/02/09 20:07:56 by hyjoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str_new;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	if (!(str_new = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j])
		str_new[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str_new[i++] = s2[j++];
	str_new[i] = '\0';
	return (str_new);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*ft_strdup(const char *str)
{
	int		s_len;
	char	*str_copy;
	int		i;

	i = 0;
	s_len = ft_strlen(str);
	str_copy = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!(str_copy))
		return (NULL);
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
