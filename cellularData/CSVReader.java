package cellularData;
import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;

/*
* Reads and interprets CSV files containing cellular data for countries in a certain format
*
* @author Foothill College, Michael Rosten
* */


    public class CSVReader {
        private Scanner inputLines;
        private int numCountries;
        private String [] countryNames;
        private String [] lineCollector;
        private int [] yearLabels;
        private double [][] dataTable;
        private int totalYears;
        private ArrayList<String> allLines = new ArrayList<>();


        /**
         * collects and reads lines from a csv file, and arranges them into an array
         * @param filename  name of file to be read
         */
        public CSVReader(String filename) {
            File infile = new File(filename);
            try {
                inputLines = new Scanner(infile);
            } catch (java.io.FileNotFoundException e) {
                System.out.println("File " + filename + " not found!");
            }
            while (inputLines.hasNextLine()) {
                String line = inputLines.nextLine();
                allLines.add(line);
            }
            lineCollector = allLines.toArray(new String[allLines.size()]);
            String[] testLine = lineCollector[1].split(",");
            numCountries = Integer.parseInt(testLine[1]);
            String[] testLineTwo = lineCollector[2].split(",");
            totalYears = testLineTwo.length - 1;
            countryNames = new String[numCountries];
            yearLabels = new int[totalYears];
            dataTable = new double[numCountries+1][totalYears];

        }


        /*
        * puts all the country names into the proper array in order
        * tests for quoted names and deals with them accordingly
        * */
        public String [] getCountryNames(){
            int count = 0;
            for (int i = 3; i < lineCollector.length;i++){
                String[] quoteTest;

                quoteTest = lineCollector[i].split("[\"]");
                if (quoteTest.length > 1){
                    lineCollector[i] = quoteTest[2];
                    countryNames[count] = quoteTest[1];
                    count++;
                } else if (quoteTest.length == 1){
                    String[] testLine = lineCollector[i].split(",");
                    countryNames[count] = testLine[0];
                    count++;
                }
            }

            return countryNames;
        }


        /*
        * Collects the yearlabels from the lines and puts them into an array
        * */
        public int [] getYearLabels(){
            String [] testLine = lineCollector[2].split(",");
            for (int x = 0; x < yearLabels.length; x++) {
                yearLabels[x] = Integer.parseInt(testLine[x+1]);
            }
            return yearLabels;
        }



        /*
        * returns the completed datatable containing all the cellular data
        * */
        public double [][] getParsedTable() {
            for (int i = 3; i < numCountries + 3; i++) {
                String[] testLine = lineCollector[i].split(",");
                    for (int x = 1; x < testLine.length; x++) {
                        dataTable[i - 3][x-1] = Double.parseDouble(testLine[x]);
                    }
                }
            return dataTable;
        }


        /*
        * returns the number of years total
        * */
        public int getNumberOfYears() { return yearLabels.length; }


}
