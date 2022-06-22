#include <gtest/gtest.h>

class A {};
 
template <typename T>
bool isintegral(T a){
	(void)a;
	return std::is_integral<T>::value;
}

TEST(stl_is_integral, STL){
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

	EXPECT_EQ(isintegral(t1), true);
	EXPECT_EQ(isintegral(t2), true);
	EXPECT_EQ(isintegral(t3), true);
	EXPECT_EQ(isintegral(t4), true);
	EXPECT_EQ(isintegral(t5), true);
	EXPECT_EQ(isintegral(t6), true);
	EXPECT_EQ(isintegral(t7), true);
	EXPECT_EQ(isintegral(t8), false);
	EXPECT_EQ(isintegral(t9), false);
	EXPECT_EQ(isintegral(t10), false);
	EXPECT_EQ(isintegral(t11), false);
	EXPECT_EQ(isintegral(t12), false);
	EXPECT_EQ(isintegral(t13), false);
	EXPECT_EQ(isintegral(t14), true);
	EXPECT_EQ(isintegral(t15), true);
}
