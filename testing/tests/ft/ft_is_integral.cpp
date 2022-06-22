/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:04:08 by avan-bre          #+#    #+#             */
/*   Updated: 2022/06/22 18:04:09 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_integral.hpp"
#include <gtest/gtest.h>

class A {};
 
template <typename T>
bool ft_isintegral(T a){
	(void)a;
	return ft::is_integral<T>::value;
}

TEST(ft_is_integral, general){
	bool		t1 = false;
	char		t2 = 14;
	wchar_t		t3 = 73;
	short		t4 = -389;
	int			t5 = 3423235;
	long		t6 = 23749237492374;
	long long	t7 = 1468764983276498763;
	float		t8 = 1.25;
	double		t9 = 5.25;
	long double	t10 = 856487356387465893.2;
	A			t11;
	std::string	t12 = "Hello";
	int			t13[3];
	const bool	t14 = false;
	const int	t15 = 8349;

	EXPECT_EQ(ft_isintegral(t1), true);
	EXPECT_EQ(ft_isintegral(t2), true);
	EXPECT_EQ(ft_isintegral(t3), true);
	EXPECT_EQ(ft_isintegral(t4), true);
	EXPECT_EQ(ft_isintegral(t5), true);
	EXPECT_EQ(ft_isintegral(t6), true);
	EXPECT_EQ(ft_isintegral(t7), true);
	EXPECT_EQ(ft_isintegral(t8), false);
	EXPECT_EQ(ft_isintegral(t9), false);
	EXPECT_EQ(ft_isintegral(t10), false);
	EXPECT_EQ(ft_isintegral(t11), false);
	EXPECT_EQ(ft_isintegral(t12), false);
	EXPECT_EQ(ft_isintegral(t13), false);
	EXPECT_EQ(ft_isintegral(t14), true);
	EXPECT_EQ(ft_isintegral(t15), true);
}
