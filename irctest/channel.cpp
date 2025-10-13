#include "channel.hpp"

//CONSTRUCTORS/DESTRUCTOR
channel::channel(){

}
channel::channel(client cl, std::string channelName){
    _lstOpe.push_back(cl);
    _lstClient.push_back(cl);//A voir si ope dans client aussi
    _channelName = channelName;
}
channel::channel(const channel& src){
    for(std::list<client>::const_iterator it = src._lstClient.begin(); it != src._lstClient.end(); it++)
        _lstClient.push_back(*it);
    for(std::list<client>::const_iterator it = src._lstOpe.begin(); it != src._lstOpe.end(); it++)
        _lstOpe.push_back(*it);
    _channelName = src._channelName;
}
channel::~channel(){

}
//OPERATORS
channel& channel::operator=(const channel& src){
    if (this == &src)
        return (*this);
    for(std::list<client>::const_iterator it = src._lstClient.begin(); it != src._lstClient.end(); it++)
        _lstClient.push_back(*it);
    for(std::list<client>::const_iterator it = src._lstOpe.begin(); it != src._lstOpe.end(); it++)
        _lstOpe.push_back(*it);
    _channelName = src._channelName;
}
//METHODS
void channel::addChanClient(client& cl){

}
void channel::rmChanClient(client& cl){
    for(std::list<client>::iterator it = _lstClient.begin(); it != _lstClient.end(); it++)
    {
        if(*it == cl)
            it = _lstClient.erase(it);
    }
    for(std::list<client>::iterator it = _lstOpe.begin(); it != _lstOpe.end(); it++)
    {
        if(*it == cl)
            it = _lstOpe.erase(it);
    }
    if (_lstClient.empty())

}

void channel::sendMessage(std::string msg, client emitter){
    for(std::list<client>::iterator it = _lstClient.begin(); it != _lstClient.end(); it++)
    {
        
    }
}
