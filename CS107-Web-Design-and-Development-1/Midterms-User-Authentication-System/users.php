<?php
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}

if (!isset($_SESSION['users'])) {
    $_SESSION['users'] = [
        'admin' => 'admin123',
        'student1' => 'pass123'
    ];
}
?>