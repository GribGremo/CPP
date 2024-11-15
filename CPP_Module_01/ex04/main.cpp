/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylabbe <sylabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:12:05 by sylabbe           #+#    #+#             */
/*   Updated: 2024/11/15 13:27:18 by sylabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

std::string replace_str(std::string &line,std::string &to_find,std::string &to_replace)
{
    size_t n = 0;
    size_t start = 0;
    std::string result;
    if (to_find.empty()) {
        return line;
    }
    while(n != std::string::npos)
    {
        n = line.find(to_find,start);
        if (n != std::string::npos)
        {
            result += line.substr(start,n - start) + to_replace;
            // line = line.substr(n + to_find.length(), line.length());
            start = n + to_find.length();
        }
    }
    result += line.substr(start,line.length());
    return (result);
}

int main(int argc, char **argv)
{
    (void)argc;
    if (argv[1] == NULL)
    {
        std::cout <<"No filename detected" << std::endl;
        return (1);
    }
    std::string filename(argv[1]);
    if (filename.empty())
    {
        std::cout << "Empty filename detected" << std::endl;
        return (1);
    }
    std::string filename_rep(argv[1]);
    filename_rep += ".replace";
    if (argv[2] == NULL)
    {
        std::cout <<"No 'string to search' detected" << std::endl;
        return (1);
    }
    std::string to_find(argv[2]);
    if (to_find.empty())
    {
        std::cout << "Empty 'string to search' detected" << std::endl;
        return (1);
    }
    if (argv[3] == NULL)
    {
        std::cout <<"No 'replace string' detected" << std::endl;
        return (1);
    }
    std::string to_replace(argv[3]);
    if (to_replace.empty())
    {
        std::cout << "Empty 'replace string' detected" << std::endl;
        return (1);
    }
    std::ifstream ifs(filename.c_str());
    std::string line;

    if (!ifs.is_open())//
    {
        std::cout << "Cannot open file " << "\"" + filename + "\"" << std::endl;
        return (1);
    }
    std::ofstream ofs(filename_rep.c_str());
    if (!ofs.is_open())//
    {
        std::cout << "Cannot open file " << "\"" + filename_rep + "\"" << std::endl;
        ifs.close();
        return (1);
    }
    while (std::getline(ifs, line)) 
    {
        if (ifs.eof())
            std::cout << "TATA" <<std::endl;
        line = replace_str(line,to_find,to_replace);
        ofs << line << std::endl;
    }
    
    ifs.close();
    ofs.close();
}
