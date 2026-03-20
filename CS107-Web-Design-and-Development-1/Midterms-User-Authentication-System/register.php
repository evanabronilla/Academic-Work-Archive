<?php
session_start();
require_once 'users.php';

$error = '';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $u = trim($_POST['username']);
    $p = trim($_POST['password']);

    if (isset($_SESSION['users'][$u])) {
        $error = "Username already exists.";
    } else {
        $_SESSION['users'][$u] = $p;
        header("Location: index.php?registered=1");
        exit;
    }
}
?>
<!DOCTYPE html>
<html>
<head><title>Register</title></head>
<body>
    <h2>Register</h2>
    <?php if ($error) echo "<p style='color:red;'>$error</p>"; ?>

    <form method="post" action="register.php">
        Username:<br>
        <input type="text" name="username" required><br><br>
        Password:<br>
        <input type="password" name="password" required><br><br>
        <input type="submit" value="Register">
    </form>
    <p>Already have an account? <a href="index.php">Login here</a></p>
</body>
</html>