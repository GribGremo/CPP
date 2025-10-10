/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:41:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/10 17:51:13 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
//FUNCTIONS
bool nonBlockFd(int& fd){
    int flags = 0;
    flags = fcntl(fd,F_GETFL);
    if (flags == - 1)
    {
        std::cout << "Error: fcntl failed" << std::endl;
        return false;
    }
    if(fcntl(fd,F_SETFL,flags | O_NONBLOCK) == - 1)
    {
        std::cout << "Error: fcntl failed" << std::endl;
        return false;
    }
    return true;
}

bool setupFdServer(int& fdSocketServer, sockaddr_in& addressServer){
    fdSocketServer = socket(AF_INET, SOCK_STREAM, 0);//IPPROTO_TCP = 0, SOCKSTREAM suffit a faire comprendre qu'on utilisera le protocole TCP
    if(fdSocketServer == - 1){//errno possible
        std::cout << "Error: Socket failed"<< std::endl;
        return false;
    }
    if(!nonBlockFd(fdSocketServer))
        return false;

    if(bind(fdSocketServer, (struct sockaddr*)&addressServer,sizeof(addressServer)) == - 1)//errno possible(interessant erreur port)
    {
        std::cout << "Error: Bind failed" << std::endl;
        return false;
    }

    if(listen(fdSocketServer,10) == - 1)//errno possible
    {
        std::cout << "Error: Listen failed" << std::endl;
        return false;
    }
    return true;
}
//CONSTRUCTORS/DESTRUCTOR
server::server(){
    _addressServer.sin_family = AF_INET;
    _addressServer.sin_port = htons(6667);
    _addressServer.sin_addr.s_addr = inet_addr("127.0.0.1");
}
server::server(pars& p){
    _addressServer.sin_family = AF_INET;
    _addressServer.sin_port = htons(p.port);
    _addressServer.sin_addr.s_addr = inet_addr("127.0.0.1");
}
server::server(const server& src){
    _addressServer.sin_family = src._addressServer.sin_family;
    _addressServer.sin_port = src._addressServer.sin_port;
    _addressServer.sin_addr.s_addr = src._addressServer.sin_addr.s_addr;
}
server::~server(){

}
    
    //OPERATORS
server& server::operator=(const server& src){
    if(this == &src)
        return (*this);
    _addressServer.sin_family = src._addressServer.sin_family;
    _addressServer.sin_port = src._addressServer.sin_port;
    _addressServer.sin_addr.s_addr = src._addressServer.sin_addr.s_addr;
    return (*this);
}
    
    //METHODS
void server::launch(){
    if(!setupFdServer(_fdSocketServer,_addressServer))
        return ;
        
    int epfd = epoll_create(1);//size ou flags a voir
    if (epfd == - 1)
    {
        std::cout << "Error: epoll_create failed" << std::endl;
        return ;
    }
    epoll_event eventServer;
    eventServer.events = EPOLLIN;
    eventServer.data.fd = _fdSocketServer;
    epoll_event eventsClients[1024];//Definir le nombre d'events a gerer
    if(epoll_ctl(epfd,EPOLL_CTL_ADD,_fdSocketServer,&eventServer) == - 1)
    {
        std::cout << "Error: epoll_ctl failed" << std::endl;
        return ;
    }
    while(_lst.size() != 3)
    {
        char buffer[512];
        sockaddr_in addressClient;
        socklen_t addressClientLen = sizeof(addressClient);
        int fdSocketClient = accept(_fdSocketServer,(struct sockaddr*)&addressClient,&addressClientLen);
        if(fdSocketClient == - 1)
        {
            std::cout << "Error: Accept failed" << strerror(errno) << std::endl;
            return ;
        }
        _lst.push_back(client(fdSocketClient));
        std::cout << "Un client s'est connecté !"<< std::endl;
        recv(fdSocketClient,buffer,sizeof(buffer), MSG_DONTWAIT);
        std::cout << buffer << std::endl;
        close(fdSocketClient); // On ferme la socket du client, mais le serveur reste en écoute
    }
    close (_fdSocketServer);
}