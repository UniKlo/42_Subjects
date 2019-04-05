<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fighter.class.php                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:45:34 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 16:51:04 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fighter {
	private $person;
	
	public function __construct($person){
		$this->person = $person;
	}

	function getPerson() {
		return $this->person;
	}
	
}
		