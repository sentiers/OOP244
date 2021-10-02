// Workshop 6 - Class with a Resource
// Contact.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/7/15


#ifndef SAFE_CONTACT_H
#define SAFE_CONTACT_H

namespace  sict
{
	const int MAX_CHAR = 20;

	class Contact {

	private:
		char m_name[MAX_CHAR + 1];
		long long *m_phone = nullptr;
		int m_numbers = 0;

		bool isValid(long long PHONE);

	public:
		Contact();
		Contact(const char *name, const long long *phone, int numbers);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact(const Contact& refer);
		Contact& operator=(const Contact& refer);
		Contact& operator+=(long long newPhone);
	};
}
#endif