<?php
    // clear dir
    shell_exec('rm -r up_load');
    shell_exec('mkdir up_load');


    $proj = $_FILES['upfile'];
    $file_name = explode(".",$proj['name'])[0];
    move_uploaded_file($proj['tmp_name'],"up_load/".$file_name.".zip");

    $results = shell_exec('unzip ./up_load/'.$file_name.' -d ./up_load');
    echo $results;

    // $results = shell_exec('python3 do_encode.py');
    // echo $results;
    //header("Location: result.php"); 

?>