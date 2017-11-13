package cellularData;

/**
 *  Represents one node holding a country as well as a second node next
 *  For use in a list of countries
 * @author Foothill College, Michael Rosten
 */

public class CountryNode {

    private Country country;
    private CountryNode next;


    /*
   * default constructor
   * sets the corresponding country for this node to the parameter
   * @param country country to be assigned
   * */
    public CountryNode(Country country){
        this.country = country;
    };


    /*
   * default constructor with option to add the next node
   * @param country country to be assigned
   * @countryNode node to be assigned to the next node
   * */
    public CountryNode(Country country, CountryNode countryNode){
        this.country = country;
        this.next = countryNode;
    };



    /*
   * returns the country assigned to this node
   * */
    Country countryGet(){
        return country;
    };



    /*
   * returns the next node after this node
   * */
    CountryNode nodeGet(){
        return next;
    };



    /*
   * setter for next
   * @param next CountryNode to be set as the next node
   * */
    public void setNext(CountryNode next){
        this.next = next;
    };
}
