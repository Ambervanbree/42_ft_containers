#include <iostream>
#include <utility>
#include <gtest/gtest.h>

TEST(stl_pair, creatingUninitialised){
	std::pair <int, char> 		p1;
	std::pair <int, double>		p2;

	EXPECT_EQ(p1.first, 0);
	EXPECT_EQ(p1.second, '\0');
	EXPECT_EQ(p2.first, 0);
	EXPECT_EQ(p2.second, 0.0);

	p1.first = 100;
	p1.second = 'G';
	p2.first = 3;
	p2.second = 5.67;

	EXPECT_EQ(p1.first, 100);
	EXPECT_EQ(p1.second, 'G');
	EXPECT_EQ(p2.first, 3);
	EXPECT_EQ(p2.second, 5.67);
}

TEST(stl_pair, creatingInitialised){
	std::pair <int, int>			p1(1, -3);
	std::pair <int, int>			p2(0, -5);
	std::pair <int, char>			p3(101, 'E');
	std::pair <int, int>			p4(102, 5);
	std::pair <int, char>			p5(p3);
	std::pair <int, std::string>	p6(1, "Chleo");

	EXPECT_EQ(p1.first, 1);
	EXPECT_EQ(p1.second, -3);
	EXPECT_EQ(p2.first, 0);
	EXPECT_EQ(p2.second, -5);
	EXPECT_EQ(p3.first, 101);
	EXPECT_EQ(p3.second, 'E');
	EXPECT_EQ(p4.first, 102);
	EXPECT_EQ(p4.second, 5);
	EXPECT_EQ(p5.first, 101);
	EXPECT_EQ(p5.second, 'E');
	EXPECT_EQ(p6.first, 1);
	EXPECT_EQ(p6.second, "Chleo");
}

TEST(stl_pair, testingOperators){
	std::pair <int, char> 			p1(100, 'G');
	std::pair <int, double>			p2(3, 3.57);
	std::pair <int, char>			p3(101, 'E');
	std::pair <int, int>			p4(102, 5);
	std::pair <int, char>			p5(p3);
	std::pair <int, std::string>	p6(1, "Chleo");
	
	p3 = p1;

	EXPECT_EQ(p3.first, 100);
	EXPECT_EQ(p3.second, 'G');
	EXPECT_EQ(p1 < p5, true);
	EXPECT_EQ(p1 > p5, false);
	EXPECT_EQ(p1 <= p5, true);
	EXPECT_EQ(p1 >= p5, false);
	EXPECT_EQ(p3 == p5, false);
	EXPECT_EQ(p3 != p1, false);
}
