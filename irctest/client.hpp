/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:39:21 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/10 13:03:57 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>//sockaddr_in
#include <arpa/inet.h>//inet_addr()


class client{
    public:
    client();
    client(int fdSocketClient);
    client(const client& src);
    ~client();
    client& operator=(const client& src);

    private:
    int _fdSocketClient;
    sockaddr_in _addressClient;//A voir
};

#endif