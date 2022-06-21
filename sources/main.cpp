/* ************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amber <amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:40:19 by amber             #+#    #+#             */
/*   Updated: 2022/06/16 14:21:01 by amber            ###   ########.fr       */
/*                                                                            */
/* ************************** */

#include "vector.hpp"
#include "ft.hpp"
#include "pair.hpp"

#include <iostream>
#include <utility>

using namespace 	std;

int	main(void){
	{
		pair <int, char> 	p1;
		pair <int, double>	p2;
		pair <int, char>	p3(101, 'E');
		pair <int, int>		p4(102, 5);
		pair <int, char>	p5(p3);
		pair <int, string>	p6(1, "Chleo");

		cout << BOLD << "p1 and p2 are uninitialized: " << RESET << endl;
		cout << "p1: " << p1.first << " [" << p1.second << ']' << endl;
		cout << "p2: " << p2.first << " " << p2.second << endl;

		cout << endl << BOLD << "initialising p1 and p2: " << RESET << endl;
		p1.first = 100;
		p1.second = 'G';
		p2.first = 3;
		p2.second = 5.67;
		cout << "p1: " << p1.first << " [" << p1.second << ']' << endl;
		cout << "p2: " << p2.first << " " << p2.second << endl;

		cout << endl << BOLD << "p3 t/m p6 have been created correctly: " << RESET << endl;
		cout << "p3: " << p3.first << " " << p3.second << endl;
		cout << "p4: " << p4.first << " " << p4.second << endl;
		cout << "p5: " << p5.first << " " << p5.second << endl;
		cout << "p6: " << p6.first << " " << p6.second << endl;

		cout << endl << BOLD << "testing assignment operator: " << RESET << endl;
		// uncomment row 50 to see that this will result in a compiler error, 
		// because they don't have the same type
		// p2 = p6; 
		p3 = p1;
		cout << "p3: " << p3.first << " " << p3.second << endl;

		cout << endl << BOLD << "testing operators: " << RESET << endl;
		cout << "p1 < p5: " << (p1 < p5) << endl; //-> equality operators compare first value of the two elements
		cout << "p1 > p5: " << (p1 > p5) << endl;
		cout << "p1 <= p5: " << (p1 <= p5) << endl;
		cout << "p1 >= p3: " << (p1 >= p3) << endl; 
		cout << "p3 == p5: " << (p3 == p5) << endl; //-> returns 1 if both elements are equal
		cout << "p3 != p1: " << (p3 != p1) << endl; //-> returns 1 if both elements are not equal

		cout << endl << BOLD << "testing make_pair: " << RESET << endl;
		pair<int, char>		p7 = make_pair(25, 'A');
		pair<int, string>	p8 = make_pair(26, "Wen");
		cout << "p7: " << p7.first << " " << p7.second << endl;
		cout << "p8: " << p8.first << " " << p8.second << endl << endl;
	}
	{
		ft::pair <int, char> 	fp1;
		ft::pair <int, double>	fp2;
		ft::pair <int, char>	fp3(101, 'E');
		ft::pair <int, int>		fp4(102, 5);
		ft::pair <int, char>	fp5(fp3);
		ft::pair <int, string>	fp6(1, "Chleo");

		cout << BOLD << "fp1 and fp2 are uninitialized: " << RESET << endl;
		cout << "fp1: " << fp1.first << " [" << fp1.second << ']' << endl;
		cout << "fp2: " << fp2.first << " " << fp2.second << endl;

		cout << endl << BOLD << "initialising fp1 and fp2: " << RESET << endl;
		fp1.first = 100;
		fp1.second = 'G';
		fp2.first = 3;
		fp2.second = 5.67;
		cout << "fp1: " << fp1.first << " [" << fp1.second << ']' << endl;
		cout << "fp2: " << fp2.first << " " << fp2.second << endl;

		cout << endl << BOLD << "fp3 t/m fp6 have been created correctly: " << RESET << endl;
		cout << "fp3: " << fp3.first << " " << fp3.second << endl;
		cout << "fp4: " << fp4.first << " " << fp4.second << endl;
		cout << "fp5: " << fp5.first << " " << fp5.second << endl;
		cout << "fp6: " << fp6.first << " " << fp6.second << endl;

		cout << endl << BOLD << "testing assignment operator: " << RESET << endl;
		// uncomment row 50 to see that this will result in a compiler error, 
		// because they don't have the same type
		// fp2 = fp6;
		fp3 = fp1;
		cout << "fp3: " << fp3.first << " " << fp3.second << endl;

		cout << endl << BOLD << "testing operators: " << RESET << endl;
		cout << "fp1 < fp5: " << (fp1 < fp5) << endl; //-> equality operators compare first value of the two elements
		cout << "fp1 > fp5: " << (fp1 > fp5) << endl;
		cout << "fp1 <= fp5: " << (fp1 <= fp5) << endl;
		cout << "fp1 >= fp3: " << (fp1 >= fp3) << endl; 
		cout << "fp3 == fp5: " << (fp3 == fp5) << endl; //-> returns 1 if both elements are equal
		cout << "fp3 != fp1: " << (fp3 != fp1) << endl; //-> returns 1 if both elements are not equal
	
		cout << endl << BOLD << "testing ft::make_pair: " << RESET << endl;
		ft::pair<int, char>		fp7 = ft::make_pair(25, 'A');
		// ft::pair<int, string>	fp8 = ft::make_pair(26, "Wen");
		cout << "fp7: " << fp7.first << " " << fp7.second << endl;
		// cout << "fp8: " << fp8.first << " " << fp8.second << endl<< endl;
	}
}
