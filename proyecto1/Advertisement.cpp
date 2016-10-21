/*
INTEGRANTES:

Richard Hearn 8-906-1268
Michael Abril CC-1116-263511
Osmar Berrocal 8-808-957
Alberto Juarez 8-853-1956

*/



#include "Advertisement.h"
#include <string>  
#include <sstream> 
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

Advertisement::Advertisement(void): number(0), quantity(0), title(""), 
	seller_email(""), body(""), start(), close() {} 

Advertisement::Advertisement(const Advertisement &a): number(a.getNumber()), 
	quantity(a.getQuantity()), title(a.getTitle()), seller_email(a.getEmail()),
	body(a.getBody()), start(a.getStart()), close(a.getClose()) {}

Advertisement::Advertisement(string title, string seller_email, string body, Date 
	start, Date close, int quantity): title(title), seller_email(seller_email), 
	body(body), start(start), close(close), quantity(quantity), number(0) {}

void Advertisement::setStart(const Date &start) {
	this->start = start;
}

void Advertisement::setClose (const Date &close) {
	this->close = close;
}

void Advertisement::setTitle (string title) {
	this->title = title;
}

void Advertisement::setBody (string body) {
	this->body = body;
}

void Advertisement::setNumber (int number) {
	this->number = number;
}

void Advertisement::setEmail (string email) {
	this->seller_email = email;
}

void Advertisement::setQuantity (int quantity) {
	this->quantity = quantity;
}

Date Advertisement::getStart () const {
	return start;
}

Date Advertisement::getClose () const {
	return close;
}

string Advertisement::getTitle() const {
	return title;
}

string Advertisement::getBody() const {
	return body;
}

string Advertisement::getEmail() const {
	return seller_email;
}

int Advertisement::getNumber () const {
	return number;
}

int Advertisement::getQuantity() const {
	return quantity;
}

bool Advertisement::operator==(const Advertisement& advertisement) const {
	if (number == advertisement.getNumber()) {
		return true;
	} else {
		return false;
	}
}



static inline std::string &trim(std::string &s) {
return trim(trim(s));
            }

static inline std::string &ltrim(std::string &s) {
s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
return s;
            }

static inline std::string &rtrim(std::string &s) {
s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
return s;
            }
            
istream &operator>>(istream &stream, Advertisement &a) { 
	stringstream ss, ss1; 
	Date date;
	string s;
    getline(stream, s);
    trim(s);
    a.setTitle(s);  
    getline(stream, s);
    trim(s);
    a.setEmail(s);
    getline(stream, s);
    trim(s);
    
    a.setQuantity(atoi(s.c_str())); 
    getline(stream, s);
    trim(s);
    ss << s;   
    ss >> date;   
    a.setStart(date);      
    getline(stream, s);
    trim(s);
    ss1 << s;    
    ss1 >> date;   
    a.setClose(date);  
    getline(stream, s);
    trim(s); 
    a.setBody(s); 
	return stream;
}
