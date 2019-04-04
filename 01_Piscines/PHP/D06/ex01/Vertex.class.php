<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.class.php                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:50:23 by khou              #+#    #+#             */
/*   Updated: 2019/04/03 13:52:18 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

require_once("Color.class.php");
class Vertex {
	private $_x;
	private $_y;
	private $_z;
	private $_w = 1;
	private $_color;
	static $verbose = FALSE;
	public function __construct(array $xyzwc) {
		$this->_x = $xyzwc['x'];
		$this->_y = $xyzwc['y'];
		$this->_z = $xyzwc['z'];
		if (isset($xyzwc['w']) && !empty($xyzwc['w']))
			$this->_w = $xyzwc['w'];
		if (isset($xyzwc['color']) && !empty($xyzwc['color']) && $xyzwc['color'] instanceof Color) {
			$this->_color = $xyzwc['color'];
		} else {
			$this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
		}
		if (SELF::$verbose)
			printf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
	}

	function __destruct() {
		if (SELF::$verbose)
			printf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue);
	}
	function __toString() {
		if (SELF::$verbose)
			return (sprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, Color( red: %3d, green: %3d, blue: %3d ) )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue));
		return (sprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f )", $this->_x, $this->_y, $this->_z, $this->_w));
	}
	public static function doc() {
		$read = fopen("Vertex.doc.txt", "r");
		echo "\n";
		while ($read && !feof($read))
			echo fgets($read);
	}

		public function getX() {
		return $this->_x;
	}
	public function setX($x) {
		$this->_x = $x;
	}
	public function getY() {
		return $this->_y;
	}
	public function setY($y) {
		$this->_y = $y;
	}
	public function getZ() {
		return $this->_z;
	}
	public function setZ($z) {
		$this->_z = $z;
	}
	public function getW() {
		return $this->_w;
	}
	public function setW($w) {
		$this->_w = $w;
	}
	public function getColor() {
		return $this->_color;
	}
	public function setColor($color) {
		$this->_color = $color;
	}
}
?>