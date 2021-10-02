// Final Project Milestone 5
// Error.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;
namespace aid
{
	void Error::safeState()
	{
		m_msg = nullptr;
	}

	Error::Error(const char* errorMessage)
	{
		if (errorMessage == nullptr || errorMessage[0] == '\0')
		{
			safeState();
		}
		else
		{
			int msgLen = strlen(errorMessage) + 1;
			m_msg = new char[msgLen];
			strncpy(m_msg, errorMessage, msgLen);
		}
	}

	Error::~Error()
	{
		delete[] m_msg;
		safeState();
	}

	void Error::clear()
	{
		delete[] m_msg;
		safeState();
	}

	bool Error::isClear() const
	{
		return m_msg == nullptr || m_msg[0] == '\0';
	}

	void Error::message(const char* str)
	{
		delete[] m_msg;

		if (str == nullptr || str[0] == '\0')
		{
			safeState();
		}
		else
		{
			int strLen = strlen(str) + 1;
			m_msg = new char[strLen];
			strncpy(m_msg, str, strLen);
		}
	}

	const char* Error::message() const
	{
		char * msg;
		isClear() ? msg = nullptr : msg = m_msg;

		return msg;
	}

	std::ostream& operator<<(std::ostream& os, const Error& error) 
	{
		if (!error.isClear()) os << error.message();

		return os;
	}
}