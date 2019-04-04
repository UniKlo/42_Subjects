<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.class.php                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:13:23 by khou              #+#    #+#             */
/*   Updated: 2019/04/03 13:47:01 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Class Color {
	public $red;
	public $green;
	public $blue;
	static $verbose = FALSE;
	public function __construct( array $color )
	{
		if (isset($color['red']) && isset($color['green']) && isset($color['blue'])) {
			$this->red = intval($color['red']);
			$this->green = intval($color['green']);
			$this->blue = intval($color['blue']);
		} else if (isset($color['rgb'])) {
			$rgb = intval($color['rgb']);
			$this->red = $rgb / (256 * 256);
			$this->green = ($rgb / 256) % 256;
			$this->blue = $rgb % 256;
		}
		if (SELF::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
	}

	public function __destruct() {
		if (SELF::$verbose)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}
	function __toString() {
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
	}
	public static function doc() {
		$read = fopen("Color.doc.txt", "r");
		echo "\n";
		while ($read && !feof($read))
			echo fgets($read);
	}
	public function add($Color) {
		return (new Color(array('red' => $this->red + $Color->red, 'green' => $this->green + $Color->green, 'blue' => $this->blue + $Color->blue)));
	}
	public function sub($Color) {
		return (new Color(array('red' => $this->red - $Color->red, 'green' => $this->green - $Color->green, 'blue' => $this->blue - $Color->blue)));
	}
	public function mult($mult) {
		return (new Color(array('red' => $this->red * $mult, 'green' => $this->green * $mult, 'blue' => $this->blue * $mult)));
	}
}

?>