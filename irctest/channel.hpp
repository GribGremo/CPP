#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "client.hpp"

#include <iostream>
#include <list>

class channel{
    public:
    channel();
    channel(client cl, std::string channelName);
    channel(const channel& src);
    ~channel();
    channel& operator=(const channel& src);

    void addChanClient(client& cl);
    void rmChanClient(client& cl);

    void sendMessage(std::string msg, client emitter);

    private:
    std::list<client> _lstClient;
    std::list<client> _lstOpe;
    std::string _channelName;
};

#endif