/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acardona <acardona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:56:17 by acardona          #+#    #+#             */
/*   Updated: 2024/01/11 17:56:35 by acardona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# define DEBUG 1

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

# include <cstdlib>
# include <iostream>
# include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif