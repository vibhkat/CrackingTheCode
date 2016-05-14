#ifndef CHAPTER3_H
#define CHAPTER3_H
#include"StackDynamicArray.h"
#include<stack>

template<class T>
void SortStack(std::stack<T>& );


template<class T>
class StackMin{
private:
	Stack<T> main;
	Stack<T> minStack;
public:
	StackMin& push(const T &);
	StackMin& pop();
	T min();
};

template<class T>
StackMin<T>& StackMin<T>::push(const T& temp)
{
	main.push(temp);
	if (minStack.isempty())
	{
		minStack.push(temp);
	}
	else
	{
		const T Min = minStack.peek();
		if( Min < temp) minStack.push(Min);
		else minStack.push(temp);
	}
return *this;
}

template<class T>
StackMin<T>& StackMin<T>::pop()
{
	minStack.pop();
	main.pop();
return *this;
}

template<class T>
T StackMin<T>::min()
{
return minStack.peek();
}



template<class T, std::size_t s>
class SetofStacks{
private:
	std::vector<std::stack<T> > S;
	std::size_t perStackSize =s;
public:
	std::size_t size();
	SetofStacks& push(const T&);
	SetofStacks& pop();
};

template<class T,std::size_t s>
std::size_t SetofStacks<T,s>::size()
{
	std::size_t count = 0;
	for(const std::stack<T>&  s1: S)
		count += s1.size();
	return count;
}

template<class T,std::size_t s>
SetofStacks<T, s>& SetofStacks<T, s>::push(const T& temp)
{
	if(S.empty())
			{ std::stack<T> stack;
			stack.push(temp);
				S.push_back(stack);
			}
		else if ((S[S.size()-1]).size() != s)
			{
			(S[S.size()-1]).push(temp);
			}
		else if ((S[S.size()-1]).size() == s)
			{ std::stack<T> stack;
				stack.push(temp);
					S.push_back(stack);
			}
return *this;
}

template<class T,std::size_t s>
SetofStacks<T, s>& SetofStacks<T, s>::pop()
{
	if(S.empty()) std::cout<<"ERROR : EMPTY"<<std::endl;
	else
		(S[S.size()-1]).pop();
	return *this;
}



template<class T>
class queueViaStacks{
private:
	std::stack<T> oldStack;
	std::stack<T> newStack;
	void shiftStacks();
public:
	std::size_t size(){return oldStack.size()+newStack.size();}
	queueViaStacks& push(const T&);
	queueViaStacks& pop();
	T& front();
};

template<class T>
T& queueViaStacks<T>::front()
{
shiftStacks();
return oldStack.top();
}

template<class T>
void queueViaStacks<T>::shiftStacks()
{
	if(oldStack.empty())
	{
		while(!newStack.empty())
		{
			oldStack.push(newStack.top());
			newStack.pop();
		}
	}
}
	template<class T>
queueViaStacks<T>& queueViaStacks<T>::push(const T& temp)
{
	newStack.push(temp);
	return *this;
}

template<class T>
queueViaStacks<T>& queueViaStacks<T>::pop()
{
		shiftStacks();
		oldStack.pop();
		return *this;
}


template<class T>
void SortStack(std::stack<T>& s)
{
	std::stack<T> tempStack;
	while(!s.empty())
	{
		T temp = s.top();
		s.pop();
		while(!tempStack.empty() && tempStack.top()> temp)
		{
			s.push(tempStack.top());
			tempStack.pop();
		}
		tempStack.push(temp);
	}

	while(!tempStack.empty())
	{
		s.push(tempStack.top());
		tempStack.pop();
	}
}






#endif
