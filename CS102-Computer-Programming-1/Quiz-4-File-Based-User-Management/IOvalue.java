import java.io.*;

public class IOvalue {
    // Constant file name used throughout the program
    private static final String FILE_NAME = "user_data.txt";

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Menu-driven loop for file operations
        while (true) {
            displayMenu();
            String choice = reader.readLine().toUpperCase();

            // Handle empty input to prevent errors
            if (choice.isEmpty()) continue;

            switch (choice) {
                case "C":
                    createFile();
                    break;
                case "W":
                    writeDataToFile(reader);
                    break;
                case "D":
                    deleteFile();
                    break;
                case "V":
                    viewFileContents();
                    break;
                case "E":
                    System.out.println("\n[!] Exiting system...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("\n[X] Invalid choice. Please try again.");
            }
        }
    }

    /**
     * Display the application menu
     */
    private static void displayMenu() {
        System.out.println("\n============================");
        System.out.println("      FILE I/O MANAGER");
        System.out.println("============================");
        System.out.println("C - Create File");
        System.out.println("W - Write Data to File");
        System.out.println("D - Delete File");
        System.out.println("V - View File Contents");
        System.out.println("E - Exit System");
        System.out.println("----------------------------");
        System.out.print("Enter your choice: ");
    }

    /**
     * Creates a new file if it doesn't already exist
     */
    private static void createFile() {
        File file = new File(FILE_NAME);
        try {
            if (file.createNewFile()) {
                System.out.println("\n[+] File created successfully: " + FILE_NAME);
            } else {
                System.out.println("\n[!] File already exists.");
            }
        } catch (IOException e) {
            System.out.println("\n[X] Error while creating the file: " + e.getMessage());
        }
    }

    /**
     * Writes user input data to the file using append mode
     */
    private static void writeDataToFile(BufferedReader reader) throws IOException {
        System.out.println("\n--- Input User Data ---");
        System.out.print("Enter ID: ");
        String id = reader.readLine();

        System.out.print("Enter Fullname: ");
        String fullname = reader.readLine();

        System.out.print("Enter Age: ");
        String age = reader.readLine();

        System.out.print("Enter Email Address: ");
        String email = reader.readLine();

        System.out.print("Enter Contact Number: ");
        String contactNo = reader.readLine();

        // FileWriter with 'true' enables append mode so old data isn't deleted
        try (FileWriter writer = new FileWriter(FILE_NAME, true)) { 
            writer.write("ID             : " + id + "\n");
            writer.write("Fullname       : " + fullname + "\n");
            writer.write("Age            : " + age + "\n");
            writer.write("Email Address  : " + email + "\n");
            writer.write("Contact Number : " + contactNo + "\n");
            writer.write("-----------------------------\n");
            System.out.println("\n[+] Data written to file successfully.");
        } catch (IOException e) {
            System.out.println("\n[X] Error while writing to the file: " + e.getMessage());
        }
    }

    /**
     * Deletes the file if it exists
     */
    private static void deleteFile() {
        File file = new File(FILE_NAME);
        if (file.exists()) {
            if (file.delete()) {
                System.out.println("\n[+] File '" + FILE_NAME + "' deleted successfully.");
            } else {
                System.out.println("\n[X] Failed to delete the file.");
            }
        } else {
            System.out.println("\n[!] File does not exist.");
        }
    }

    /**
     * Displays the contents of the file if it exists
     */
    private static void viewFileContents() {
        File file = new File(FILE_NAME);
        if (file.exists()) {
            try (BufferedReader fileReader = new BufferedReader(new FileReader(file))) {
                String line;
                System.out.println("\n--- Current File Contents ---");
                System.out.println("-----------------------------");
                while ((line = fileReader.readLine()) != null) {
                    System.out.println(line);
                }
                System.out.println("--- End of File ---");
            } catch (IOException e) {
                System.out.println("\n[X] Error while reading the file: " + e.getMessage());
            }
        } else {
            System.out.println("\n[!] File does not exist. Create one first.");
        }
    }
}