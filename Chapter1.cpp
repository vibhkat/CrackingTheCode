#include<string>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include"Chapter1.h"

bool uniqueCharacters1_1(const std::string& s)
{
	if (s.size()> 128) return false;   //128 depends on type of characters using
	bool* cp = new bool[128]();
	for(std::size_t i=0; i!= s.size(); ++i) //const char& c : s)
	{
		int val = static_cast<int> (s[i]);
		if(cp[val] == true) 
			return false;
		else 
			cp[val] = true;
	}
return true;
}


bool permutaion1_2_1(std::string s1, std::string s2)
{
if(s1.size() != s2.size())
	return false;
std::sort(s1.begin(), s1.end());
std::sort(s2.begin(), s2.end());
std::size_t Size = s1.size() < s2.size() ? s1.size() : s2.size();
for(std::size_t i = 0; i!= Size ; ++i)
{
	if(s1[i] != s2[i])
		return false;
}
return true;
}

bool permutaion1_2_2(const std::string& s1, const std::string& s2)
{
if(s1.size() != s2.size())
	return false;
int *p = new int[128]();
for(std::size_t i =0; i != s1.size(); ++i)
{
	int val = static_cast<int> (s1[i]);
	++p[val];
}
for(std::size_t i =0; i != s2.size(); ++i)
{
	int val = static_cast<int> (s2[i]);
	if(--p[val]< 0)
		return false;
	
}
return true;
}

std::string URLify(const std::string& s)
{
char c[100];
std::size_t i=0, count =0 ;
for(; i != s.size() ; ++i )
{
	c[i]=s[i];
	if (s[i] == ' ') ++count;
}
//c[i]='\0';
std::size_t newlength = s.size()+ 2*count;
c[newlength]='\0';
for(std::size_t i = s.size()-1; i>0; --i)
{
	if(c[i] == ' ' )
	{
		c[newlength-1] = '0';
		c[newlength-2] = '2';
		c[newlength-3] = '%';
		newlength = newlength -3;
	}
	else
	{
		c[newlength-1] = c[i];
		--newlength;
	}
}
return std::string(c);
}



bool ispalindromePermutaion(const std::string& s)
{
int tablesize = static_cast<int>('z') - static_cast<int>('a') +1;
	int *p = new int[tablesize]();// depends on ASCII
std::size_t length = s.size();
std::size_t oddcount=0, evencount=0;
for(std::size_t i=0; i!=length ; ++i)
{ int index =static_cast<int>(tolower(s[i]))- static_cast<int>('a');
	++p[index];
}

for(int i=0 ; i!= tablesize; ++i)
{
	if(p[i]% 2 == 0 && p[i]!= 0) ++evencount;
	else if (p[i]%2 !=0 && p[i] !=0 )++oddcount;
}
std::cout<<"EVEN :"<<evencount<< " ODD :"<<oddcount<<std::endl;
if((length% 2 ==0  && evencount%2 == 0 % oddcount == 0) ||(length% 2 !=0 && evencount%2 == 0 && oddcount == 1) ) return true;
else return false;


}


bool ispalindromePermutaionBitManipulation(const std::string& s)
{
unsigned int bitvector = 0;
for(std::size_t i=0; i!= s.size(); ++i)
{
toggle(bitvector, static_cast<int>(tolower(s[i]))- static_cast<int>('a'));
}
if((bitvector == 0) || ((bitvector & (bitvector -1)) == 0 ))
	return true;
return false;
}

void toggle(unsigned int& bitvector, int place)
{
	if (place < 0)
		return;
	unsigned int mask = 1<<place;
	if(( bitvector & mask) == 0)
		bitvector |= mask;
	else
		bitvector &= ~mask;
}


bool oneEditAway(const std::string& s1, const std::string& s2)
{
	if(s1.size() == s2.size()) return EditReplace(s1,s2);
	else if(s1.size() +1 == s2.size()) return EditInsertRemove(s1, s2);
	else if(s1.size() == s2.size()+1) return EditInsertRemove(s2, s1);
	return false;
}

bool EditReplace(const std::string& s1 , const std::string& s2)
{
	bool foundDifference = false;
	for(std::size_t i=0; i!= s1.size(); ++i)
	{
		if(s1[i] != s2[i])
	    {
			if(foundDifference)
				return false;
			foundDifference = true;
	    }
	}
	return true;
}

bool EditInsertRemove(const std::string& s1 , const std::string& s2)  //considering s2 size greater than s1
{
	std::size_t index1= 0, index2 = 0;
	while(index1<s1.size() && index2<s2.size())
	{
		if(s1[index1] == s2[index2])
		{
			++index1;
			++index2;
		}
		else if(s1[index1] != s2[index2])
		{
			if(index1 != index2)  // can also use bool instead
				return false;
			++index2;
		}
	}
	return true;
}

const std::string StringCompression(const std::string& s)
{
	std::size_t index1 = 0, index2 = 1, count = 1, newlength =0;
	std::string s1;
	while(index1<s.size() && index2<=s.size())
	{
		if(s[index1] == s[index2])
			{
				++count;
				++index2;
			}
		else if((s[index1] != s[index2] )|| (index2+1 >= s.size()))
		{
			s1+= s[index1];
			std::ostringstream ss;
			ss<<count;
			s1+=ss.str();
			count =1;
			index1 = index2;
			++index2;
			newlength = s1.size();
		}
		if(newlength > s.size())
			return s;
	}
return s1;
}


