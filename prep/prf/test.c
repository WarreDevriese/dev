/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:33:04 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/08 11:37:18 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	printf("What happens with a %m I wonder %s\n", "super curious now");
	printf("What happens with a %w I wonder %s\n", "super curious now");
	printf("What happens with a %r I wonder %s\n", "super curious now");
	printf("What happens with a %t I wonder %s\n", "super curious now");
	return (0);
}
