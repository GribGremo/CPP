/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:12 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/18 14:26:32 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    (void)argc;
    Harl harl;
    if (argc == 2)
        harl.complain(argv[1]);
    else
        std::cout << "Invalid number of arguments";
    return 0;
}