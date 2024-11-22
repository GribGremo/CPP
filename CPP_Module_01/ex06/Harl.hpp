/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/22 10:12:43 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
    public:

    Harl();
    ~Harl();
    void complain( std::string level);
    
    private:

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string fn_cmd[4];
    void (Harl::*fn[4])();
};
#endif