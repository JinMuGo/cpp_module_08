/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:35:22 by jgo               #+#    #+#             */
/*   Updated: 2023/07/23 23:50:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {
	std::cout << SPAN_DFLT_CTOR << std::endl;
}

Span::Span(const unsigned int N) : vec_(N), idx_(0) {
	std::cout << SPAN_CTOR << std::endl;
}

Span::Span(const Span& obj) {
	std::cout << SPAN_CPY_CTOR << std::endl;
	*this = obj;
}

Span::~Span(void) {
	std::cout << SPAN_DTOR << std::endl;
}

const std::size_t& Span::getIdx(void) const {
	return (this->idx_);
}

const VEC_INT& Span::getVec(void) const {
	return (this->vec_);
}

Span& Span::operator=(const Span& obj) {
	std::cout << SPAN_CPY_ASGMT_OP_CALL << std::endl;
	if (this != &obj) {
		this->vec_ = obj.getVec();
		this->idx_ = obj.getIdx();
	}
	return (*this);
}

void Span::addNumber(const int& num) {
	if (this->vec_.size() == this->idx_)
		throw AlreadyAllElementsStored(__func__);
	this->vec_.at(this->idx_++) = num;
}

std::size_t Span::longestSpan(void) const {
	if (this->vec_.size() < 2)
		throw CantSpanElement(__func__);
	const std::pair<VEC_INT_CONST_ITER, VEC_INT_CONST_ITER> itPair =
		std::make_pair<VEC_INT_CONST_ITER, VEC_INT_CONST_ITER>(std::min_element(this->vec_.begin(), this->vec_.end()),
															   std::max_element(this->vec_.begin(), this->vec_.end()));

	return *itPair.second - *itPair.first;
}

std::size_t Span::shortestSpan(void) const {
	if (this->vec_.size() < 2)
		throw CantSpanElement(__func__);
	VEC_INT tmp(this->vec_);
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
	tmp.erase(tmp.begin());
	std::valarray<int> valArr(tmp.data(), tmp.size());
	valArr = std::abs(valArr);
	return (valArr.min());
}

Span::AlreadyAllElementsStored::AlreadyAllElementsStored(const std::string func)
	: prompt_(func + ": Already All Elements Stored in Container") {}
Span::AlreadyAllElementsStored::~AlreadyAllElementsStored(void) throw() {}

const char* Span::AlreadyAllElementsStored::what(void) const throw() {
	return (this->prompt_.c_str());
}

Span::CantSpanElement::CantSpanElement(const std::string func)
	: prompt_(func + ": Can't Span Element because size is too small") {}
Span::CantSpanElement::~CantSpanElement(void) throw() {}

const char* Span::CantSpanElement::what(void) const throw() {
	return (this->prompt_.c_str());
}