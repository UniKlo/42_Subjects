<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Targaryen.class.php                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:56:02 by khou              #+#    #+#             */
/*   Updated: 2019/04/04 20:56:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Targaryen {
	function resistsFire() {
		return FALSE;
	}
	function getBurned() {
		if ($this->resistsFire()) {
			return "emerges naked but unharmed";
		} else {
			return "burns alive";
		}
	}
}