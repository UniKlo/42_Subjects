<?php
function auth($login, $passwd)
{
    if (!$login || !$passwd)
        return FALSE;
    $fil_path = "..htdocs/private/passwd";
    $account = unserialize(file_get_contents($path));
    if ($account) 
    {
        foreach ($account as $key => $val) {
            if ($val["login"] === $login && $val["passwd"] === hash("whirlpool", $passwd))
                return TRUE;
    }
}
return FALSE;
}