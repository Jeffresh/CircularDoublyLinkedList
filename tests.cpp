#include "cdllist.hpp"
#include <iostream>


int main()
{
	CD_Linked_List<int> CDLL;

	CD_Linked_List<int>::position p = CDLL.ini_pos();

	CDLL.insert(1,p);
	CDLL.next(p);



	

	// for(int i = 0; i<10; i++)
	// {
	// 	// std::cout<<CDLL.element(p);
	// 	// p= CDLL.next(p);
	// }

}