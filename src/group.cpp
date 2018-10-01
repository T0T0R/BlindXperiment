#include <iostream>
#include <string>

#include "group.h"

Group::Group():
	m_number{0}, m_string{""}, m_comment{""}{}

Group::Group(int number) :
	m_number {number}, m_string {""}, m_comment{""}{}

Group::Group(std::string string) :
	m_number {0}, m_string {string}, m_comment{""}{}

Group::Group(int number, std::string string) :
	m_number {number}, m_string {string}, m_comment{""}{}

Group::~Group(){}


int Group::getNumber() const {return m_number;}
std::string Group::getString() const {return m_string;}
std::string Group::getComment() const {return m_comment;}

void Group::setNumber(int number){m_number=number;}
void Group::setString(std::string string){m_string=string;}
void Group::addComment(std::string comment){m_comment = m_comment + comment;}
