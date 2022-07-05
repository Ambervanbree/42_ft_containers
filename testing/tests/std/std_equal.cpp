/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_equal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:59:36 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/05 12:40:01 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

bool is_palindrome(const std::string& s){
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
 
TEST(std_equal, palindrome){
	EXPECT_TRUE(is_palindrome("radar"));
	EXPECT_TRUE(is_palindrome("rotator"));
	EXPECT_TRUE(is_palindrome("racecar"));
	EXPECT_FALSE(is_palindrome("hello"));
	EXPECT_FALSE(is_palindrome("bullocks"));
	EXPECT_FALSE(is_palindrome("amsterdam"));
}

bool is_reverse(const std::string& s1, const std::string& s2){
	return std::equal(s1.begin(), s1.end(), s2.rbegin());
}

TEST(std_equal, reverse){
	EXPECT_TRUE(is_reverse("parc", "crap"));
	EXPECT_TRUE(is_reverse("live", "evil"));
	EXPECT_TRUE(is_reverse("boobytrap", "partyboob"));
	EXPECT_FALSE(is_reverse("batman", "nambat"));
	EXPECT_FALSE(is_reverse("yellow", "wollei"));
	EXPECT_FALSE(is_reverse("spongebob", "bobengops"));
}

bool pred(int &a, int &b){
	return a == b ? 1 : 0;
}

bool is_equal(std::vector<int> &array1, std::vector<int> &array2){
	return std::equal(array1.begin(), array1.end(), array2.begin(), pred);
}

bool is_equal_adjacent(std::vector<int> &array1, std::vector<int> &array2){
	return std::equal(array1.begin(), array1.end(), array2.begin() + 1, pred);
}

TEST(std_equal, adjacentPred){
	std::vector<int>	array1;
	std::vector<int>	array2;
	int 				i = 0;

	for (; i < 10; i++){
		array1.push_back(i + 1);
		array2.push_back(i);
	}
	array2.push_back(i);
	
	EXPECT_FALSE(is_equal(array1, array2));
	EXPECT_TRUE(is_equal_adjacent(array1, array2));
	EXPECT_FALSE(is_equal_adjacent(array2, array1));
}
