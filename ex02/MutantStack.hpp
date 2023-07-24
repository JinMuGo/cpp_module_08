/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:16:50 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 11:46:08 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include "MutantStack.h"

// https://en.cppreference.com/w/cpp/container/stack
// https://stackoverflow.com/questions/148540/creating-my-own-iterators
// stack의 underlying container는 deque임.
template <class T>
class MutantStack : public std::stack<T, std::deque<T> > {
   private:
	/* data */
   public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
	const_iterator cbegin(void) const { return this->c.begin(); }
	const_iterator cend(void) const { return this->c.end(); }

	reverse_iterator rbegin(void) { return this->c.rbegin(); }
	reverse_iterator rend(void) { return this->c.rend(); }
	const_reverse_iterator crbegin(void) const { return this->c.rbegin(); }
	const_reverse_iterator crend(void) const { return this->c.rend(); }

	MutantStack(void) { std::cout << MS_DFLT_CTOR << std::endl; }
	MutantStack(const MutantStack& obj):std::stack<T>(obj) {
		std::cout << MS_CPY_CTOR << std::endl;
		*this = obj;
	}
	~MutantStack(void) { std::cout << MS_DTOR << std::endl; }
	MutantStack& operator=(const MutantStack& obj) {
		std::cout << MS_CPY_ASGMT_OP_CALL << std::endl;
		if (this != &obj)
			this->std::stack<T>::operator=(obj);
		return (*this);
	}
};

#endif
