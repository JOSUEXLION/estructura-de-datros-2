
/*
INTEGRANTES:

Richard Hearn 8-906-1268
Michael Abril CC-1116-263511
Osmar Berrocal 8-808-957
Alberto Juarez 8-853-1956

*/


#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Client.h"  


using namespace std;

Client::Client(void): 
    fname(""), lname(""), email(""), passwd("") {}; 

Client::Client(Client const &c) : 
	fname(c.fname), lname(c.lname), email(c.email), passwd(c.passwd) {};

Client::Client(string &fname, string &lname, string &email, string &passwd):
	fname(fname), lname(lname), email(email), passwd(passwd) {};

void Client::setFname(const string &fname) { 
	this->fname = fname;
}

void Client::setLname(const string &lname) { 
	this->lname = lname;
}
void Client::setEmail(const string &email) { 
	this->email = email;
}
	
void Client::setPasswd(const string &passwd) { 
	this->passwd = passwd;
}


string Client::getFname () const { 
	return fname;
}

string Client::getLname () const { 
	return lname;
}

string Client::getEmail () const { 
	return email;
}

string Client::getPasswd () const { 
	return passwd;
}

bool Client::verifyPasswd(string passwd) { 
	return this->passwd == passwd;
}

istream &operator>>(istream &stream, Client &c) { 
	string fname, lname, email, passwd;

	stream >> fname >> lname >> email >> passwd;
	c.setFname(fname);
	c.setLname(lname);
	c.setEmail(email);
	c.setPasswd(passwd);

	return stream;
}
