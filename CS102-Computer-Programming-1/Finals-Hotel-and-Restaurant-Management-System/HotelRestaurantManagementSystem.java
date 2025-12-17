import java.io.*;
import java.util.*;

public class HotelRestaurantManagementSystem {
    private static final String CUSTOMER_FILE = "Customer_Records.txt";
    private static final String ORDER_FILE = "Customer_Orders.txt";

    // Menu Data Structures
    private static final Map<String, String> MEALS_MENU = new LinkedHashMap<>();
    private static final Map<String, Double> MEALS_PRICE = new LinkedHashMap<>();
    private static final Map<String, String> DRINKS_MENU = new LinkedHashMap<>();
    private static final Map<String, Double> DRINKS_PRICE = new LinkedHashMap<>();
    private static final Map<String, String> DESSERTS_MENU = new LinkedHashMap<>();
    private static final Map<String, Double> DESSERTS_PRICE = new LinkedHashMap<>();
    private static final Map<String, String> SIDE_DISHES_MENU = new LinkedHashMap<>();
    private static final Map<String, Double> SIDE_DISHES_PRICE = new LinkedHashMap<>();
    private static final Map<String, String> BUNDLED_MENU = new LinkedHashMap<>();
    private static final Map<String, Double> BUNDLED_PRICE = new LinkedHashMap<>();

    static {
        initializeMenus();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            displayMainMenu();
            System.out.print("Enter your choice: ");
            String input = reader.readLine();
            if (input == null || input.isEmpty()) continue;
            String choice = input.toUpperCase();

            switch (choice) {
                case "A": handleCustomerRecordMenu(reader); break;
                case "B": handleReservationRecordMenu(reader); break;
                case "C": generateBill(reader); break;
                case "X":
                    printBoxed("Thank you for using the system. Goodbye!");
                    return;
                default:
                    System.out.println("⚠️ Invalid choice. Please try again.");
            }
        }
    }

    private static void initializeMenus() {
        // Meals
        MEALS_MENU.put("A1", "Chicken and Waffles");   MEALS_PRICE.put("A1", 300.00);
        MEALS_MENU.put("B1", "Healthy Taco Salad");    MEALS_PRICE.put("B1", 375.00);
        MEALS_MENU.put("C1", "Roast Beef");            MEALS_PRICE.put("C1", 450.00);
        MEALS_MENU.put("D1", "Cochinillo");            MEALS_PRICE.put("D1", 700.00);
        MEALS_MENU.put("E1", "Steak");                 MEALS_PRICE.put("E1", 650.00);
        
        // Drinks
        DRINKS_MENU.put("A2", "Iced Tea");             DRINKS_PRICE.put("A2", 50.00);
        DRINKS_MENU.put("B2", "Coffee");               DRINKS_PRICE.put("B2", 100.00);
        DRINKS_MENU.put("C2", "Fruit Shake");          DRINKS_PRICE.put("C2", 150.00);
        DRINKS_MENU.put("D2", "Soda");                 DRINKS_PRICE.put("D2", 75.00);
        DRINKS_MENU.put("E2", "Wine");                 DRINKS_PRICE.put("E2", 200.00);
        
        // Desserts
        DESSERTS_MENU.put("A3", "Ice Scramble");       DESSERTS_PRICE.put("A3", 150.00);
        DESSERTS_MENU.put("B3", "Banana Split");       DESSERTS_PRICE.put("B3", 200.00);
        DESSERTS_MENU.put("C3", "Mousse Cake");        DESSERTS_PRICE.put("C3", 250.00);
        DESSERTS_MENU.put("D3", "Panna Cotta");        DESSERTS_PRICE.put("D3", 180.00);
        DESSERTS_MENU.put("E3", "Tiramisu");           DESSERTS_PRICE.put("E3", 220.00);
        
        // Side Dishes
        SIDE_DISHES_MENU.put("A4", "French Fries");    SIDE_DISHES_PRICE.put("A4", 120.00);
        SIDE_DISHES_MENU.put("B4", "Garlic Bread");    SIDE_DISHES_PRICE.put("B4", 90.00);
        SIDE_DISHES_MENU.put("C4", "Mashed Potatoes"); SIDE_DISHES_PRICE.put("C4", 150.00);
        
        // Bundled
        BUNDLED_MENU.put("A5", "Burger Combo");        BUNDLED_PRICE.put("A5", 500.00);
        BUNDLED_MENU.put("B5", "Pasta Combo");         BUNDLED_PRICE.put("B5", 600.00);
        BUNDLED_MENU.put("C5", "Seafood Platter");     BUNDLED_PRICE.put("C5", 1200.00);
    }

    // --- UI Methods ---

    private static void displayMainMenu() {
        System.out.println("\n+-----------------------------------------------------------+");
        System.out.println("|      Hotel and Restaurant Management System               |");
        System.out.println("+-----------------------------------------------------------+");
        System.out.println("| [A] 📝 Create Customer Record                             |");
        System.out.println("| [B] ✍  Create Reservation Record                          |");
        System.out.println("| [C] 🧾 Bill Out Module                                    |");
        System.out.println("| [X] ❌ Exit System                                        |");
        System.out.println("+-----------------------------------------------------------+");
    }

    private static void handleCustomerRecordMenu(BufferedReader reader) throws IOException {
        while (true) {
            System.out.println("\n📋 Customer Record Module");
            System.out.println("[A] Create Customer Record");
            System.out.println("[B] Update Customer Record");
            System.out.println("[C] View Customer Record");
            System.out.println("[X] Return to Main Menu");
            System.out.print("Enter your choice: ");
            String choice = reader.readLine().toUpperCase();

            if (choice.equals("A")) createCustomerRecord(reader);
            else if (choice.equals("B")) updateCustomerRecord(reader);
            else if (choice.equals("C")) viewCustomerRecords();
            else if (choice.equals("X")) return;
            else System.out.println("⚠️ Invalid choice.");
        }
    }

    // --- Data Logic Methods ---

    private static void createCustomerRecord(BufferedReader reader) throws IOException {
        System.out.print("Enter Customer Name: ");      String name = reader.readLine();
        System.out.print("Enter Contact Number: ");     String contact = reader.readLine();
        System.out.print("Enter Date (YYYY-MM-DD): ");  String date = reader.readLine();
        System.out.print("Enter Time (HH:MM): ");       String time = reader.readLine();
        System.out.print("Enter Number of Guests: ");   int guests = Integer.parseInt(reader.readLine());

        String record = name + "," + contact + "," + date + "," + time + "," + guests + "\n";
        saveToFile(CUSTOMER_FILE, record);
        System.out.println("✅ Customer record saved!");
    }

    private static void updateCustomerRecord(BufferedReader reader) throws IOException {
        System.out.print("Enter Customer Name to update: ");
        String searchName = reader.readLine();

        File customerFile = new File(CUSTOMER_FILE);
        File tempFile = new File("temp_" + CUSTOMER_FILE);
        boolean recordFound = false;

        try (BufferedReader br = new BufferedReader(new FileReader(customerFile));
             BufferedWriter bw = new BufferedWriter(new FileWriter(tempFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts[0].equalsIgnoreCase(searchName)) {
                    recordFound = true;
                    System.out.println("Found! Enter new guests count: ");
                    String newGuests = reader.readLine();
                    bw.write(parts[0] + "," + parts[1] + "," + parts[2] + "," + parts[3] + "," + newGuests);
                } else {
                    bw.write(line);
                }
                bw.newLine();
            }
        }
        if (recordFound) {
            customerFile.delete();
            tempFile.renameTo(customerFile);
            System.out.println("✅ Record updated.");
        } else {
            tempFile.delete();
            System.out.println("⚠️ Record not found.");
        }
    }

    private static void viewCustomerRecords() throws IOException {
        System.out.println("\n--- Customer Database ---");
        try (BufferedReader br = new BufferedReader(new FileReader(CUSTOMER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] p = line.split(",");
                System.out.printf("Name: %-15s | Guests: %s\n", p[0], p[4]);
            }
        } catch (FileNotFoundException e) {
            System.out.println("⚠️ No records found.");
        }
    }

    // --- Order Logic ---

    private static void handleReservationRecordMenu(BufferedReader reader) throws IOException {
        while (true) {
            System.out.println("\n📋 Order Management");
            System.out.println("[A] Create Orders");
            System.out.println("[B] View Orders");
            System.out.println("[X] Return");
            System.out.print("Choice: ");
            String choice = reader.readLine().toUpperCase();
            if (choice.equals("A")) createOrdersRecord(reader);
            else if (choice.equals("B")) viewOrdersRecord();
            else if (choice.equals("X")) return;
        }
    }

    private static void createOrdersRecord(BufferedReader reader) throws IOException {
        StringBuilder orderDetails = new StringBuilder();
        boolean ordering = true;
        while (ordering) {
            System.out.println("\nMenu: [A]Meals [B]Drinks [C]Desserts [X]Finish");
            System.out.print("Select: ");
            String menuChoice = reader.readLine().toUpperCase();
            if (menuChoice.equals("A")) orderDetails.append(selectItems(reader, MEALS_MENU, MEALS_PRICE, "Meals"));
            else if (menuChoice.equals("B")) orderDetails.append(selectItems(reader, DRINKS_MENU, DRINKS_PRICE, "Drinks"));
            else if (menuChoice.equals("C")) orderDetails.append(selectItems(reader, DESSERTS_MENU, DESSERTS_PRICE, "Desserts"));
            else if (menuChoice.equals("X")) ordering = false;
        }
        saveToFile(ORDER_FILE, orderDetails.toString());
        System.out.println("✅ Order Saved.");
    }

    private static String selectItems(BufferedReader reader, Map<String, String> menu, Map<String, Double> prices, String name) throws IOException {
        StringBuilder sb = new StringBuilder();
        menu.forEach((k, v) -> System.out.println(k + ": " + v + " - P" + prices.get(k)));
        System.out.print("Enter Code (X to stop): ");
        String code = reader.readLine().toUpperCase();
        if (menu.containsKey(code)) {
            System.out.print("Quantity: ");
            int q = Integer.parseInt(reader.readLine());
            sb.append(name).append(",").append(menu.get(code)).append(",").append(q).append(",").append(prices.get(code) * q).append("\n");
        }
        return sb.toString();
    }

    private static void viewOrdersRecord() throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(ORDER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) System.out.println(line);
        } catch (Exception e) { System.out.println("⚠️ No orders."); }
    }

    // --- Billing ---

    private static void generateBill(BufferedReader reader) throws IOException {
        System.out.print("Enter Customer Name for Bill: ");
        String name = reader.readLine();
        double total = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(ORDER_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                total += Double.parseDouble(line.split(",")[3]);
            }
            System.out.printf("\nTotal Amount Due: P %.2f\n", total);
            System.out.print("Enter Payment: ");
            double pay = Double.parseDouble(reader.readLine());
            if (pay >= total) System.out.printf("✅ Success! Change: P %.2f\n", (pay - total));
            else System.out.println("⚠️ Insufficient funds.");
        } catch (Exception e) { System.out.println("⚠️ Error generating bill."); }
    }

    private static void saveToFile(String fileName, String content) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(content);
        }
    }

    private static void printBoxed(String message) {
        int len = message.length();
        String b = "+-" + "-".repeat(len) + "-+";
        System.out.println(b + "\n| " + message + " |\n" + b);
    }
}