/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:30:22 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/12 12:16:44 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#define KICK "KICK"
#define INVITE "INVITE"
#define TOPIC "TOPIC"
#define MODE "MODE"
#define NICK "NICK"
#define USER "USER"


#include "client.hpp"
#include "channel.hpp"

#include <unistd.h>
#include <fcntl.h>

#include <list>
#include <cerrno>//temp?
#include <cstring>//temp?
#include <iostream>
#include <netinet/in.h>//sockaddr_in
#include <arpa/inet.h>//inet_addr()
#include <sys/epoll.h>//epoll()

#include <stdexcept>
struct pars{
    u_short port;
    std::string password;
};

class server{
    public:
    server();
    server(pars& p);
    server(const server& src);
    ~server();
    server& operator=(const server& src);

    void launch();

    private:
    //socket
    int _fdSocketServer;
    sockaddr_in _addressServer;
    //aprsing
    pars _p;
    //epoll
    int _epfd;
    //utils
    std::list<client> _lstPendingClient;
    std::list<client> _lstClient;
    std::list<channel> _lstChannel;
    //server
    std::string _servername;
};

#endif