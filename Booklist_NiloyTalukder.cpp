// Name : Niloy Talukder Date: 07/24/2015
// Course: 16:332:503, PM for Financial Applications and Numerical Computing.
// HW July 20: HW_Book list class Booklist_NiloyTalukder.cpp

// Member-function definitions for class Booklist.
#include<iostream>    
using std::cin;
using std::cout;
using std::endl;

#include<iomanip>
using std::setw;

// include definition of class Booklict from Booklist_NiloyTalukder.h
#include "Booklist_NiloyTalukder.h"

// Booklist constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
Booklist::Booklist() 
{
	size=20; //maximum list length is declared
	sorted=0; //initially not sorted
	num_in_list=0; //no element at beginning
	cout<<"Welcome to the Booklist program\n\n";
} //end booklist constructor

// Booklist destructor
Booklist::~Booklist()
{
	cout<<"\nEnd of Booklist program\n\n";
}//end of Booklist destructor

//insert at end function
void Booklist::insert()
{
	if(num_in_list==size) //check whether book list is full
				cout<<"Book list is full\n\n";
	else {
		    //ask for new element
		    cout<<"\nPlease type in the element you want to add in the list:\n";
			cin >> new_element;

	        mylist[num_in_list] = new_element; //putting element at end
	        ++num_in_list; //increasing list size by 1

	        //print list
	        cout<<"\nYour list is now:\n";
		    for(int i=0; i<num_in_list; i++)
			     cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
            cout<<"\n\n";

			sorted=0; //any element added sort flag goes to zero

			/*if(mylist[num_in_list]>mylist[num_in_list-1]&&sorted==1)
	             sorted=1;
	        else sorted=0;*/

	}

} //end of insert at end function

//add an element at a location
void Booklist::insert_at()
{
	if(num_in_list==size) //check whether book list is full
		cout<<"\nBook list is full\n\n";
	else {
		//ask for new element and its position
		cout<<"\nPlease type in the element you want to add:\n";
		cin >> new_element;
		cout<<"\nAt what position?\n";
		cin >> at_position;

		if(at_position<=(num_in_list+1))
		{
           for(int i=num_in_list; i>(at_position-1); i--)
		       mylist[i]=mylist[i-1];

	       mylist[at_position-1] = new_element; //putting new element at position
	       ++num_in_list; //increasing list size by 1

	       //print list
	       cout<<"\nYour list is now:\n";
		   for(int i=0; i<num_in_list; i++)
			   cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
           cout<<"\n\n";

		   sorted=0;  //any element added sort flag goes to zero

	       /*if((mylist[at_position-2]<mylist[at_position-1])&&(mylist[at_position-1]<mylist[at_position])&&(sorted==1))
	           sorted=1;
		   else if((at_position==num_in_list)&&mylist[num_in_list]>mylist[num_in_list-1]&&(sorted==1)) sorted=1;
	       else sorted=0;*/

		} else {
				cout<<"Out of range\n"; //not valid position
				//print list
	            cout<<"\nYour list is now:\n";
		        for(int i=0; i<num_in_list; i++)
			        cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
                cout<<"\n\n";
		}

	}

} //end of insert at location function

//find an element by ISBN number (linear search)
void Booklist::find_linear()
{
	//ask for element to search
	int found=0;
	cout<<"\nPlease type in the element to find by ISBN number(linear search):\n";
	cin >> new_element;//storing the element

	for(int j=0; j<num_in_list; j++)
	{
		if(mylist[j]==new_element){
			cout<<"\nSearching element is at position "<<j+1<<" in the Book list\n"; //if found print the position
			found=1;
		    break;
		} 
		
	}	
	if(found==0)
	   cout<<"\nElement not found in the Book list\n"; //element not found
} //end of find_linear function


//find an element by ISBN number (binary search)
void Booklist::find_binary()
{
	if(sorted==0)
	    cout<<"\nBook list is not sorted";
    else{
		int found=0;
	    //ask for element to search
		cout<<"\nPlease type in the element to find by ISBN number(binary search):\n";
	    cin >> new_element;

		int middle, low=0, high=num_in_list-1;

		while(low<=high){
			// determine middle element of subarray being searched
			middle=(low+high)/2;

			// if search element  matches middle element, return middle
			if(new_element == mylist[middle]){
				cout<<"\nSearching element is at position "<<middle+1<<" in the Book list\n"; //if found print the position
				found=1;
				break;
			}
			else{
				if(new_element<mylist[middle]) // if search element less than middle element, 
                // set new high element
					high=middle-1;
				else low=middle+1; //if element greater than middle element, 
                                  // set new low element
			}
		}

		if(found==0)
		   cout<<"\nElement not found in the Book list\n"; //element not found

	}
} //end of find_binary function


//delete an element at position
void Booklist::delete_item_position()
{
	if (num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else {

		//ask for element position that one to delete
		cout<<"\nAt what position you want to delete element?\n";
		cin >> at_position;
		if(at_position<=num_in_list){
            //shifting elements from the end towards left until delete position
	        for(int i=at_position; i<num_in_list; i++)
		         mylist[i-1]=mylist[i];

	        num_in_list--; //decrease list size by 1

	        //print list
	        cout<<"Your list is now:\n";
		    for(int i=0; i<num_in_list; i++)
			    cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
            cout<<"\n\n";
		} else cout<<"No element at that position";
	}
} //end of delete_item_position function

//delete an element by ISBN number
void Booklist::delete_item_isbn()
{
	if (num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else {
		int found=0;
		//ask for element to delete
	    cout<<"\nPlease type in the element ISBN number you want to delete:\n";
	    cin >> new_element;//storing the element

		for(int j=0; j<num_in_list; j++)
	    {
		    if(mylist[j]==new_element){
				at_position=j+1;
				//shifting elements from the end towards left until delete position
	            for(int i=at_position; i<num_in_list; i++)
		            mylist[i-1]=mylist[i];
			
	            num_in_list--; //decrease list size by 1

				found=1;

				//print list
	            cout<<"Your list is now:\n";
		        for(int i=0; i<num_in_list; i++)
			    cout<<setw(9)<<i+1<<".   "<<mylist[i]<<endl;
                cout<<"\n\n";

				break;
			}
       } 

	if(found==0)
	   cout<<"\nElement not found in the Book list\n"; //element not found
   }

}//end of delete_item_isbn function

//sort the list (using selection sort)
void Booklist::sort_list_selection()
{
	if (num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else{
		int i, j, sm_index; 
	    long long int temp;

	    for(i=0; i<num_in_list-1; i++) // num_in_list-1 = number of passes
	    {
		    sm_index=i;

		    for(j=i+1; j<num_in_list; j++)
		    {
			    if(*(mylist+j)<*(mylist+sm_index))
				    sm_index=j;
		    }

		    if(sm_index!=i)
		    {
			   temp=*(mylist+i);
			   *(mylist+i)=*(mylist+sm_index);
			   *(mylist+sm_index)=temp;
		    }

		}
	

	    sorted=1;

	    //print list
	    cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<*(mylist+i)<<endl;
        cout<<"\n\n";
	}

} //end of selection sort function

//sort the list (using bubble sort)
void Booklist::sort_list_bubble()
{
	if(num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else{
		long long int hold;
	    bool flag=1;

	    //loop to control no. of passes
	    for(int pass=0; pass<(num_in_list-1) && flag; pass++)
	    {
		   flag=0;
		   //loop to control no. of comparisons per pass
		   for(int j=0; j<num_in_list-1; j++)
		   {
			   //comparison side by side element and swap them if fitrst element is greater than the second one
			   if(*(mylist+j)>*(mylist+j+1))
			   {
				   hold=*(mylist+j);
				   *(mylist+j)= *(mylist+j+1);
				   *(mylist+j+1)=hold;
				   flag=1; //set flag since swap occured
			   }
		   }
	     }

	sorted=1;
	//print list
	cout<<"\nYour list is now:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".   "<<*(mylist+i)<<endl;
    cout<<"\n\n";

	}
} //end of bubble sort function

//print function
void Booklist::print()
{
	if (num_in_list==0) //lowest bound of list checking
		cout<<"\nNo element in the Book list\n\n";
	else { 
		cout<<"\nThe book list is:\n";
		for(int i=0; i<num_in_list; i++)
			cout<<setw(9)<<i+1<<".  "<<mylist[i]<<endl;

		cout<<"\n";
	}
}//end of print function