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


	position ini_pos()const;

	void insert(const T&,position);
	void del(position);

	T& element(position);
	T element(position)const;

	position search(const T&) const;
	position next(position)const;
	position back(position)const;

	~CD_Linked_List();



private:

	struct node
	{
		node *next,*back;
		T elt;

		node(const T& e, node *n = 0 , node *b = 0): elt{e},next{n},back{b}{}

	};

	node *L;

	void copy(const CD_Linked_List<T>&);



};

template<typename T>
const  typename  CD_Linked_List<T>::position CD_Linked_List<T>::NULL_POS = 0;

template<typename T>
void CD_Linked_List<T>::copy(const CD_Linked_List<T>& l)
{
	if(l.L)
	{
		L= new node((l.L)->elt);
		L->back= L->next = L;

		for(node* r = l.L->next; r!=l.L; r = r->next)
			L->back = L->back->next = new node(r->elt, L->back, L);		



	}

}

template<typename T>
inline CD_Linked_List<T>::CD_Linked_List():L{NULL_POS}{}


template<typename T>
inline CD_Linked_List<T>::CD_Linked_List(const CD_Linked_List<T>& C){ copy(C);}


template<typename T>
inline CD_Linked_List<T>& CD_Linked_List<T>::operator =(const CD_Linked_List<T>& l)
{

	if(L!=&l)
	{
		this->~CD_Linked_List();

		copy(l);

	}


	return *this;


}

template<typename T>
inline typename CD_Linked_List<T>::position CD_Linked_List<T>::ini_pos()const {return L;}


template<typename T>
inline void CD_Linked_List<T>::insert(const T& e, CD_Linked_List<T>::position p)
{

	if(p != NULL_POS)
		p->next=p->next->back = new node(e,p,p->next);
	else
	{
		L= new node(e);
		L->back=L->next=L;
	}
}

template<typename T>
inline void CD_Linked_List<T>::del(CD_Linked_List<T>::position p)
{


	assert(L!= NULL_POS);

	node* q = p->next;


	if(L!=p->next)
	{
		p->next =  q->next;

		L = p->next->back = p;
	}
	else
		L = NULL_POS;

	delete q;
}

template<typename T>
inline  T CD_Linked_List<T>::element(CD_Linked_List<T>::position p)const { assert(L!= NULL_POS);  return p->next->elt;}

template<typename T>
inline T& CD_Linked_List<T>::element(CD_Linked_List<T>::position p){ assert(L!= NULL_POS); return p->next->elt;}

template<typename T>
inline typename CD_Linked_List<T>::position CD_Linked_List<T>::search(const T& e)const
{

	assert(L!=NULL_POS);

	node* q = L->next; bool found = true;

	if(L->elt != e)
	{
		found = false;
		while( found && q!=L)
		{
			if( q->elt ==e)
				found = true;
			else
				q=q->next;
		}

		if(!found)
			q= NULL_POS;

	}

	


	return q;

}

template<typename T>
inline typename CD_Linked_List<T>::position CD_Linked_List<T>::next( CD_Linked_List<T>::position p)const
{
	assert(p!=NULL_POS);

	return p->next;


}

template<typename T>
inline typename CD_Linked_List<T>::position CD_Linked_List<T>::back( CD_Linked_List<T>::position p)const
{
	assert(p!=NULL_POS);

	return p->back;
}

template<typename T>
CD_Linked_List<T>::~CD_Linked_List()
{

	node* q ;

	while(L->next!=L)	
	{
		q=L->next;
		L->next=q->next;
		delete q;
	}


	delete L;



}





#endif