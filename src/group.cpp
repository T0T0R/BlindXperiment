#include <iostream>
#include <string>

#include "group.h"

Group::Group():
	m_number{0}, m_string{""}{}

Group::Group(int number) :
	m_number {number}, m_string {""}{}

Group::Group(std::string string) :
	m_number {0}, m_string {string}{}

Group::Group(int number, std::string string) :
	m_number {number}, m_string {string}{}

Group::~Group(){}


int Group::getNumber() const {return m_number;}
std::string Group::getString() const {return m_string;}

void Group::setNumber(int number){m_number=number;}
void Group::setString(std::string string){m_string=string;}