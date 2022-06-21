#include "pair.hpp"
#include <iostream>
#include <utility>
#include <gtest/gtest.h>

TEST(pair, creatingUninitialised){
	std::pair <int, char> 		p1;
	std::pair <int, double>		p2;
	ft::pair <int, char> 		fp1;
	ft::pair <int, double>		fp2;

	EXPECT_EQ(p1.first, fp1.first);
	EXPECT_EQ(p1.second, fp1.second);
	EXPECT_EQ(p2.first, fp2.first);
	EXPECT_EQ(p2.second, fp2.second);

	p1.first = 100;
	p1.second = 'G';
	p2.first = 3;
	p2.second = 5.67;
	fp1.first = 100;
	fp1.second = 'G';
	fp2.first = 3;
	fp2.second = 5.67;

	EXPECT_EQ(p1.first, fp1.first);
	EXPECT_EQ(p1.second, fp1.second);
	EXPECT_EQ(p2.first, fp2.first);
	EXPECT_EQ(p2.second, fp2.second);
}

TEST(pair, creatingInitialised){
	std::pair <int, int>			p1(1, -3);
	std::pair <int, int>			p2(0, -5);
	std::pair <int, char>			p3(101, 'E');
	std::pair <int, int>			p4(102, 5);
	std::pair <int, char>			p5(p3);
	std::pair <int, std::string>	p6(1, "Chleo");

	ft::pair <int, int>				fp1(1, -3);
	ft::pair <int, int>				fp2(0, -5);
	ft::pair <int, char>			fp3(101, 'E');
	ft::pair <int, int>				fp4(102, 5);
	ft::pair <int, char>			fp5(fp3);
	ft::pair <int, std::string>		fp6(1, "Chleo");

	EXPECT_EQ(p1.first, fp1.first);
	EXPECT_EQ(p1.second, fp1.second);
	EXPECT_EQ(p2.first, fp2.first);
	EXPECT_EQ(p2.second, fp2.second);
	EXPECT_EQ(p3.first, fp3.first);
	EXPECT_EQ(p3.second, fp3.second);
	EXPECT_EQ(p4.first, fp4.first);
	EXPECT_EQ(p4.second, fp4.second);
	EXPECT_EQ(p5.first, fp5.first);
	EXPECT_EQ(p5.second, fp5.second);
	EXPECT_EQ(p6.first, fp6.first);
	EXPECT_EQ(p6.second, fp6.second);
}

TEST(pair, testingOperators){
	std::pair <int, char> 			p1(100, 'G');
	std::pair <int, double>			p2(3, 3.57);
	std::pair <int, char>			p3(101, 'E');
	std::pair <int, int>			p4(102, 5);
	std::pair <int, char>			p5(p3);
	std::pair <int, std::string>	p6(1, "Chleo");

	ft::pair <int, char> 			fp1(100, 'G');
	ft::pair <int, double>			fp2(3, 3.57);
	ft::pair <int, char>			fp3(101, 'E');
	ft::pair <int, int>				fp4(102, 5);
	ft::pair <int, char>			fp5(fp3);
	ft::pair <int, std::string>		fp6(1, "Chleo");
	
	p3 = p1;
	fp3 = fp1;

	EXPECT_EQ(p3.first, fp3.first);
	EXPECT_EQ(p3.second, fp3.second);
	EXPECT_EQ(p1 < p5, fp1 < fp5);
	EXPECT_EQ(p1 > p5, fp1 > fp5);
	EXPECT_EQ(p1 <= p5, fp1 <= fp5);
	EXPECT_EQ(p1 >= p5, fp1 >= fp5);
	EXPECT_EQ(p3 == p5, fp3 == fp5);
	EXPECT_EQ(p3 != p1, fp3 != fp1);
}
