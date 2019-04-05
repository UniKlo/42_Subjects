<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   House.class.php                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:30:18 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 13:33:07 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

abstract class House {
	function introduce() {
		echo "House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->getHouseMotto() . "\"" . PHP_EOL;
	}
	
	abstract function getHouseName();
	abstract function getHouseSeat();
	abstract function getHouseMotto();
}