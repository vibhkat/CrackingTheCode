#ifndef CHAPTER1_H
#define CHAPTER1_H
#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
bool uniqueCharacters1_1(const std::string& );
bool permutaion1_2_1(std::string , std::string );
bool permutaion1_2_2(const std::string& , const std::string& );
std::string URLify(const std::string& );
bool ispalindromePermutaion(const std::string& );
bool ispalindromePermutaionBitManipulation(const std::string& );
void toggle(unsigned int& , int );
bool oneEditAway(const std::string& , const std::string& );
bool EditReplace(const std::string& , const std::string& );
bool EditInsertRemove(const std::string& , const std::string&);
const std::string StringCompression(const std::string& );
template<class T> void MatrixRotation(std::vector<std::vector<T>>& );
template<class T> void printVector(const std::vector<T>&);

template<class T>
void MatrixRotation(std::vector<std::vector<T>>& a)
{
std::size_t N = a.size();
for(std::size_t layer =0 ; layer != N/2; ++layer)
{
	std::size_t first = layer;
	std::size_t last = N-1-layer;
	for(std::size_t i = first; i != last; ++i)
	{
		T temp = a[first][i];
		a[first][i] = a[last-i+layer][first]; //we need to add layer to increase the count
		a[last-i+layer][first] = a[last][last-i+layer];
		a[last][last-i+layer] = a[i][last];
		a[i][last]=temp;
	}
}
}



template<class T>
void printVector(const std::vector<T>&v)
{
for(std::size_t i=0; i!= v.size(); ++i )
	{
	for(std::size_t j=0; j!= (v.at(0)).size(); ++j)
	std::cout<<v[i][j]<< " ";
	std::cout<<std::endl;
	}
}

#endif
