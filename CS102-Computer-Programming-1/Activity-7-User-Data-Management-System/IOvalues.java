import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class IOvalues {

    // Constant file name used throughout the program
    private static final String FILE_NAME = "user_data.txt";

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Main loop for user menu
        while (true) {
            System.out.println("\n============================");
            System.out.println("       USER DATA MENU");
            System.out.println("============================");
            System.out.println("C - Create File");
            System.out.println("W - Write Data to File");
            System.out.println("S - Search Record by ID");
            System.out.println("U - Update Record by ID");
            System.out.println("D - Delete Record by ID");
            System.out.println("V - View File Contents");
            System.out.println("E - Exit System");
            System.out.println("----------------------------");
            System.out.print("Enter your choice: ");

            // Capture and process user input
            String choice = reader.readLine().toUpperCase();

            switch (choice) {
                case "C":
                    createFile();
                    break;
                case "W":
                    writeDataToFile(reader);
                    break;
                case "S":
                    searchRecordByID(reader);
                    break;
                case "U":
                    updateRecordByID(reader);
                    break;
                case "D":
                    deleteRecordByID(reader);
                    break;
                case "V":
                    viewFileContents();
                    break;
                case "E":
                    System.out.println("[!] Exiting system...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("[X] Invalid choice. Please try again.");
            }
        }
    }

    /**
     * Create a file if it doesn't already exist.
     */
    private static void createFile() {
        File file = new File(FILE_NAME);
        try {
            if (file.createNewFile()) {
                System.out.println("[+] File created successfully: " + FILE_NAME);
            } else {
                System.out.println("[!] File already exists.");
            }
        } catch (IOException e) {
            System.out.println("[X] Error creating file: " + e.getMessage());
        }
    }

    /**
     * Write user data to the file.
     */
    private static void writeDataToFile(BufferedReader reader) throws IOException {
        System.out.println("\n--- Input New Record ---");
        System.out.print("Enter ID: ");
        String id = reader.readLine();
        System.out.print("Enter Fullname: ");
        String fullname = reader.readLine();
        System.out.print("Enter Age: ");
        String age = reader.readLine();
        System.out.print("Enter Email: ");
        String email = reader.readLine();
        System.out.print("Enter Contact: ");
        String contactNo = reader.readLine();

        try (FileWriter writer = new FileWriter(FILE_NAME, true)) {
            writer.write(id + "," + fullname + "," + age + "," + email + "," + contactNo + "\n");
            System.out.println("[+] Data written to file successfully.");
        } catch (IOException e) {
            System.out.println("[X] Error writing to file: " + e.getMessage());
        }
    }

    /**
     * Search for a record by ID and display it.
     */
    private static void searchRecordByID(BufferedReader reader) throws IOException {
        System.out.print("\nEnter ID to search: ");
        String searchID = reader.readLine();

        try (BufferedReader fileReader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            boolean found = false;
            while ((line = fileReader.readLine()) != null) {
                String[] record = line.split(",");
                if (record[0].equals(searchID)) {
                    System.out.println("\n[!] Record Found:");
                    displayRecord(record);
                    found = true;
                    break;
                }
            }
            if (!found) System.out.println("[X] Record with ID " + searchID + " not found.");
        } catch (IOException e) {
            System.out.println("[X] Error reading file: " + e.getMessage());
        }
    }

    /**
     * Update a record by ID.
     */
    private static void updateRecordByID(BufferedReader reader) throws IOException {
        System.out.print("\nEnter ID to update: ");
        String updateID = reader.readLine();

        File file = new File(FILE_NAME);
        if (!file.exists()) {
            System.out.println("[X] File does not exist.");
            return;
        }

        List<String> records = new ArrayList<>();
        boolean found = false;

        try (BufferedReader fileReader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = fileReader.readLine()) != null) {
                String[] record = line.split(",");
                if (record[0].equals(updateID)) {
                    System.out.println("Current data: " + line);
                    System.out.print("New Fullname: ");
                    String fullname = reader.readLine();
                    System.out.print("New Age: ");
                    String age = reader.readLine();
                    System.out.print("New Email: ");
                    String email = reader.readLine();
                    System.out.print("New Contact: ");
                    String contactNo = reader.readLine();

                    records.add(updateID + "," + fullname + "," + age + "," + email + "," + contactNo);
                    found = true;
                } else {
                    records.add(line);
                }
            }
        }

        if (found) {
            saveListToFile(records);
            System.out.println("[+] Record updated successfully.");
        } else {
            System.out.println("[X] Record not found.");
        }
    }

    /**
     * Delete a record by ID.
     */
    private static void deleteRecordByID(BufferedReader reader) throws IOException {
        System.out.print("\nEnter ID to delete: ");
        String deleteID = reader.readLine();

        File file = new File(FILE_NAME);
        if (!file.exists()) return;

        List<String> records = new ArrayList<>();
        boolean found = false;

        try (BufferedReader fileReader = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = fileReader.readLine()) != null) {
                String[] record = line.split(",");
                if (record[0].equals(deleteID)) {
                    found = true;
                } else {
                    records.add(line);
                }
            }
        }

        if (found) {
            saveListToFile(records);
            System.out.println("[+] Record deleted successfully.");
        } else {
            System.out.println("[X] Record not found.");
        }
    }

    /**
     * View all contents of the file.
     */
    private static void viewFileContents() {
        File file = new File(FILE_NAME);
        if (file.exists()) {
            try (BufferedReader fileReader = new BufferedReader(new FileReader(file))) {
                String line;
                System.out.println("\n--- Current File Content ---");
                System.out.println("ID | NAME | AGE | EMAIL | CONTACT");
                System.out.println("---------------------------------");
                while ((line = fileReader.readLine()) != null) {
                    System.out.println(line);
                }
            } catch (IOException e) {
                System.out.println("[X] Error: " + e.getMessage());
            }
        } else {
            System.out.println("[X] File does not exist.");
        }
    }

    // Helper method to save list back to file
    private static void saveListToFile(List<String> records) throws IOException {
        try (FileWriter writer = new FileWriter(FILE_NAME)) {
            for (String record : records) {
                writer.write(record + "\n");
            }
        }
    }

    // Helper method to print record nicely
    private static void displayRecord(String[] record) {
        System.out.println("ID      : " + record[0]);
        System.out.println("Name    : " + record[1]);
        System.out.println("Age     : " + record[2]);
        System.out.println("Email   : " + record[3]);
        System.out.println("Contact : " + record[4]);
    }
}