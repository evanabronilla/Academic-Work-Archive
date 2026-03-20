<?php
session_start();

$questionBank = [
    [
        "id" => 1,
        "question" => "Which of the following is NOT a fruit?",
        "choices" => ["Rhubarb", "Tomatoes", "Avocados", "Blueberry"],
        "answer" => "Rhubarb"
    ],
    [
        "id" => 2,
        "question" => "Where was the first example of paper money used?",
        "choices" => ["China", "Turkey", "Greece", "Madrid"],
        "answer" => "China"
    ],
    [
        "id" => 3,
        "question" => "What number was the Apollo mission that successfully put a man on the moon for the first time in human history?",
        "choices" => ["Apollo 11", "Apollo 12", "Apollo 13", "Apollo 10"],
        "answer" => "Apollo 11"
    ],
    [
        "id" => 4,
        "question" => "Which horoscope sign is a fish?",
        "choices" => ["Aquarius", "Cancer", "Pisces", "Aries"],
        "answer" => "Pisces"
    ],
    [
        "id" => 5,
        "question" => "Which app has the most total users?",
        "choices" => ["TikTok", "Snapchat", "Instagram", "Canvas"],
        "answer" => "Instagram"
    ],
    [
        "id" => 6,
        "question" => "What city hosted the 2002 Olympic Games?",
        "choices" => ["Tokyo", "Beijing", "Sydney", "Manila"],
        "answer" => "Sydney"
    ],
    [
        "id" => 7,
        "question" => "Which of the following was considered one of the Seven Ancient Wonders?",
        "choices" => ["Colosseum", "Great Wall of China", "Colossus of Rhodes", "Leaning Tower of Pisa"],
        "answer" => "Colossus of Rhodes"
    ],
    [
        "id" => 8,
        "question" => "What is the strongest muscle in the human body?",
        "choices" => ["Jaw", "Heart", "Glutes", "Lungs"],
        "answer" => "Jaw"
    ],
    [
        "id" => 9,
        "question" => "Anna, Elsa Kristoff and Olaf are all characters in what animated movie?",
        "choices" => ["Frozen", "Fro-Yo", "Cinderella", "Snow White"],
        "answer" => "Frozen"
    ],
    [
        "id" => 10,
        "question" => "What name is singer-actor Stefani Germanotta better known by?",
        "choices" => ["Lady Gaga", "Taylor Swift", "Chappel Roan", "Marian Rivera"],
        "answer" => "Lady Gaga"
    ]
];

shuffle($questionBank);
$selectedQuestions = array_slice($questionBank, 0, 5);
$_SESSION['questions'] = $selectedQuestions;
?>

<!DOCTYPE html>
<html>
<head>
    <title>PHP Multiple-Choice Exam</title>
</head>
<body>

<h2>Randomized Quiz</h2>

<form method="post" action="result.php">
    <?php foreach ($selectedQuestions as $item): ?>
        <p><?php echo $item['question']; ?></p>

        <?php foreach ($item['choices'] as $choice): ?>
            <label>
                <input
                    type="radio"
                    name="ans_<?php echo $item['id']; ?>"
                    value="<?php echo $choice; ?>"
                    required
                >
                <?php echo $choice; ?>
            </label><br>
        <?php endforeach; ?>

        <input type="hidden" name="correct_<?php echo $item['id']; ?>" value="<?php echo $item['answer']; ?>">
        <br>
    <?php endforeach; ?>

    <input type="submit" value="Submit">
</form>

</body>
</html>