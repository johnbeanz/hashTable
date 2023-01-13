//Simple Hash Table
#include <iostream>
#include <cstdlib>
#include <list>
#include <cstring>

class HashTable{
    
    private:
        int buckets;
        std::list<int> *table;// pointer to array that stores the buckets

    public:
        //constructor
        HashTable(int constructor);
        
        //insert into hashtable
        void insert(int x);

        int hashSlingingSlasher(int x){

            return (x % buckets);

        }//end hashslingingslasher
        
        void printHash(); //print hashtable

};//end hashtable declaration

HashTable::HashTable(int b){
    this->buckets = b;
    table = new std::list<int>[buckets];
}
void HashTable::insert(int key){
    
    int index = hashSlingingSlasher(key);
    //find key by indexing the list, if key is found remove it, else throw error
    std::list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == key){
            break;
        }//end if
    }//end for
    
    if(i != table[index].end()){
        table[index].erase(i);
    }//end if
    else{
        table[index].push_back(key);
    }//end else

}//end insert

//print hash table function
    void HashTable::printHash(){
    
    int userChoice;
    std::cout<<"Select a number 1-10 to view results"<<std::endl;
    std::cin>>userChoice;
    
    //this for loop will print only the users choice, and its corresponding table
    for(int i = userChoice - 1; i < userChoice; i++){
        std::cout<<i;
        for(auto x : table[i]){

            std::cout<<" --> "<<x;

        }//end for
        std::cout<<std::endl;
    }//end for
}//end print


int main(){
    int counter = 0; 
    //create our hashtable with amount of buckets to be 10
    HashTable h(10);

    srand(time(NULL));//using a seed so the results will vary


    for(counter = 0; counter < 1000; counter++){
        int randomNum;

        randomNum = 10 + (std::rand() % (99 - 10 + 1));//generate this way so the numbers are between 10-99
        //std::cout<<randomNum<<std::endl;
        h.insert(randomNum);
        
        //sort and delete duplicates from the hash table
    }//end for
    
    h.printHash();

    return 0;
}//end main
