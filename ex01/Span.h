/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:35:24 by jgo               #+#    #+#             */
/*   Updated: 2023/07/23 23:49:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <valarray>
#include <vector>
#include "color.h"

#ifndef VEC_INT
#define VEC_INT std::vector<int>
#endif

#ifndef VEC_INT_CONST_ITER
#define VEC_INT_CONST_ITER std::vector<int>::const_iterator
#endif

#ifndef T_ITER
#define T_ITER typename T::iterator
#endif

#define SPAN_DFLT_CTOR GREEN "- Span: Default constructor called" RESET
#define SPAN_CTOR DARK_GREEN "- Span: constructor called" RESET
#define SPAN_CTR LIGHT_CYAN "- Span: constructor called" RESET
#define SPAN_CPY_CTOR CYAN "- Span: Copy constructor called" RESET
#define SPAN_CPY_ASGMT_OP_CALL DARK_CYAN "- Span: Copy assignment operator called" RESET
#define SPAN_DTOR ORANGE "- Span: Destructor called" RESET
#define SPAN_MEMBER_FUNC_CALL "- Span member function called"

#endif