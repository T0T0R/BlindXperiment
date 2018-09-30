#pragma once

#include <string>

class Group
{
public:
	Group();
	Group(int number);
	Group(std::string string);
	Group(int number, std::string string);
	~Group();

	int getNumber() const;
	std::string getString() const;

	void setNumber(int number);
	void setString(std::string string);

protected:
	int m_number;
	std::string m_string;
};

