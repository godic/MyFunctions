<?php

function dbConnect(){

  $con = mysqli_connect('YOURSERVER', 'YOURID', 'YOURPASSWORD', 'YOURDB');

  if(mysqli_connect_errno()){
    ?><script>alert("Failed to connect to MySQL")</script>
    <meta http-equiv="refresh" content="0; url=index.php" /><?php
    return null;
  }

   mysqli_query($con, "SET NAMES 'utf8'");

  return $con;
}


function selectQueryAll($_table){

    $query = "SELECT * FROM $_table";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function selectQueryAllm1($_table, $_fieldname, $_value){

    $query = "SELECT * FROM $_table WHERE $_fieldname = '$_value'";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}
function selectQueryAllm2($_table, $_fieldname1, $_value1, $_fieldname2, $_value2){

    $query = "SELECT * FROM $_table WHERE $_fieldname1 = '$_value1' AND $_fieldname2 = '$_value2'";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function selectQueryAllmm($_table, $_fieldname, $_value){

  $query = "SELECT * FROM $_table WHERE ";
  for($i = 0; $i < count($_fieldname) - 1, $i++){
    $query .= $_fieldname[$i] . " = '" . $_value[$i] . "' AND ";
  }
  $query .= $_fieldname[count($_fieldname) - 1] . " = '" . $_value[count($_fieldname) - 1]"'";

  $db = dbConnect();
  $result=mysqli_query($db, $query);
  mysqli_close($db);

  return $result;
}

function selectQuery($_table, $_attribute){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }
    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function selectQuerym1($_table, $_attribute, $_fieldname, $_value){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }
    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table WHERE $_fieldname = '$_value'";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function selectQuerym2($_table, $_attribute, $_fieldname1, $_value1, $_fieldname2, $_value2){

    $query = "SELECT ";
    for($i=0; $i < count($_attribute)-1;$i++){
        $query .= $_attribute[$i].", ";
    }

    $query .= $_attribute[count($_attribute)-1];
    $query .= " FROM $_table WHERE $_fieldname1 = '$_value1' AND $_fieldname2 = '$_value2'";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);

    return $result;
}

function selectQuerymm($_table, $_attribute, $_fieldname, $_value){

  $last
  // Attributes
  $query = "SELECT ";
  for($i=0; $i < count($_attribute)-1;$i++){
      $query .= $_attribute[$i].", ";
  }
  $query .= $_attribute[count($_attribute)-1];
  $query .= " FROM $_table WHERE ";

  // Condition
  for($i = 0; $i < count($_fieldname) - 1, $i++){
    $query .= $_fieldname[$i] . " = '" . $_value[$i] . "' AND ";
  }
  $query .= $_fieldname[count($_fieldname) - 1] . " = '" . $_value[count($_fieldname) - 1] . "'";

  $db = dbConnect();
  $result=mysqli_query($db, $query);
  mysqli_close($db);

  return $result;
}

function insertQuery($_table, $_attribute){

    $last = count($_attribute)-1;
    $query = "INSERT INTO $_table VALUE (";
    for($i=0; $i < $last;$i++){
        if(isNull($_attribute[$i])){
            $query .= 'NULL' . ", ";
            continue;
        }
        $query .= "'$_attribute[$i]'".", ";
    }

    if(isNull($_attribute[$last])){
        $query .= 'NULL' . ")";
    }
    else{
        $query .= "'$_attribute[$last]'" . ")";
    }

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);
}

function updateQueryv1m1($_table, $attribute, $value, $_field, $_value){

    $query = "UPDATE $_table SET $attribute = '$value' WHERE $_field = '$_value'";

    $db = dbConnect();
    $result = mysqli_query($db, $query);
    mysqli_close($db);
}

function updateQueryv2m1($_table, $attribute1, $value1, $attribute2, $value2, $_field, $_value){

    $query = "UPDATE $_table SET $attribute1 = '$value1', $attribute2 = '$value2' WHERE $_field = '$_value'";
    $db = dbConnect();
    $result = mysqli_query($db, $query);

    mysqli_close($db);
}

function updateQueryvmmm($_table, $_attribute, $value, $_field, $_value){
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

  $db = dbConnect();
  $result = mysqli_query($db, $query);
  mysqli_close($db);
}

function deleteQuerym1($_table, $_fieldname, $_value){

    $query = "DELETE FROM $_table WHERE $_fieldname = '$_value'";

    $db = dbConnect();
    $result=mysqli_query($db, $query);
    mysqli_close($db);
}

function isNull($value){
    if($value === NULL)
        return true;
    return false;
}

function sendQuery($query){
  $db = dbConnect();
  $result = mysqli_query($db, $query);
  mysqli_close($db);

  return $result;
}

?>
