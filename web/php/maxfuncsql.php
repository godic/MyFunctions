<?php
include_once "config.php";

function db_connect(){

    $host = get_server_info();
    $con = mysqli_connect($host["address"], $host["name"], $host["password"], $host["db"]);

    if(mysqli_connect_errno()){
        ?><script>alert("Failed to connect to MySQL")</script>
        <meta http-equiv="refresh" content="0; url=index.php" /><?php
        return null;
    }

    mysqli_query($con, "SET NAMES 'utf8'");

    return $con;
}


function select_query_all($_table){

    $query = "SELECT * FROM $_table";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query_all_m1($_table, $_fieldname, $_value){

    $query = "SELECT * FROM $_table WHERE $_fieldname = '$_value'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}
function select_query_all_m2($_table, $_fieldname1, $_value1, $_fieldname2, $_value2){

    $query = "SELECT * FROM $_table WHERE $_fieldname1 = '$_value1' AND $_fieldname2 = '$_value2'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query_all_mm($_table, $_fieldname, $_value){

    $query = "SELECT * FROM $_table WHERE ";
    for($i = 0; $i < count($_fieldname) - 1; $i++){
        $query .= $_fieldname[$i] . " = '" . $_value[$i] . "' AND ";
    }
    $query .= $_fieldname[count($_fieldname) - 1] . " = '" . $_value[count($_fieldname) - 1] . "'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query($_table, $_attribute){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }
    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query_m1($_table, $_attribute, $_fieldname, $_value){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }
    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table WHERE $_fieldname = '$_value'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query_m2($_table, $_attribute, $_fieldname1, $_value1, $_fieldname2, $_value2){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }

    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table WHERE $_fieldname1 = '$_value1' AND $_fieldname2 = '$_value2'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function select_query_mm($_table, $_attribute, $_fieldname, $_value){

    // Attributes
    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }
    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table WHERE ";

    // Condition
    for($i = 0; $i < count($_fieldname) - 1; $i++) {
        $query .= $_fieldname[$i] . " = '" . $_value[$i] . "' AND ";
    }
    $query .= $_fieldname[count($_fieldname) - 1] . " = '" . $_value[count($_fieldname) - 1] . "'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function insert_query($_table, $_attribute){

    $last = count($_attribute)-1;
    $query = "INSERT INTO $_table VALUE (";
    for($i=0; $i < $last;$i++){
        if(is_null($_attribute[$i])){
            $query .= 'NULL' . ", ";
            continue;
        }
        $query .= "'$_attribute[$i]'".", ";
    }

    if(is_null($_attribute[$last])){
        $query .= 'NULL' . ")";
    }
    else{
        $query .= "'$_attribute[$last]'" . ")";
    }

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function update_query_v1_m1($_table, $attribute, $value, $_field, $_value){

    $query = "UPDATE $_table SET $attribute = '$value' WHERE $_field = '$_value'";

    $db = db_connect();
    $result = mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function update_query_v2_m1($_table, $attribute1, $value1, $attribute2, $value2, $_field, $_value){

    $query = "UPDATE $_table SET $attribute1 = '$value1', $attribute2 = '$value2' WHERE $_field = '$_value'";
    $db = db_connect();
    $result = mysqli_query($db, $query);

    mysqli_close($db);

    return $result;
}

function update_query_vm_mm($_table, $_attribute, $value, $_field, $_value){
// Attributes
    $last = count($attribute) - 1;
    $query = "UPDATE $_table SET ";
    for($i = 0; $i < $last; $i++){
        $query .= $_attribute[$i] . " = '" . $_value[$i] . "', ";
    }
    $query .= $_attribute[$last] . " = '" . $_value[$last];

// condition
    $last = count($_field) - 1;
    $query .= " WHERE ";
    for($i = 0; $i < $last; $i++){
        $query .= $_field[$i] . " = '" . $_value[$i] . "' AND ";
    }
    $query .= $_field[$last] . " = '" . $_value[$i];

    $db = db_connect();
    $result = mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function delete_query_m1($_table, $_fieldname, $_value){

    $query = "DELETE FROM $_table WHERE $_fieldname = '$_value'";

    $db = db_connect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);
    return $result;
}

function send_query($query){
    $db = db_connect();
    $result = mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

?>
