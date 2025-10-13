/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:41:55 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/12 20:45:39 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

#define MAX_EVENTS 1024
//FUNCTIONS
void nonBlockFd(int& fd){
    int flags = 0;
    
    flags = fcntl(fd,F_GETFL);
    if (flags == - 1)
        throw std::runtime_error("Error: Fcntl failed: " + std::string(strerror(errno)));

    if(fcntl(fd,F_SETFL,flags | O_NONBLOCK) == - 1)
        throw std::runtime_error("Error: Fcntl failed: " + std::string(strerror(errno)));
}

void socketToEpoll(int& fd, int& fdSocketServer, int& epfd){
    epoll_event stEvent;
    
    if(fd == fdSocketServer)
        stEvent.events = EPOLLIN;
    else
        stEvent.events = EPOLLIN | EPOLLET | EPOLLRDHUP;
    stEvent.data.fd = fd;
        
    if(epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&stEvent) == - 1)
        throw std::runtime_error("Error: Epoll_ctl failed: " + std::string(strerror(errno)));
}

void setupEpoll(int fdSocketServer, int& epfd){
   epfd = epoll_create(1);//size ou flags a voir
    if (epfd == - 1)
        throw std::runtime_error("Error: Epoll_create failed: " + std::string(strerror(errno)));
    
    socketToEpoll(fdSocketServer,fdSocketServer,epfd);
}

bool acceptClient(int& fdSocketServer, int& fd, int& epfd, std::list<client>& lstPendingClient){//MOT DE PASSE?
    sockaddr_in addressClient;
    socklen_t addressClientLen = sizeof(addressClient);
    
    int fdSocketClient = accept(fdSocketServer,(struct sockaddr*)&addressClient,&addressClientLen);
    if(fdSocketClient == - 1)//PAS BESOIN JE LAISSE POUR LE MOMENT
    {
        std::cout << "Error: Accept failed:" << strerror(errno) << std::endl;
        return false;
    }
    nonBlockFd(fdSocketClient);
    socketToEpoll(fdSocketClient, fdSocketServer,epfd);
    lstPendingClient.push_back(client(fdSocketClient));
    std::cout << "Un client s'est connecté !"<< std::endl;
    return true;
}

size_t subString(const std::string& str, std::string cmp, std::string& res){
    size_t end = 0;
    end = str.find(cmp);
    if (end = std::string::npos)
        return end;
    res = str.substr(0,end);
    return (end);
}

void skipSpaces(const std::string& str, size_t& n){
    while(std::isspace(str[n]))
        n++;
}

void strToUpper(std::string& str){
    for (size_t i = 0; i < str.size(); i++)
        str[i] = toupper(str[i]);
}

bool getCmd(const std::string& seq, std::string& cmd, size_t& n){
    std::list<std::string> cmds {"NICK", "USER", "JOIN","PASS", "PRIVMSG","KICK","INVITE","TOPIC","MODE"};
    n = subString(seq, " ", cmd);
    if (n = std::string::npos)
        return false;//ALLO
    strToUpper(cmd);
    skipSpaces(seq,n);//check fin?
    for (std::list<std::string>::iterator it = cmds.begin(); *it != cmd && it != cmds.end(); it++){
        if(*it == cmd)
            return true;
    }
    return false;
}

void getParams(const std::string& seq, std::list<std::string>& params, size_t& n){
    std::string par;
    size_t endpar;
    while(n < seq.size() && seq[n] != ':'){
        endpar
    }
}

void parseCmd(const std::string seq){
    std::string prefix;
    std::string cmd;
    std::list<std::string> params;
    std::string trailing;
    size_t end = 0;
    
    if (seq.empty())
        return ;
        
    if (seq[0] == ':'){
        end = subString(seq, " ", prefix);
        if (end = std::string::npos)
            return ;//check format prefixe
        skipSpaces(seq, end);
    }
    if(!getCmd(seq,cmd,end))
        return ;
    for (size_t i = end; i < seq.size();){
        
    }    
    
}

void handleRecMessage(std::string& input){
    std::string cmd;
    size_t end;
    
    for (size_t start = 0; start|| start < input.size();)
    {
        end = subString(input, "\r\n", cmd);
        if (end = std::string::npos)
            return ;//A voir que fait on, on garde un buffer, mais c'est perturbant pour l'utilisateur de devoir reprendre la ou il s'est arrete ou on ignore
        parseCmd(cmd);
        start = end + 2;
    }
}

void readFromClient(int fdSocketClient){
    std::string input;
    char buffer[1024];
    ssize_t n = 1;
    
    while(true){
        n = recv(fdSocketClient, buffer, sizeof(buffer),MSG_DONTWAIT);
        if (n > 0)
            input.append(buffer,n);
        else if (n == -1 ){
            if (errno == EAGAIN || errno == EWOULDBLOCK){
                handleRecMessage(input);
                break;
            }
            else
                throw std::runtime_error("Error: Recv failed: " + std::string(strerror(errno)));
        }
        else if (n == 0)
        {
            rmClient(fdSocketClient);
            break;
        }
    }
}

void handleIn( int& fdSocketServer,int fd, int& epfd, std::list<client>& lstPendingClient){
    if (fd == fdSocketServer){
        if(!acceptClient(fdSocketServer, fd, epfd, lstPendingClient))
            return ;
    }
    else{
        char buffer[512];
        buffer[0] = '\0';
        recv(fd,buffer,sizeof(buffer), MSG_DONTWAIT);
        std::cout << buffer << std::endl;
    }
}

bool handleEpollRequests( int& fdSocketServer, int& epfd, std::list<client>& lstPendingClient){
    epoll_event eventsClients[MAX_EVENTS];//Definir le nombre d'events a gerer
    int n = epoll_wait(epfd, eventsClients, MAX_EVENTS,-1);//Will wait till signal, i suppose handling signal right after, -1 make him wait till request come, 0 will just check if there is a request and keep going
    if (n == - 1 || n == 0)  //theorically, it should not be at zero, the only thing that can stop to wait if not a request is a signal(signal should send -1)
    {
        std::cout << "Error: epoll_wait failed" << std::endl;//ou message cloture serveur
        return false;
    }
    for (int i = 0; i < n; i++)
    {
        if(eventsClients[i].events & EPOLLIN)
            handleIn(fdSocketServer, eventsClients[i].data.fd, epfd, lstPendingClient);
        if(eventsClients[i].events & EPOLLERR || eventsClients[i].events & EPOLLHUP || eventsClients[i].events & EPOLLRDHUP){
            close(eventsClients[i].data.fd);
            std::cout << "Un client s'est deconnecté !"<< std::endl;
        }
            // rmClients(eventsClients[i].data.fd);//a voir(remove frome lstClients dans erver et Channel)
        
    }
    return true;
}

void setupFdServer(int& fdSocketServer, sockaddr_in& addressServer){
    fdSocketServer = socket(AF_INET, SOCK_STREAM, 0);//IPPROTO_TCP = 0, SOCKSTREAM suffit a faire comprendre qu'on utilisera le protocole TCP
    if(fdSocketServer == - 1)//errno possible
        throw std::runtime_error("Error: Socket failed: " + std::string(strerror(errno)));

    nonBlockFd(fdSocketServer);

    if(bind(fdSocketServer, (struct sockaddr*)&addressServer,sizeof(addressServer)) == - 1)//errno possible(interessant erreur port)
        throw std::runtime_error("Error: Bind failed: " + std::string(strerror(errno)));
    
    if(listen(fdSocketServer,10) == - 1)//errno possible
        throw std::runtime_error("Error: Listen failed: " + std::string(strerror(errno)));
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
    setupFdServer(_fdSocketServer,_addressServer);
    setupEpoll(_fdSocketServer, _epfd);//listen apres?
 
    while(_lstClient.size() != 3)
    {
        handleEpollRequests(_fdSocketServer, _epfd, _lstPendingClient);
    }
    close (_fdSocketServer);
}