/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:23:35 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/11 19:14:20 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

#include <cstdlib> //strtol
#include <climits> //USHRT_MAX

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>//socket(),bind(),listen(),accept()
#include <netinet/in.h>//sockaddr_in
#include <arpa/inet.h>//inet_addr()
#include <unistd.h>
/*
Socket Setup : socket, setsockopt, bind, listen

Multi-client : poll, accept

Communication : recv, send

Confort : inet_ntop, htons, signal

Gestion de signaux propre : sigaction, sigemptyset


🔴 Critique	    socket, bind, listen, accept, recv, send, poll	                   Connexions clients / serveur TCP
🟡 Essentiel	setsockopt, close, getaddrinfo, htons, ntohs, inet_ntop, signal	   Fiabilité / compatibilité
🔵 Utile	    fcntl, sigaction, sig*set, gethostbyname, getsockname              Sécurité / signal / debug
⚪ Rare	       connect, lseek, fstat, getprotobyname	                          Surtout si serveur agit aussi comme client ou gère des fichiers

htons: convert a unsigned short into in_port_t format(a kind of unsigned short but for network)
inet_addr: convert string IP address into in_addr(format structure)
listen: rend disponible ce socket pour la reception de clients(2earg: nombre de clients en attente de validation a acceder au socket)
fcntl: permet de gerer le comportement d'un fd (le rendre non-bloquant par exemple)
*/


bool isFormatPasswordCompatible(std::string password){
    if ((password.size() > 64 || password.size() < 1))
        return (false);
    for(int i = 0; i < password.size();i++){
        if(!std::isprint(password[i]) || password[i] == ' ')
            return (false);
    }
    return (true);
}

bool parsing(int argc, char **argv, pars& p){
    char *end = NULL;
    if (argc != 3)
        return false;
    long int n = std::strtol(argv[1],&end,10);//parsing
    if (*end != '\0' || n <= 0 || n > USHRT_MAX)//A voir la range des ports utilisables
        return (false);
    p.port = n;
    p.password = argv[2];
    if(!isFormatPasswordCompatible(p.password))
        return (false);
    return (true);
}

int main(int argc, char **argv){
    pars p;
    if (!parsing(argc,argv,p))
        return (1);
    server serv = server(p);
    try{
        serv.launch();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
/*
___sockaddr_in____
|sin_family      |
|sin_port        |      ____sin_addr_____
|sin_addr --------------> u long s_addr |
~~~~~~~~~~~~~~~~~~      ~~~~~~~~~~~~~~~~~
*/