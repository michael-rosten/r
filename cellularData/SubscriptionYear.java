package cellularData;
/*
*   simple object that stores an int year and a double subscriptions
*
*   @author Foothill College, Michael Rosten
* */

public class SubscriptionYear {
    private int year;
    private double subscriptions;

    /*
    * constructor, assigns a year and subscriptions value
    * @param year sets year
    * @param subscriptions subscription to set
    * */
    public SubscriptionYear(int year, double subscriptions){
        this.year = year;
        this.subscriptions = subscriptions;
    }
    /*
    * returns the year
    * */
    public int getYear(){
        return year;
    }
    /*
    * returns the subscriptions
    * */
    public double getSubscriptions(){
        return subscriptions;
    }
    /*
    * sets the private variable year
    * @param year year to set
    * */
    public void setYear(int year){
         this.year = year;
    }
    /*
    * returns the private variable subscriptions
    * @param subscriptions subscriptions to set
    * */
    public void setSubscriptions(double subscriptions){
        this.subscriptions = subscriptions;
    }
    /*
    * returns a string containing all the data in subscriptionyear
    * */
    public String toString(){
        String subString;
        subString = Integer.toString(year);
        subString = subString + "\t";
        subString = Double.toString(subscriptions);
        return subString;
    }

}
