<?php
session_start();

if (!isset($_SESSION['username'])) {
    header("Location: index.php");
    exit;
}

$u = $_SESSION['username'];
?>
<!DOCTYPE html>
<html>
<head><title>Dashboard</title></head>
<body>
    <h2>Welcome, <?php echo htmlspecialchars($u); ?>!</h2>
    <a href="logout.php">Logout</a>
</body>
</html>