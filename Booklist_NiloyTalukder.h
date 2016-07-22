// Name : Niloy Talukder Date: 07/24/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Book list class Booklist_NiloyTalukder.h


//Declaration of class Booklist.               
// Member functions are defined in Booklist_NiloyTalukder.cpp

// prevent multiple inclusions of header file
#ifndef BOOKLIST_NILOYTALUKDER_H
#define BOOKLIST_NILOYTALUKDER_H
  
// Booklist abstract data type definition
class Booklist {

public:
	//function definition
	Booklist(); //constructor
	~Booklist(); //destructor
    void insert(); //add an element to end of list
    void insert_at(); //add an element at a location
    void find_linear(); //find an element by ISBN number (linear search)
    void find_binary(); //find an element by ISBN number (binary search)
    void delete_item_position(); //delete an element at position
    void delete_item_isbn(); //delete an element by ISBN number
    void sort_list_selection(); //sort the list (using selection sort)
    void sort_list_bubble(); //sort the list (using bubble sort)
    void print(); //print

	
private:
	bool sorted; //flag to idicate sorted or not
	int num_in_list, at_position; // variable to store size of the book list
	int size; //maximum size of the book list

	long long int new_element, delete_element, mylist[20]; //variable to store new, delete element and array initialization for the book list

};


#endif

