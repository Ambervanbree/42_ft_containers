/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:59:33 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/23 15:37:13 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equal.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

bool is_palindrome(const std::string& s){
    return ft::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

TEST(ft_equal, palindrome){
	EXPECT_EQ(is_palindrome("radar"), true);
	EXPECT_EQ(is_palindrome("rotator"), true);
	EXPECT_EQ(is_palindrome("racecar"), true);
	EXPECT_EQ(is_palindrome("hello"), false);
	EXPECT_EQ(is_palindrome("bullocks"), false);
	EXPECT_EQ(is_palindrome("amsterdam"), false);
}

bool is_reverse(const std::string& s1, const std::string& s2){
	return ft::equal(s1.begin(), s1.end(), s2.rbegin());
}

TEST(ft_equal, reverse){
	EXPECT_EQ(is_reverse("parc", "crap"), true);
	EXPECT_EQ(is_reverse("live", "evil"), true);
	EXPECT_EQ(is_reverse("boobytrap", "partyboob"), true);
	EXPECT_EQ(is_reverse("batman", "nambat"), false);
	EXPECT_EQ(is_reverse("yellow", "wollei"), false);
	EXPECT_EQ(is_reverse("spongebob", "bobengops"), false);
}

bool pred(int &a, int &b){
	return a == b ? 1 : 0;
}

bool is_equal_adjacent(std::vector<int> &array1, std::vector<int> &array2){
	return ft::equal(array1.begin(), array1.end(), array2.begin() + 1, pred);
}

TEST(ft_equal, adjacentPred){
	std::vector<int>	array1;
	std::vector<int>	array2;
	int 				i = 0;

	for (; i < 10; i++){
		array1.push_back(i + 1);
		array2.push_back(i);
	}
	array2.push_back(i);	
	
	EXPECT_EQ(is_equal_adjacent(array1, array2), true);

	array1.push_back(++i);

	EXPECT_EQ(is_equal_adjacent(array1, array2), false);

	array2.push_back(i);

	EXPECT_EQ(is_equal_adjacent(array1, array2), true);
}
