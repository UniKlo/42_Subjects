<?php
	session_start();
	// require_once('logout.php');
	$user = $_SESSION['logged_in_user'];
?>
<!DOCTYPE html>
<html lang='en'>
	<head>
		<meta charset='UTF-8' />
		<title>Dog Wash</title>
		<link href='../css/header.css' rel='stylesheet' type='text/css' />
        <link href='../css/styles.css' rel='stylesheet' type='text/css' />
        <script src="shop.js" async></script>
	</head>
	<body>
		<ul>
			<li><a href='../index.php'><img src='https://github.com/hirenpateldotnex/rush00_src/blob/master/logo.png?raw=true'></a></li>
			<li><a href='../shop/shop.php'>SHOP</a></li>
			<?php
				if ($_SESSION['logged_in_user'])
				{
					echo "<li><a href='../login/pw_modify.html'>". $user ."s Account</a></li>";
				}
				else
				{
					echo "<li><a href='../login/login.html'>SIGN IN</a></li>";
				}
				?>
		</ul>
        <br><h1>
        <form id="form" method="post" action="">
        Man <input type="checkbox" id="man"  onclick="myfilter()">
        Woman <input type="checkbox" id="woman"  onclick="myfilter()">
        Glassed <input type="checkbox" id="glasses"  onclick="myfilter()">
        Sunglasses <input type="checkbox" id="sun"  onclick="myfilter()">
        <p id="text" style="display:none">Checkbox is CHECKED!</p>
        </form></h1>
        <br>
      <?php
         $myfile = "../admin/items.txt";
         if (isset($_POST['ta'])) {
         	$newData = nl2br(htmlspecialchars($_POST['ta']));
         	$handle = fopen($myfile, "r");
         	fwrite($handle, $newData);
         	fclose($handle);
         }
         if (file_exists($myfile)) {
         	$tmp  = explode( ';', file_get_contents($myfile));
         	$data = array();
         	foreach ( $tmp as $k => $v )
         	{
         		$data[] = explode( '|', $v );
         	}
         }
         echo "<div style='display: block; margin: auto;width: 60%;padding: 10px;'>";
        //  echo "size of inventory: " . sizeof($data) . "\n";   
         for ($item_i = 1; $item_i < sizeof($data) ; $item_i++) {
            echo"<div class='shop-item' style='width: 40%;background-color: white'>
            <span class='shop-item-title'>".$data[$item_i][1]."</span>
            <br><img class='shop-item-image' style=' width: 200px;height: auto;'src='".$data[$item_i][6]."'>
            <div class='shop-item-details'>
                <span class='shop-item-price'>".$data[$item_i][3]."</span>
                <button class='btn btn-primary shop-item-button' type='button'>ADD TO CART</button>
            </div>
            </div><br><br>";
         }
         echo "</div>";
         ?>
         <section class="container content-section">
            <h2 class="section-header">CART</h2>
            <div class="cart-row">
                <span class="cart-item cart-header cart-column">ITEM</span>
                <span class="cart-price cart-header cart-column">PRICE</span>
                <span class="cart-quantity cart-header cart-column">QUANTITY</span>
            </div>
            <div class="cart-items">
            </div>
            <div class="cart-total">
                <strong class="cart-total-title">Total</strong>
                <span class="cart-total-price">$0</span>
            </div>
            <button class="btn btn-primary btn-purchase" type="button">PURCHASE</button>
        </section>
        </h1>
		<footer>
			<p>Made by <b>Hiren</b>  & <b>Khloe</b></p>
		</footer>
	</body>
</html>