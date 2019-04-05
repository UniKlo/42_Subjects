<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UnholyFactory.class.php                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:50:07 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 16:52:16 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class UnholyFactory {
	private $fighters = [];
	function absorb($obj) {
		if (get_parent_class($obj)) {
			if (isset($this->fighters[$obj->getPerson()])) {
				print("(Factory already absorbed a fighter of type " . $obj->getPerson() . ")" . PHP_EOL);
			} else {
				print("(Factory absorbed a fighter of type " . $obj->getPerson() . ")" . PHP_EOL);
				$this->fighters[$obj->getPerson()] = $obj;
			}
		} else {
			print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
		}
	}
	function fabricate($rf) {
		if (array_key_exists($rf, $this->fighters)) {
			print("(Factory fabricates a fighter of type " . $rf . ")" . PHP_EOL);
			return clone $this->fighters[$rf];
		}
		print("(Factory hasn't absorbed any fighter of type " . $rf . ")" . PHP_EOL);
		return NULL;
	}
}
?>