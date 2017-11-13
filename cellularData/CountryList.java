package cellularData;

/**
 *  List data type for nodes representing country objects
 *  Adds countries, and checks if a country exists in the list
 *  Gets the index of a given country
 *
 * @author Foothill College, Michael Rosten
 */

public class CountryList {

    private int size;
    private CountryNode head;

    /*
   * default constructor
   * creates an empty Country list
   * */
    public CountryList(){
        this.size = 0;
        this.head = null;
    };


    /*
   * adds a country to the list
   * creates a node to add and sets the next
   * checks if the current list is empty and acts appropriately
   * @param next Country to be added
   * */
    public void add(Country next){
        CountryNode nextCountry = new CountryNode(next);
        if (this.isEmpty()) {
            head = nextCountry;
            size++;
            return;
        }
        nextCountry.setNext(head);
        head = nextCountry;
        size++;
    };



    /*
   * checks if the list is empty by checking the head
   * */
    public boolean isEmpty(){
        if (this.head == null){
            return true;
        }   else {
            return false;
        }
    };



    /*
   * gets the corresponding country to given index
   * throws exception if index is out of bounds
   * @param index index to be checked
   * */
    Country getIndex(int index) throws IndexOutOfBoundsException{
        String e = "Index out of bounds (too big or too small).";
        if (index < 0){
            throw new IndexOutOfBoundsException(e);
        } else if (index > size){
            throw new IndexOutOfBoundsException(e);
        }
        CountryNode crawler = head;
        int i = 0;
        while(crawler != null && i <= index){
            if (i == index){
                return crawler.countryGet();
            }

            crawler = crawler.nodeGet();
            i++;
        }

        return null;
    };



    /*
   * checks if a given country exists within the list
   * returns the country if it exists
   * @param check country to be checked against the list
   * */
    public Country contains(Country check){
        CountryNode crawler = head;
        int i = 0;
        while(crawler != null && i <= size){
            if (crawler.countryGet().equals(check)){
                return crawler.countryGet();
            }

            crawler = crawler.nodeGet();
            i++;
        }
        return null;
    };



    /*
   * returns the size of the list
   * */
    public int size(){return size;};



    /*
   * overrides default method to convert the list to string
   * adds all countries on the list to a result string
   * */
    public String toString() {
        String result = "";
        CountryNode crawler = head;
        int i = 0;
        while(crawler != null && i <= size){
            result = result + crawler.countryGet().getName() + " ";
            crawler = crawler.nodeGet();
            i++;
        }
        return result;
    }
}
