// Final Project Milestone 5
// Error.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

#ifndef SAFE_ERROR_H
#define SAFE_ERROR_H

namespace aid
{
	class Error {
		
		char * m_msg;
		void safeState();

	public:
		explicit Error(const char* errorMessage = nullptr);
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream& os, const Error& error);
}
#endif
