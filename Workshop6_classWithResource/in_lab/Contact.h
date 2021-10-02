// Workshop 6 - Class with a Resource
// Contact.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/7/12


#ifndef SAFE_CONTACT_H
#define SAFE_CONTACT_H

namespace  sict
{
	const int MAX_CHAR = 20;

	class Contact {

	private:
		char m_name[MAX_CHAR];
		long long *m_phone = nullptr;
		int m_numbers = 0;

	public:
		Contact();
		Contact(const char *name, const long long *phone, int numbers);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
#endif