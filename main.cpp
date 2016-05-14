#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include"Chapter1.h"
#include"Chapter2.h"
#include"Chapter3.h"
#include"Chapter5.h"
#include"Chapter8.h"
#include<bitset>


int main()
{
	std::cout<< " 1_1 :"<< uniqueCharacters1_1("aabcdef")<<std::endl;
	std::cout<<"1_2_1 :"<<permutaion1_2_1("abcd","dcba")<<std::endl;
	std::cout<<"1_2_2 :"<<permutaion1_2_2("abcd","dcb")<<std::endl;
	std::cout<<URLify("Mr John Smith")<<std::endl;
	std::cout<<"1_4 :"<< ispalindromePermutaion("tactcoapapa")<<std::endl;
	std::cout<<"1_4 :"<<ispalindromePermutaionBitManipulation("tactofapapa")<<std::endl;
	std::cout<<sizeof(unsigned int)<<std::endl;
	std::cout<<int('a')<<std::endl;
	std::cout<<"1_5 : "<<oneEditAway("apple", "aple")<<std::endl;
	std::cout<<"1_6 : "<<StringCompression("aabcccccaaa")<<std::endl;
	std::cout<<"1_6 : "<<StringCompression("abcde")<<std::endl;
	std::vector<int> a1{1,2,3,4,5};
	std::vector<std::vector<int> > v;
	v.push_back(a1);
	v.push_back(a1);v.push_back(a1);v.push_back(a1);v.push_back(a1);
	printVector(v);
	MatrixRotation(v);
	printVector(v);
	ForwardList<int> a;
	a.addNode_back(2).addNode_back(2).addNode_back(2).addNode_back(4).addNode_back(5).addNode_back(6).addNode_back(8).addNode_back(8	);
	a.displayList(std::cout)<<std::endl;
	a.removeDupsWithoutBuffer();
	a.displayList(std::cout)<<std::endl;
	a.NthtoLAST(2);
	ForwardList<int> b , c, d, e, f, sum, p,q;
	b.addNode_back(7).addNode_back(1).addNode_back(6).addNode_back(9);
	b.displayList(std::cout)<<std::endl;
	c.addNode_back(5).addNode_back(9).addNode_back(4);
	c.displayList(std::cout)<<std::endl;
	d.sumReverseOrder(b,c);
	d.displayList(std::cout)<<std::endl;
	e.addNode_back(6).addNode_back(1).addNode_back(7).addNode_front(9);
	e.displayList(std::cout)<<std::endl;
	f.addNode_back(4).addNode_back(9).addNode_back(5);
	f.displayList(std::cout)<<std::endl;
	sum.sumForwardOrder(e,f);
	std::cout<<sum<<std::endl;

	std::bitset<4> mybits=~0;
	std::cout<<(mybits<<1)<<std::endl;
	std::bitset<32> n ("10000000000"), m("10011");
	std::cout<<insertCplusplus(n, m , 2 , 6)<<std::endl;
	p.addNode_back(7).addNode_back(1).addNode_back(1).addNode_back(1).addNode_back(7);
	std::cout<<p.isPalindrome()<<std::endl;
	std::cout<<p<<std::endl;
	const std::vector< int> cV{0,1,2};
	//cV[0] = 2;
	StackMin<int> min;
	min.push(5).push(6).push(3).push(7).pop().pop();
	std::cout<<"=============  "<<min.min()<<std::endl;
	SetofStacks<int,2> ss;;
	ss.push(1).push(2).push(3).push(4).push(5).push(6);
	std::cout<<ss.size()<<std::endl;
	//std::cout<<ss[2].size();
	ss.pop();
	ss.pop();
	std::cout<<ss.size()<<std::endl;
	std::stack<int> si;
	si.push(2);
	si.push(7);
	si.push(8);
	si.push(5);
	si.push(10);
	std::cout<<si.top()<<std::endl;
	SortStack(si);
	std::cout<<si.top()<<std::endl;
	std::cout<<"++++++++++++++++  "<<fibonacci(6)<<std::endl;

std::cout<<";;;;;;;;;;;;;;;;;;; "<<tripleStep(4)<< "  == "<<tripleStepMemo(4)<<std::endl;

	return 0;
}
