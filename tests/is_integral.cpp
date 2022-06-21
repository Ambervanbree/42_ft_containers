#include "is_integral.hpp"
#include <gtest/gtest.h>

class A {};
 
template <typename T>
bool isintegral(T a){
	(void)a;
	return std::is_integral<T>::value;
}

template <typename T>
bool ft_isintegral(T a){
	(void)a;
	return ft::is_integral<T>::value;
}

TEST(is_integral, STL){
	bool		t1 = false;
	char		t2 = 14;
	char16_t	t3 = 3857;
	char32_t	t4 = -5;
	wchar_t		t5 = 73;
	short		t6 = -389;
	int			t7 = 3423235;
	long		t8 = 23749237492374;
	long long	t9 = 1468764983276498763;
	float		t10 = 1.25;
	double		t11 = 5.25;
	long double	t12 = 856487356387465893.2;
	A			t13;
	std::string	t14 = "Hello";
	int			t15[3];
	const bool	t16 = false;
	const int	t17 = 8349;

	EXPECT_EQ(isintegral(t1), true);
	EXPECT_EQ(isintegral(t2), true);
	EXPECT_EQ(isintegral(t3), true);
	EXPECT_EQ(isintegral(t4), true);
	EXPECT_EQ(isintegral(t5), true);
	EXPECT_EQ(isintegral(t6), true);
	EXPECT_EQ(isintegral(t7), true);
	EXPECT_EQ(isintegral(t8), true);
	EXPECT_EQ(isintegral(t9), true);
	EXPECT_EQ(isintegral(t10), false);
	EXPECT_EQ(isintegral(t11), false);
	EXPECT_EQ(isintegral(t12), false);
	EXPECT_EQ(isintegral(t13), false);
	EXPECT_EQ(isintegral(t14), false);
	EXPECT_EQ(isintegral(t15), false);
	EXPECT_EQ(isintegral(t16), true);
	EXPECT_EQ(isintegral(t17), true);
}

TEST(is_integral, FT){
	bool		ft1 = 12;
	char		ft2 = 14;
	char16_t	ft3 = 3857;
	char32_t	ft4 = -5;
	wchar_t		ft5 = 73;
	short		ft6 = -389;
	int			ft7 = 3423235;
	long		ft8 = 23749237492374;
	long long	ft9 = 1468764983276498763;
	float		ft10 = 1.25;
	double		ft11 = 5.25;
	long double	ft12 = 856487356387465893.2;
	A			ft13;
	std::string	ft14 = "Hello";
	int			ft15[3];
	const bool	ft16 = false;
	const int	ft17 = 8349;

	EXPECT_EQ(ft_isintegral(ft1), true);
	EXPECT_EQ(ft_isintegral(ft2), true);
	EXPECT_EQ(ft_isintegral(ft3), true);
	EXPECT_EQ(ft_isintegral(ft4), true);
	EXPECT_EQ(ft_isintegral(ft5), true);
	EXPECT_EQ(ft_isintegral(ft6), true);
	EXPECT_EQ(ft_isintegral(ft7), true);
	EXPECT_EQ(ft_isintegral(ft8), true);
	EXPECT_EQ(ft_isintegral(ft9), true);
	EXPECT_EQ(ft_isintegral(ft10), false);
	EXPECT_EQ(ft_isintegral(ft11), false);
	EXPECT_EQ(ft_isintegral(ft12), false);
	EXPECT_EQ(ft_isintegral(ft13), false);
	EXPECT_EQ(ft_isintegral(ft14), false);
	EXPECT_EQ(ft_isintegral(ft15), false);
	EXPECT_EQ(ft_isintegral(ft16), true);
	EXPECT_EQ(ft_isintegral(ft17), true);
}

