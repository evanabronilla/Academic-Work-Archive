import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OrderingSystem {

    // Prices for meals, drinks, and desserts
    static final double[] mealPrices = {50.0, 80.0, 110.0};
    static final double[] drinkPrices = {10.0, 10.0, 25.0};
    static final double[] dessertPrices = {10.0, 30.0, 50.0};

    // Arrays to store the ordered quantities
    static int[] mealOrders = new int[3];
    static int[] drinkOrders = new int[3];
    static int[] dessertOrders = new int[3];

    // Total amount due
    static double totalAmount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        char mainChoice;

        while (true) {
            displayMainMenu();
            String inputLine = reader.readLine().toUpperCase();
            
            if (inputLine.isEmpty()) continue;
            mainChoice = inputLine.charAt(0);

            switch (mainChoice) {
                case 'A':
                    orderMeal(reader);
                    break;
                case 'B':
                    orderDrink(reader);
                    break;
                case 'C':
                    orderDessert(reader);
                    break;
                case 'D':
                    processPayment(reader);
                    return; // End program after payment
                default:
                    System.out.println("\n[!] Invalid choice. Please try again.");
            }
        }
    }

    // --- Menu Display Methods ---

    static void displayMainMenu() {
        System.out.println("\n===============================");
        System.out.println("       RESTO ORDER SYSTEM");
        System.out.println("===============================");
        System.out.println("[A] Meals");
        System.out.println("[B] Drinks");
        System.out.println("[C] Desserts");
        System.out.println("[D] Checkout & Payment");
        System.out.println("-------------------------------");
        System.out.print("Choose an option: ");
    }

    static void orderMeal(BufferedReader reader) throws IOException {
        System.out.println("\n--------- MEAL LIST ---------");
        System.out.println("[A] Meal #1     - P 50.00");
        System.out.println("[B] Meal #2     - P 80.00");
        System.out.println("[C] Meal #3     - P 110.00");
        System.out.print("Choose a meal: ");
        char itemChoice = reader.readLine().toUpperCase().charAt(0);
        
        System.out.print("Enter quantity (max 5): ");
        int quantity = Integer.parseInt(reader.readLine());

        if (quantity > 0 && quantity <= 5) {
            switch (itemChoice) {
                case 'A': mealOrders[0] += quantity; break;
                case 'B': mealOrders[1] += quantity; break;
                case 'C': mealOrders[2] += quantity; break;
                default: System.out.println("[!] Invalid meal choice."); return;
            }
            System.out.println("[+] Added to cart.");
        } else {
            System.out.println("[!] Maximum quantity per order is 5.");
        }
    }

    static void orderDrink(BufferedReader reader) throws IOException {
        System.out.println("\n--------- DRINK LIST --------");
        System.out.println("[A] Soft Drink  - P 10.00");
        System.out.println("[B] Juice       - P 10.00");
        System.out.println("[C] Coffee      - P 25.00");
        System.out.print("Choose a drink: ");
        char itemChoice = reader.readLine().toUpperCase().charAt(0);
        
        System.out.print("Enter quantity (max 5): ");
        int quantity = Integer.parseInt(reader.readLine());

        if (quantity > 0 && quantity <= 5) {
            switch (itemChoice) {
                case 'A': drinkOrders[0] += quantity; break;
                case 'B': drinkOrders[1] += quantity; break;
                case 'C': drinkOrders[2] += quantity; break;
                default: System.out.println("[!] Invalid drink choice."); return;
            }
            System.out.println("[+] Added to cart.");
        } else {
            System.out.println("[!] Maximum quantity per order is 5.");
        }
    }

    static void orderDessert(BufferedReader reader) throws IOException {
        System.out.println("\n-------- DESSERT LIST -------");
        System.out.println("[A] Ice Cream   - P 10.00");
        System.out.println("[B] Cake        - P 30.00");
        System.out.println("[C] Fruit Salad - P 50.00");
        System.out.print("Choose a dessert: ");
        char itemChoice = reader.readLine().toUpperCase().charAt(0);
        
        System.out.print("Enter quantity (max 5): ");
        int quantity = Integer.parseInt(reader.readLine());

        if (quantity > 0 && quantity <= 5) {
            switch (itemChoice) {
                case 'A': dessertOrders[0] += quantity; break;
                case 'B': dessertOrders[1] += quantity; break;
                case 'C': dessertOrders[2] += quantity; break;
                default: System.out.println("[!] Invalid dessert choice."); return;
            }
            System.out.println("[+] Added to cart.");
        } else {
            System.out.println("[!] Maximum quantity per order is 5.");
        }
    }

    // --- Calculation & Payment Methods ---

    public static void calculateTotal() {
        totalAmount = 0;
        for (int i = 0; i < 3; i++) {
            totalAmount += (mealOrders[i] * mealPrices[i]);
            totalAmount += (drinkOrders[i] * drinkPrices[i]);
            totalAmount += (dessertOrders[i] * dessertPrices[i]);
        }
    }

    static void processPayment(BufferedReader reader) throws IOException {
        calculateTotal();

        System.out.println("\n===============================");
        System.out.println("        ORDER SUMMARY");
        System.out.println("===============================");
        
        // Detailed summary of each category
        displayCategorySummary("Meals", mealOrders, mealPrices);
        displayCategorySummary("Drinks", drinkOrders, drinkPrices);
        displayCategorySummary("Desserts", dessertOrders, dessertPrices);

        System.out.println("-------------------------------");
        System.out.printf("TOTAL AMOUNT : P %.2f\n", totalAmount);

        double paymentAmount;
        while (true) {
            System.out.print("Enter Payment Amount: P ");
            paymentAmount = Double.parseDouble(reader.readLine());
            
            if (paymentAmount >= totalAmount) {
                double change = paymentAmount - totalAmount;
                System.out.println("-------------------------------");
                System.out.println("[+] Payment Successful!");
                System.out.printf("Change       : P %.2f\n", change);
                System.out.println("Thank you for dining with us!");
                break;
            } else {
                System.out.println("[!] Insufficient payment. Please enter a sufficient amount.");
            }
        }
        System.out.println("===============================");
    }

    // Helper method to display ordered items for a category
    private static void displayCategorySummary(String label, int[] orders, double[] prices) {
        boolean hasItems = false;
        for (int qty : orders) if (qty > 0) hasItems = true;

        if (hasItems) {
            System.out.println(label + ":");
            for (int i = 0; i < orders.length; i++) {
                if (orders[i] > 0) {
                    System.out.printf("  Item #%d x %d  = P %.2f\n", (i + 1), orders[i], (orders[i] * prices[i]));
                }
            }
        }
    }
}