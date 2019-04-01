<!DOCTYPE html>
<html lang='en'>
	<head>
		<meta charset='UTF-8' />
		<title>Dog Wash</title>
		<link href='../css/header.css' rel='stylesheet' type='text/css' />
		<link href='../css/styles.css' rel='stylesheet' type='text/css' />
	</head>
	<body>
		<ul>
			<li><a href='../index.php'><img src='https://github.com/hirenpateldotnex/rush00_src/blob/master/logo.png?raw=true'></a></li>
			<li><a href='../shop/shop.php'>SHOP</a></li>
		</ul>
		<br>
      <br>
      <?php
         $myfile = "../htdocs/private/passwd";
         if (isset($_POST['ta'])) {
             $newData = nl2br(htmlspecialchars($_POST['ta']));
             $handle = fopen($myfile, "w");
             fwrite($handle, $newData);
             fclose($handle);
         }
         if (file_exists($myfile)) {$myData = file_get_contents($myfile);}
         ?>
      <h1>Users</h1>
      <form action="admin_users_page.php" method="post">
         <textarea name="ta" cols="64" rows="10"><?php
            $myData = str_replace("<br />","",$myData);
            $myData = str_replace("<br>","",$myData);
            $myData = str_replace(" ","",$myData);
            echo $myData;
            ?></textarea>
         <br><br>
         <input name="myBtn" type="submit" />
      </form>
      <br>
      <h1>
      <a href="../login/login.html".php">Create New Users</a>
      <br>
      <br>
      <a href="admin_items_page.php">Edit Items</a><br>
      <a href="admin_orders_page.php">Edit Orders</a>
      <br>
      <br>
      <a href="admin.php">Admin page</a></h1>
      <footer>
    <p>Made by <b>Hiren</b>  & <b>Khloe</b></p>
</footer>
</body>
</html>