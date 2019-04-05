<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NightsWatch.class.php                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:46:06 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 16:21:50 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
class NightsWatch implements IFighter{
	private $fighters = [];
	function recruit($fighter) {
		$this->fighters[] = $fighter;
	}
	function fight() {
		foreach ($this->fighters as $fighter) {
			if (method_exists(get_class($fighter), 'fight'))
				$fighter->fight();
		}
	}
}
?>