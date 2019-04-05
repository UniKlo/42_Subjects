<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jaime.class.php                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:12:09 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 14:12:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Jaime {
	function sleepWith($i) {
		if ($i instanceof Tyrion) {
			print("Not even if I'm drunk !". PHP_EOL);
		} else if ($i instanceof Sansa) {
			print("Let's do this." . PHP_EOL);
		} else if ($i instanceof Cersei) {
			print("With pleasure, but only in a tower in Winterfell, then." . PHP_EOL);
		}
	}
}