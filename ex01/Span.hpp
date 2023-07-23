/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:35:32 by jgo               #+#    #+#             */
/*   Updated: 2023/07/23 23:50:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include "Span.h"

class Span {
   private:
	VEC_INT vec_;
	std::size_t idx_;
	Span(void);

   public:
	// OCCF
	Span(const Span& obj);
	virtual ~Span(void);
	Span& operator=(const Span& obj);

	Span(const unsigned int N);
	std::size_t shortestSpan(void) const;
	std::size_t longestSpan(void) const;
	const VEC_INT& getVec(void) const;
	const std::size_t& getIdx(void) const;
	void addNumber(const int& num);

	template <typename T>
	void addRange(T begin, T end) {
		if (std::distance(begin, end) > static_cast<int>(this->vec_.size() - this->idx_))
			throw CantSpanElement(__func__);
		while (begin != end)
			this->vec_.at(this->idx_++) = *begin++;
	};

	class AlreadyAllElementsStored : public std::exception {
	   private:
		const std::string prompt_;

	   public:
		AlreadyAllElementsStored(const std::string func);
		virtual ~AlreadyAllElementsStored() throw();
		virtual const char* what(void) const throw();
	};

	class CantSpanElement : public std::exception {
	   private:
		const std::string prompt_;

	   public:
		CantSpanElement(const std::string func);
		virtual ~CantSpanElement() throw();
		virtual const char* what(void) const throw();
	};
};

#endif
