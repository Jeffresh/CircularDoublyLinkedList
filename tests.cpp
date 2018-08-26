#include "cdllist.hpp"
#include <iostream>


int main()
{
	CD_Linked_List<int> CDLL{};

	CD_Linked_List<int>::position p = CDLL.ini_pos();


	for(int i = 0; i<10; i++)
	{
		CDLL.insert(i,p);
	}

	for(int i = 0; i<10; i++)
	{
		std::cout<<CDLL.element(p);
		p= CDLL.next(p);
	}

}