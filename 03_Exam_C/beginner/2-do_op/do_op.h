/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:20:25 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 11:20:28 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef int	(*fun_table)(int a, int b);

fun_table	dispatch(char c);
#endif
