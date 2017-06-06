/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 08:06:16 by mmatime           #+#    #+#             */
/*   Updated: 2017/06/05 08:06:17 by mmatime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_inputs(char *str)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if ((str[i] == ' ' && str[i - 1] != ' ') ||
				(str[i] == '\n' && str[i - 1] != '\n'))
			a++;
		i++;
	}
	return (a);
}

int		input_count(char *str)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			a++;
		if (str[i] == '\n' && str[i - 1] != '\n')
		{
			a++;
			return (a);
		}
		i++;
	}
	return (a);
}
