#ifndef CIRCULAR_DOUBLY_LINKED_LIST_HPP
#define CIRCULAR_DOUBLY_LINKED_LIST_HPP

#include<cassert>

template<typename T>
class CD_Linked_List
{

	struct node;


public:


	typedef node* position;
	static const position NULL_POS;

	CD_Linked_List();
	CD_Linked_List(const CD_Linked_List<T>&);
	CD_Linked_List<T>& operator =(const CD_Linked_List<T>&);

	position ini_pos();

	void insert(const T&,position);
	void del(position);

	T& element(position);
	T element(position)const;

	position search(const T&) const;
	position next(position)const;
	position back(position)const;



private:

	struct node
	{
		node *next,*back;
		T elt;

		node(const T& e, node* n = 0 , node* b = 0): elt{e},next{n},back{b}{}

	};

	node *L;

	void copy(const CD_Linked_List<T>&);



};




#endif