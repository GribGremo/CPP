/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/16 15:54:16 by sylabbe          ###   ########.fr       */
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
    void complain( const char* level);

    typedef void (Harl::*HarlFn)();
    
    private:

    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    std::string fn_cmd[4];
    HarlFn fn[4];
};

#endif