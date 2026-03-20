<?php
session_start();
require_once 'users.php';

$error = '';
$success = '';

if (isset($_GET['registered']) && $_GET['registered'] == 1) {
    $success = "Registration successful. You can now log in.";
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $u = trim($_POST['username'] ?? '');
    $p = trim($_POST['password'] ?? '');

    if (isset($_SESSION['users'][$u])) {
        if ($_SESSION['users'][$u] == $p) {
            $_SESSION['username'] = $u;
            header("Location: dashboard.php");
            exit;
        }
    }
    $error = "Invalid username or password.";
}
?>
<!DOCTYPE html>
<html>
<head><title>Login</title></head>
<body>
    <h2>Login</h2>
    <?php if ($success) echo "<p style='color:green;'>$success</p>"; ?>
    <?php if ($error) echo "<p style='color:red;'>$error</p>"; ?>

    <form method="post" action="index.php">
        Username:<br>
        <input type="text" name="username" required><br><br>
        Password:<br>
        <input type="password" name="password" required><br><br>
        <input type="submit" value="Login">
    </form>
    <p>No account? <a href="register.php">Register here</a></p>
</body>
</html>