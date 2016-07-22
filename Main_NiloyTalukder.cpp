// Name : Niloy Talukder Date: 07/24/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Book list class main_NiloyTalukder.cpp

#include<iostream>    
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;

#include"Booklist_NiloyTalukder.h"

int main()
{
	int choice;
	Booklist book_list;

	do{
		//choice
		cout<<"\nWhat would you like to do?\n\n";
		cout<<setw(9)<<"1.  add an element to end of list\n"
			<<setw(9)<<"2.  add an element at a location\n"
			<<setw(9)<<"3.  find an element by ISBN number (linear search)\n"
			<<setw(9)<<"4.  find an element by ISBN number (binary search)\n"
			<<setw(9)<<"5.  delete an element at position\n"
			<<setw(9)<<"6.  delete an element by ISBN number\n"
			<<setw(9)<<"7.  sort the list (using selection sort)\n"
			<<setw(9)<<"8.  sort the list (using bubble sort)\n"
			<<setw(9)<<"9.  print the list\n"
			<<setw(9)<<"0.  exit\n\n";

		cout<<"Your choice--";
		cin>>choice;

		switch(choice)
		{
		case(0): //exit
			break;
		case(1): //add an element to end of list
			book_list.insert();
			continue;
		case(2): //add an element at a location
			book_list.insert_at();
			continue;
		case(3): //find an element by ISBN number (linear search)
			book_list.find_linear();
			continue;
		case(4): //find an element by ISBN number (binary search)
			book_list.find_binary();
			continue;
		case(5): //delete an element at position
			book_list.delete_item_position();
			continue;
		case(6): //delete an element by ISBN number
			book_list.delete_item_isbn();
			continue;
		case(7): //sort the list (using selection sort)
			book_list.sort_list_selection();
			continue;
		case(8): //sort the list (using bubble sort)
			book_list.sort_list_bubble();
			continue;
		case(9): //print
			book_list.print();
			continue;
		default:
			cout<<"\nInvalid choice";
			continue;
		}
	}while(choice!=0);

	return 0; //program terminated successfully
}
