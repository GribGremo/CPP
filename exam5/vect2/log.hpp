#ifndef LOG_HPP
#define LOG_HPP

#ifdef DEBUG
    #define LOG(x) std::cerr << "[DEBUG] " << x <<std::endl
#else
    #define LOG(x)
#endif

#endif