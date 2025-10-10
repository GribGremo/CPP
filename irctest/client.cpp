/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:50:51 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/10 13:03:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.hpp"

//CONSTRUCTORS/DESTRUCTOR
    client::client(){
        _fdSocketClient = 0;       
    }

    client::client(int fdSocketClient){
        int flags = 0;
        _fdSocketClient = fdSocketClient;
        flags = fcntl(_fdSocketClient,F_GETFL);
        fcntl(_fdSocketClient,F_SETFL | O_NONBLOCK);
        // _addressClient = addressClient;
    }

    client::client(const client& src){//NONBLOCK DEJA INIT?
        _fdSocketClient = src._fdSocketClient;
        // _addressClient = src._addressClient;
    }

    client::~client(){

    }
    //OPERATORS
    client& client::operator=(const client& src){//NONBLOCK DEJA INIT?
        if (this == &src)
            return (*this);
        close(_fdSocketClient);//A VOIR ATTENTION
        _fdSocketClient = src._fdSocketClient;
        // _addressClient = src._addressClient;
        return (*this);
    }

//METHODS