import java.util.Scanner;

class KnowingtheUser {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // --- Data Collection Section ---
        System.out.println("========================================");
        System.out.println("      USER INFORMATION COLLECTOR");
        System.out.println("========================================");

        System.out.print("Enter your name: ");
        String name = input.nextLine();

        System.out.print("Enter your age: ");
        int age = input.nextInt(); 
        input.nextLine(); // Consume the leftover newline

        System.out.print("Enter number of programs learned: ");
        int programsLearned = input.nextInt();
        input.nextLine(); // Consume the leftover newline

        System.out.print("Enter your favorite show: ");
        String favoriteShow = input.nextLine();

        System.out.print("Enter your favorite sport: ");
        String favoriteSport = input.nextLine();

        System.out.print("Enter your favorite book: ");
        String favoriteBook = input.nextLine();

        System.out.print("Enter your favorite music genre: ");
        String favoriteMusicGenre = input.nextLine();

        System.out.print("Enter your favorite animal: ");
        String favoriteAnimal = input.nextLine();

        System.out.print("Enter your dream job: ");
        String dreamJob = input.nextLine();

        System.out.print("Enter the country you want to visit: ");
        String countryToVisit = input.nextLine();

        System.out.print("Enter your expected salary (in PHP): ");
        int expectedSalary = input.nextInt();

        // --- Output Display Section ---
        System.out.println("\n\n========================================");
        System.out.println("             USER PROFILE");
        System.out.println("========================================");
        System.out.printf("%-25s : %s\n", "Name", name);
        System.out.printf("%-25s : %d years old\n", "Age", age);
        System.out.printf("%-25s : %d\n", "Programs Learned", programsLearned);
        System.out.println("----------------------------------------");
        System.out.printf("%-25s : %s\n", "Favorite Show", favoriteShow);
        System.out.printf("%-25s : %s\n", "Favorite Sport", favoriteSport);
        System.out.printf("%-25s : %s\n", "Favorite Book", favoriteBook);
        System.out.printf("%-25s : %s\n", "Music Genre", favoriteMusicGenre);
        System.out.printf("%-25s : %s\n", "Favorite Animal", favoriteAnimal);
        System.out.println("----------------------------------------");
        System.out.printf("%-25s : %s\n", "Dream Job", dreamJob);
        System.out.printf("%-25s : %s\n", "Target Country", countryToVisit);
        System.out.printf("%-25s : PHP %,d.00\n", "Expected Salary", expectedSalary);
        System.out.println("========================================");

        // Closing the scanner
        input.close();
    }
}