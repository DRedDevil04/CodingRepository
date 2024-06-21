/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import static java.lang.Integer.parseInt;
import java.util.ArrayList;
import java.util.List;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.params.provider.CsvFileSource;

/**
 *
 * @author devam
 */
public class A3Q4Test {
    
    public A3Q4Test() {
    }
    A3Q4 inst;
    @BeforeEach
    public void setUp() {
        inst=new A3Q4();
        
    }
    
    @AfterEach
    public void tearDown() {
        inst=null;
    }

    /**
     * Test of main method, of class A3Q4.
     */
    

    /**
     * Test of add method, of class A3Q4.
     */
    @Test
    public void testAdd() {
        ArrayList<List<Object>> testCases=readABFromCSV("./atests.csv");
        for(int i=0;i<testCases.size();i++){
               int k;
               k = inst.add((int)testCases.get(i).get(0), (int)testCases.get(i).get(1));
               
               if((int)k==(int)testCases.get(i).get(2)){
                System.out.println("TESTCASE PASSED");
               }
               else{
                System.out.println("TESTCASE FAILED");
               }
        }
        
    }
    
    
    private ArrayList<List<Object>> readABFromCSV(String csvFilePath) {
        ArrayList<List<Object>> tests=new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(csvFilePath))) {
            String line;
            List<Object> mixedList = new ArrayList<>();
            while ((line = br.readLine()) != null) {
                String[] s=line.split(",");
                mixedList.add(parseInt(s[0]));
                mixedList.add(parseInt(s[1]));
                mixedList.add(parseInt(s[2]));
                tests.add(mixedList);
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
        return tests;
    }
     
    
    }
    

