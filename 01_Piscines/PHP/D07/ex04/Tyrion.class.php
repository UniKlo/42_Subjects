<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tyrion.class.php                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:14:17 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 14:14:47 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Tyrion {
	function sleepWith($i) {
		if ($i instanceof Jaime || $i instanceof Cersei) {
			print("Not even if I'm drunk !" . PHP_EOL);
		} else if ($i instanceof Sansa) {
			print("Let's do this." . PHP_EOL);
		} 
	}
}
?>