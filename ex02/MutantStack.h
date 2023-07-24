/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:16:45 by jgo               #+#    #+#             */
/*   Updated: 2023/07/24 10:24:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include "color.h"

#define MS_DFLT_CTOR GREEN "- MutantStack: Default constructor called" RESET
#define MS_CTOR DARK_GREEN "- MutantStack: constructor called" RESET
#define MS_CTR LIGHT_CYAN "- MutantStack: constructor called" RESET
#define MS_CPY_CTOR CYAN "- MutantStack: Copy constructor called" RESET
#define MS_CPY_ASGMT_OP_CALL DARK_CYAN "- MutantStack: Copy assignment operator called" RESET
#define MS_DTOR ORANGE "- MutantStack: Destructor called" RESET
#define MS_MEMBER_FUNC_CALL "- MutantStack member function called"

#endif