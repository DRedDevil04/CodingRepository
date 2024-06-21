import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static boolean runTestCase(String programPath, String input, String expectedOutput) {
        try {
            Process process = Runtime.getRuntime().exec("java " + programPath);
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));

            // Provide input to the executed program
            process.getOutputStream().write(input.getBytes());
            process.getOutputStream().close(); // Close the input stream to indicate end of input

            // Read output from the executed program
            StringBuilder output = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                output.append(line).append("\n");
            }
            System.out.println("Expected Output "+expectedOutput);
            System.out.println("Actual Output "+output);
            // Wait for the process to finish
            process.waitFor();

            // Compare output with expected output
            return output.toString().trim().equals(expectedOutput.trim());
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            return false;
        }
    }

    public static void main(String[] args) {
        String programPath = "/Users/devam/Programs/IIT2022035/SE/labTest/Program.java"; // Assuming the program is in the same directory

        try (BufferedReader csvReader = new BufferedReader(new FileReader("/Users/devam/Programs/IIT2022035/SE/labTest/test_cases.csv"))) {
            String line;
            while ((line = csvReader.readLine()) != null) {
                // Split the line by comma to separate input and expected output
                String[] data = line.split(",");
//                System.out.println(data);
                int n = Integer.parseInt(data[0]);
                String input = "";
                int i = 0;
                for(; i<=(n*3) ; i++){
                    input+=(data[i]+' ');
                }
//                System.out.println(data);
                String expectedOutput = data[i];

                if (runTestCase(programPath, input + "\n", expectedOutput)) {
                    System.out.println("Test case: PASSED");
                } else {
                    System.out.println("Test case: FAILED");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
