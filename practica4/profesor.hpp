//clase profesor
#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

#include <iostream>
#include <string>
using namespace std;


class Pofesor
{
private:
    string userName_;
    string password_;
    int id_;

public:
    Profesor(string userName , string password , int id){
        setId(id);
        setUserName(userName);
        setPassword(password);
            };

string getUserName(){return userName_;};
string getPassword(){return password_;};
int getId(){return id_;};

void setUserName(string userName){userName_ = userName;};
void setPassword(string password){password_ = password;};
void setId(int id){id_ = id;};


};

#endif;

