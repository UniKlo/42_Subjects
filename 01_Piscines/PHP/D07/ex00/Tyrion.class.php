<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tyrion.class.php                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:45:30 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 13:11:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Tyrion extends Lannister{
	public function __construct() {
		parent::__construct();
		print("My name is Tyrion" . PHP_EOL);
	}
	public function getSize() {
		return "Short";
	}
}
	