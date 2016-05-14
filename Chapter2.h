#ifndef CHAPTER2_H
#define CHAPTER2_H
#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
template<class T> class ForwardList;
template<class T> struct Node;
template<class T>
void intersection(ForwardList<T>&,ForwardList<T>& );
template<class T> std::ostream& operator<<(std::ostream& ,  ForwardList<T> &);


template<class T>
class ForwardList{
	friend void intersection<>(ForwardList&, ForwardList&);
	friend std::ostream& operator<< <>(std::ostream& os, ForwardList &);


private:
	int size;
	struct Node{
		T data;
		Node* next;
	};
	Node* Start = NULL;
	Node* createNode(const T& data){
		Node* temp = new Node;
		temp -> data = data;
		temp -> next = NULL;
		return temp;
		};
	void checkingRecursivelyPalindrome(bool &, Node *, Node *&);

public:
	ForwardList():size(0){};
	~ForwardList();

	//ForwardList& operator=(const ForwardList&);
	Node* Head(){return Start;};
	const T& topValue(){return Start->data;};
	std::size_t Size(){return size;};
	std::ostream& displayList(std::ostream& );
	ForwardList& addNode_front(const T& );
	ForwardList& addNode_back(const T& );
	ForwardList& addNode(const T&, const int&);
	ForwardList& deleteNode_front();
	ForwardList& deleteNode_back();
	ForwardList& deleteNode(const int&);
	ForwardList& reverseIterative();
	ForwardList& reverseRecursiveFunction(Node *p );
	ForwardList& reverseRecursive(){return reverseRecursiveFunction(Start);}
	ForwardList& removeDupsWithBuffer();
	ForwardList& removeDupsWithoutBuffer();
	ForwardList& NthtoLAst(const std::size_t &);
	void NthtoLast(Node*, const std::size_t  &, std::size_t &);
	ForwardList& NthtoLAST(const std::size_t & k);
	ForwardList& sumReverseOrder(ForwardList &, ForwardList &);
	ForwardList& sumForwardOrder(ForwardList &, ForwardList &);
	void ReversesumForward(Node * , Node *, T & );
	void RunnerTechnique();
	bool isPalindrome();
	Node* tail(){Node* temp =Start;	while(temp -> next != NULL)	temp = temp -> next; return temp;};
	bool loopdetection();
	ForwardList& loopHead();

};

template<class T>
ForwardList<T>& ForwardList<T>::loopHead()
{
	Node* slow = Start;
	Node* fast = Start;
	while(fast!= NULL && fast -> next != NULL)
		{
			slow->next;
			fast -> next -> next;
			if(slow == fast)
				break;
		}
	if(fast == NULL)
	{
		std::cout<<"NO LOOP DETECTED"<<std::endl;
		return *this;
	}

	slow = Start;
	while(slow != fast)
	{
		slow = slow -> next;
		fast = fast -> next;
	}
	std::cout<<"HEAD OF LOOP : "<< fast -> data<<std::endl;
return *this;
}

template<class T>
bool ForwardList<T>::loopdetection()
{
	Node* slow = Start;
	Node* fast = Start;
	while(fast!= NULL && fast -> next != NULL)
	{
		slow = slow->next;
		fast -> next -> next;
		if(slow == fast)
			return true;
	}
return false;
}

template<class T>
void intersection(ForwardList<T>& a, ForwardList<T>& b)
{
	std::size_t sizeA = a.Size();
	std::size_t sizeB = b.Size();
	if(a.tail() != b.tail())
	{
		std::cout<<"NO INTERSECTION"<<std::endl;
		return ;
	}
	decltype(a.Head()) HeadA = a.Head();
	decltype(a.Head()) HeadB = b.Head();
	if(sizeA > sizeB)
	{
		for(std::size_t i=0 ;i != (sizeA - sizeB); ++i)
			HeadA =HeadA -> next;
	}
	else if(sizeA < sizeB)
	{
		for(std::size_t i=0 ;i != (sizeB - sizeA); ++i)
					HeadB =HeadB -> next;
	}

	while( HeadB != NULL && HeadA != NULL)
	{
		if (HeadB == HeadA)
		{
			std::cout<<"FOUND INTERSECTION  : "<< HeadA -> data << std::endl;
			return;
		}
	}
	std::cout<<"NO INTERSECTION"<<std::endl;
	return;

}


template<class T>
bool ForwardList<T>::isPalindrome()
{
bool palindrome =true;
Node *q;
checkingRecursivelyPalindrome(palindrome, Start, q );
return palindrome;
}

template<class T>
void ForwardList<T>::checkingRecursivelyPalindrome(bool &palindrome, Node *p, Node *& q )
{
	if(p == NULL)
	{
		q = Start;
		return;
	}
	checkingRecursivelyPalindrome(palindrome, p->next, q);
	if(!palindrome) return ;
	if(p-> data != q-> data) palindrome = false;
	q = q-> next;
	return;
}

template<class T>
ForwardList<T>& ForwardList<T>::sumForwardOrder(ForwardList<T> &a1, ForwardList<T> &a2)
{
	std::size_t l1 = a1.Size();
	std::size_t l2 = a2.Size();
	if(l1 < l2 )
	{
		for(std::size_t i=0; i!= l2 -l1 ; ++i)
		{
			a1.addNode_front(0);
		}
	}
	else if(l1 > l2 )
		{
			for(std::size_t i=0; i!= l1 -l2 ; ++i)
			{
				a2.addNode_front(0);
			}
		}
	Node *a = a1.Head();
	Node *b = a2.Head();
	T carry = 0;
	ReversesumForward( a, b, carry);
	if(carry != 0)
			(*this).addNode_front(carry);

	return *this;
}

template<class T>
void ForwardList<T>::ReversesumForward(Node *a, Node *b, T &carry)
{
	if(a == NULL && b == NULL)
	{
		return;
	}
	ReversesumForward(a -> next , b -> next , carry);
	T sum = a -> data + b -> data + carry;
	(*this).addNode_front(sum % 10);
			carry = sum / 10;
}
template<class T>
ForwardList<T>& ForwardList<T>::sumReverseOrder(ForwardList<T> &a1, ForwardList<T> &a2)
{
	Node *a = a1.Head();
	Node *b = a2.Head();
	T carry = 0;
	T sum = 0;
	while( a != NULL || b != NULL)
	{
		if(a != NULL && b != NULL)
		{
			sum = a -> data + b -> data + carry;
			a = a -> next;
			b = b -> next;
			//std::cerr<<"1"<<std::endl;

		}
		else if(a != NULL)
		{
			sum = a -> data + carry;
			a = a -> next;
			//std::cerr<<"2"<<std::endl;
		}
		else if(b!= NULL)
		{
			sum = b -> data + carry;
			b = b -> next;
			//std::cerr<<"3"<<std::endl;
		}
		carry = sum/ 10;
	(*this).addNode_back(sum % 10);
	}
	if(carry != 0)
		(*this).addNode_back(carry);


return *this;
}


template<class T>
ForwardList<T>& ForwardList<T>::NthtoLAST(const std::size_t &k)
{
	Node *p1 = Start;
	Node *p2 = Start;
	for(std::size_t i=0; i!=k; ++i)
	{
		if(p2==NULL)
		{
			std::cout<<"OUT OF BONDS"<<std::endl;
			return *this;
		}
		p2 = p2 -> next;
	}

	while(p2!=NULL)
	{
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	std::cout<<p1->data<<std::endl;

return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::NthtoLAst(const std::size_t &k)
{
	std::size_t i=0;
	NthtoLast(Start, k, i);
	return *this;
}

template<class T>
void ForwardList<T>::NthtoLast(Node* N, const std::size_t &k, std::size_t &i)
{
	if(N == NULL)
		return;
	NthtoLast(N -> next, k, i);
	++i;
	if(i == k)
		std::cout<< N->data<<std::endl;
	return;
}

template<class T>
ForwardList<T>& ForwardList<T>::removeDupsWithoutBuffer()
{
	Node *curr1 = Start ;
	while( curr1 != NULL)
	{
		Node  *curr2 = curr1 -> next;
		Node* prev = curr1;
		while(curr2 != NULL)
		{
			if(curr1 -> data == curr2 -> data)
			{
				Node *temp = curr2;
				prev -> next = curr2 -> next;
				curr2 = curr2 -> next;
				delete temp;
			}
			else
			{
				prev = curr2;
				curr2 = curr2-> next;
			}
		}
		curr1 = curr1 -> next;
	}
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::removeDupsWithBuffer()
{
	if(Start == NULL)
	{
		std::cerr<<"LIST IS EMPTY"<<std::endl;
		return *this;
	}

	bool *p = new bool[128];
	Node *curr = Start;
	Node *prev = NULL;
	while(curr != NULL)
	{
		int index =static_cast<int>(curr -> data);
		if( !p [index])
		{
			p[index] = true;
			prev=curr;
			curr = curr->next;

		}
		else if(p[index])
		{
			Node * temp = curr;
			prev->next = curr -> next;
			curr = curr -> next;
			delete temp;

		}

	}

	return *this;
}



template<class T>
ForwardList<T>::~ForwardList()
{
while(size>0)
{
	deleteNode_front();
	--size;
	}
}



template<class T>
std::ostream& ForwardList<T>::displayList(std::ostream& os)
{
	Node* ptr = Start;
    while (ptr!=NULL)
    {
        os<<ptr->data<<" ";

        ptr=ptr->next;
    }
    return os;
}
/*
template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwadList& rhs)
{
	ForwardList lhs;
	Node* head = rhs.Head();
	while()
return *this;
}
*/
template<class T>
ForwardList<T>& ForwardList<T>::addNode_front(const T& value)
{
    ++size;
	Node* temp = createNode(value);
    if(Start == NULL)
    {
        Start = temp;
    }
    else
    {
        temp -> next=Start;
        Start = temp;
    }
return *this;
}


template<class T>
ForwardList<T>& ForwardList<T>::addNode_back(const T& value)
{
    ++size;
	Node* temp = createNode(value);
    if(Start == NULL)
    {
        Start = temp;
    }
    else
    {
    	Node* temp1 = Start;
    	while(temp1 -> next != NULL)
   	        {
  	           temp1 = temp1 -> next;
   	        }
        temp1 -> next = temp;
    }
    return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::addNode(const T& value, const int& place)
{
Node* temp = createNode(value);
if(Start == NULL)
    {
	++size;
	std::cerr<<"LIST IS EMPTY. Inserting at first"<<std::endl;
    Start = temp;
    }
else
{
	if(place > size)
	{
	std::cout<<"OUT OF RANGE :putting new node at the end "<<std::endl;
	addNode_back(value);
	}
	else if(place==1)
    {
	std::cout<<"OUT OF RANGE :putting new node at the front "<<std::endl;
	addNode_front(value);
    }
	else
	    {
		++size;
        int count = 1;
	        Node* temp1 = Start;
	        while(temp1 -> next != NULL && count != (place-1))
	        {
	            ++count;
	            temp1=temp1->next;
	        }
	        temp->next = temp1->next;
	        temp1->next = temp;
	    }
}
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode_front()
{
    if (Start == NULL)
    {
        std::cout<<"LIST is empty"<<std::endl;
    }
    else
    {
    	--size;
        Node* temp = Start;
        if(temp->next==NULL)
        {
            delete temp;
            Start = NULL;
        }
        else
        {
            Start = Start->next;
            delete temp;
        }
    }
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode_back()
{
	if (Start == NULL)
	    {
	        std::cout<<"LIST is empty"<<std::endl;
	    }
	    else
	    {
	    	--size;
	        Node* temp1= Start, *temp2;
	        if(temp1->next == NULL)
	        {
	            delete temp1;
	            Start = NULL;
	        }
	        else
	        {
	            while(temp1->next != NULL)
	            {
	                temp2 = temp1;
	                temp1 = temp1->next;
	            }
	            temp2->next = NULL;
	            delete temp1;
	        }
	    }
	return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::deleteNode(const int& place)
{
	if (Start == NULL)
		    {
		        std::cout<<"LIST is empty"<<std::endl;
		    }
	else
	{
		if(place ==1)
		{
		    deleteNode_front();
		}
		else if(place>=size)
		{
		    deleteNode_back();
		}
		else
		{
			--size;
			int count = 0;
			Node* temp1=Start, *temp2;
			while(temp1->next != NULL && count == (place-1))
			{
				temp1=temp1->next;
				++count;
			}
			temp2=temp1->next;
			temp1->next=temp2->next;
			delete temp2;
		}
	}
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::reverseIterative()
{
	Node *prev, *curr, *next;
	curr = Start;
	prev = NULL;
	while(curr != NULL)
	{
		next= curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	Start = prev;
return *this;
}

template<class T>
ForwardList<T>& ForwardList<T>::reverseRecursiveFunction(Node * p )
{
if(p-> next == NULL)
{
Start = p;
return *this;
}
	reverseRecursiveFunction(p->next);
	Node *q = p->next;
	q->next = p;
	p->next = NULL;
	return *this;
}

template<class T>
void ForwardList<T>::RunnerTechnique()
{
	Node *p1 = Start;
	Node *p2 = Start;
	while(p2 -> next != NULL)
	{
		p1 = p1 -> next;
		p2 = p2 -> next;
		if(p2 -> next != NULL)
				p2 = p2 -> next;
	}
	//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;
	p2 =Start;
	//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;

	while(p1 != NULL)
	{
		//std::cout<<p1-> data<< " "<< p2 -> data<<std::endl;

		Node *temp = p2 -> next;
		p2 -> next = p1;
		p1 = p1 -> next;
		if(p1 != NULL)
		{
			(p2 -> next) -> next = temp;
			p2 =temp;
		}

	}
}
template<class T>
inline std::ostream& operator<<(std::ostream& os, ForwardList<T> &d)
{
	d.displayList(os);
return os;
}



#endif
