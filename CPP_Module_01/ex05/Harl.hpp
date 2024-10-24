/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:13:17 by sylabbe           #+#    #+#             */
/*   Updated: 2024/10/18 12:23:18 by sylabbe          ###   ########.fr       */
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