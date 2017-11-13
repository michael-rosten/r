package cellularData;

/*
*   Creates data type country. Has variables name, subscriptions, and count.
*   Stores subscription data for all available years for a specific country.
*   @author Foothill College, Michael Rosten
* */
public class Country {
    private String name;
    private SubscriptionYear[] subscriptions;
    private int count = 0;


    /*
    * default constructor
    * sets name and initializes subscriptionyear array
    * @param name name of country
    * @param numYears number of years
    * */
    public Country(String name, int numYears) {
        this.name = name;
        this.subscriptions = new SubscriptionYear[numYears];

    }
    /*
   * alternate constructor
   * sets name
   * @param name name of country
   * */
    public Country(String name) {
        this.name = name;

    }

    /*
   * overrides equals method for comparing countries
   * removes whitespace and casing from both test cases
   * @param test Country to be compared with this
   * */
    public boolean equals(Country test){

        String trueName = test.getName().replaceAll("\\s+","").toLowerCase();
        String testName = this.getName().replaceAll("\\s+","").toLowerCase();
        return (trueName.equals(testName));

    };

    /*
    * adds a new SubscriptionYear to the SubscriptionYear array
    * @param year year to be added
    * @param subscription subscription to be added
    * */
    public void addSubscriptionYear(int year, double subscription) {
        SubscriptionYear newYear = new SubscriptionYear(year, subscription);
        subscriptions[count] = newYear;
        count++;
    }


    /*
    * returns name of country
    * */
    public String getName() {
        return name;
    }


    /*
    * returns a double that contains the total subscriptions for a year period given
    * also tests for certain exceptions and throws them if applicable
    * @param start year start
    * @param end year end
    * */
    public double getNumSubscriptionsForPeriod(int start, int end) throws IllegalArgumentException {
        String s = "Illegal Argument: Start date is greater than end date.";
        String q = "The start and end year are invalid";
        String r = "The start date of " + start + " is invalid. Instead testing for valid range of "
                + subscriptions[0].getYear() + " to " + subscriptions[subscriptions.length-1].getYear(); ;
        String p = "The end date of " + end + "is invalid. Instead testing for valid range of "
                + subscriptions[0].getYear() + " to " + subscriptions[subscriptions.length-1].getYear();
        if (start >= end){
            throw new IllegalArgumentException(s);
        }
        if ((start < subscriptions[0].getYear()) && (end > subscriptions[subscriptions.length-1].getYear())){
            throw new IllegalArgumentException(q);
        }
        if (start < subscriptions[0].getYear()){
            System.out.println(r);
            start = subscriptions[0].getYear();

        }
        if (end > subscriptions[subscriptions.length-1].getYear()){
            System.out.println(p);
            end = subscriptions[subscriptions.length-1].getYear();
        }
        int startYear = Math.abs(start - subscriptions[0].getYear());
        int totalYears = Math.abs(start - end);
        double totalDouble = 0;
        for (int i = startYear; i < totalYears + startYear + 1; i++) {
            totalDouble = totalDouble + subscriptions[i].getSubscriptions();

        }
        return totalDouble;
    }


    /*
    * returns a string containing relevant information for this country
    * */
    public String toString(){
        String result = "";
        result = result + name;
        for (int i = 0; i < subscriptions.length; i++){
            result = result + "\t" + Double.toString(subscriptions[i].getSubscriptions());
        }
        return result;
    }
}
