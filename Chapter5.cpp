#include"Chapter5.h"

unsigned int insert(unsigned int& n,unsigned int& m, unsigned int& i, unsigned int&j)
{
	unsigned int allones = ~0;
	unsigned int left = allones<<(j+1);
	unsigned int right = (1<<i)-1;
	unsigned int mask = left | right;
	unsigned int n_cleared = n & mask;
	unsigned int m_shifted = m << i;
	return n_cleared | m_shifted;
}


std::bitset<32> insertCplusplus(const std::bitset<32> &n,const std::bitset<32> &m, const unsigned int &i, const unsigned int &j)
{
	std::bitset<32> allones = ~0;
	std::bitset<32> left = allones <<(j+1);
	std::bitset<32> right = (1<<i) - 1;
	std::bitset<32> mask = left | right;
	std::bitset<32> n_cleared = n & mask;
	std::bitset<32> m_shifted = m << i;
	return n_cleared | m_shifted;
}
