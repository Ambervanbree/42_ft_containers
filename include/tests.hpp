/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:22:03 by avan-bre          #+#    #+#             */
/*   Updated: 2022/07/06 10:27:29 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#ifndef FT
# define ENABLE_IF		ft::enable_if
# define EQUAL			ft::equal
# define IS_INTEGRAL	ft::is_integral
# define LEX_COMPARE	ft::lexicographical_compare
# define PAIR			ft::pair
# define STACK			ft::stack
# define VECTOR			ft::vector
#else
# define ENABLE_IF		std::enable_if
# define EQUAL			std::equal
# define IS_INTEGRAL	std::is_integral
# define LEX_COMPARE	std::lexicographical_compare
# define PAIR			std::pair
# define STACK			std::stack
# define VECTOR			std::vector
#endif

#endif