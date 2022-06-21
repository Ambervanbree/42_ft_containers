#include "pair.hpp"
#include <gtest/gtest.h>

TEST(make_pair, basic){
	std::pair<int, char>	p1 = std::make_pair(25, 'A');
	ft::pair<int, char>		fp1 = ft::make_pair(25, 'A');
	std::pair<int, double>	p2 = std::make_pair(25, 2.45);
	ft::pair<int, double>	fp2 = ft::make_pair(25, 2.45);

	std::string	str1 = "Hello";
	
	std::pair<float, std::string>	p3 = std::make_pair(1.2, str1);
	ft::pair<float, std::string>	fp3 = ft::make_pair(1.2, str1);

	EXPECT_EQ(p1.first, fp1.first);
	EXPECT_EQ(p1.second, fp1.second);
	EXPECT_EQ(p2.first, fp2.first);
	EXPECT_EQ(p2.second, fp2.second);
	EXPECT_EQ(p3.first, fp3.first);
	EXPECT_EQ(p3.second, fp3.second);
}