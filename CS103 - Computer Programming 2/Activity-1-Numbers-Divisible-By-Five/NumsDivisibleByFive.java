public class NumsDivisibleByFive {
    public static void main(String[] args) {
        int[] numbers = {5, 0, 6, 15, 10, 9, 23, 24, 100, 500, 1, 22, 63, 96, 4, 50};

        for (int number : numbers) {
            if (number % 5 == 0) {
                System.out.println(number + " is Divisible by 5.");
            } else {
                System.out.println(number + " is not Divisible by 5.");
            }
        }
    }
}