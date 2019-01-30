/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:20:01 by khou              #+#    #+#             */
/*   Updated: 2018/12/31 02:18:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int a, int b){
  int	ret = a + b;
  return (ret);}

int	deduction(int a, int b){
  int ret = a - b;
  return (ret);}

int	production(int a, int b){
  int ret  = a * b;
  return (ret);}

int	divide(int a, int b){
  int ret = a / b;
  return (ret);}

int 	mode(int a, int b){
  int ret = a % b;
  return (ret);}

fun_table	dispatch(char c)
{
  fun_table	f[126];

  f['+'] = &add;
  f['-'] = &deduction;
  f['*'] = &production;
  f['/'] = &divide;
  f['%'] = &mode;
  return (f[(int) c]);
}
