/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:23:35 by sylabbe           #+#    #+#             */
/*   Updated: 2025/10/09 17:10:40 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
*/

struct pars{
    u_short port;
    std::string password;
};

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

    int fdSocketServer = socket(AF_INET, SOCK_STREAM, 0);//IPPROTO_TCP = 0, SOCKSTREAM suffit a faire comprendre qu'on utilisera le protocole TCP
    if(fdSocketServer == -1){//errno possible
        std::cout << "Error: Socket failed to create"<< std::endl;
        return (1);
    }

    sockaddr_in addressServer;//Describes an IPV4 internet domain socket address
    addressServer.sin_family = AF_INET;
    addressServer.sin_port = htons(p.port);
    addressServer.sin_addr.s_addr = inet_addr("127.0.0.1");//defaut a voir

    if(bind(fdSocketServer, (struct sockaddr*)&addressServer,sizeof(addressServer)) == - 1)//errno possible(interessant erreur port)
    {
        std::cout << "Error: Bind failed to associate address to socket" << std::endl;
        return (1);
    }

    if(listen(fdSocketServer,10) == - 1)//errno possible
    {
        std::cout << "Error: Listen failed" << std::endl;
        return (1);
    }
    while(true)
    {
        sockaddr_in addressClient;
        socklen_t addressClientLen = sizeof(addressClient);
        int fdSocketClient = accept(fdSocketServer,(struct sockaddr*)&addressServer,&addressClientLen);
        if(fdSocketClient == - 1)
        {
            std::cout << "Error: Accept failed" << std::endl;
            return (1);
        }


        std::cout << "Un client s'est connecté !\n";

        const char* msg = "Hello !\n";

        close(fdSocketClient); // On ferme la socket du client, mais le serveur reste en écoute
    }
    
    close(fdSocketServer);
}
/*
___sockaddr_in____
|sin_family      |
|sin_port        |      ____sin_addr_____
|sin_addr --------------> u long s_addr |
~~~~~~~~~~~~~~~~~~      ~~~~~~~~~~~~~~~~~
*/