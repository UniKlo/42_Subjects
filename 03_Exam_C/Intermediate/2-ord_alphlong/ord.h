/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 23:14:42 by khou              #+#    #+#             */
/*   Updated: 2019/08/08 00:05:29 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node {
    char *str;
    struct s_node *left;
    struct s_node *right;
} t_node;

t_node *new_node(char *str);
int is_space(char c);
char **str_split(char *str);
