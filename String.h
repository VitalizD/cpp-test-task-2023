#pragma once

#include<ostream>

class String
{
public:
	String(); // конструктор по умолчанию
	String(const char* c_str); // конструктор для последовательности символов
	String(const String& other); // конструктор копирования
	String(String&& other) throw(); // конструктор перемещения
	~String(); // деструктор
	char* c_str() const; // C-строка
	size_t length() const; // длина строки
	String& operator=(const String& other); // оператор присваивания с копированием
	String& operator=(String&& other) throw(); // оператор присваивания с перемещением
	String& operator=(const char* c_str); // оператор присваивания с копированием (C-style)
	String& operator+=(const String& other); // оператор инкремента
	String& operator+=(const char* c_str); // оператор инкремента (C-style)
	friend String operator+(const String& lvalue, const String& rvalue); // оператор сложения
	friend String operator+(const String& lvalue, const char* rvalue); // оператор сложения (C-style)
	friend std::ostream& operator<<(std::ostream& os, const String& str); // оператор сдвига
	char operator[](unsigned index) const; // оператор индексирования
	bool operator<(const String& other) const; // оператор "меньше"
	bool operator>(const String& other) const; // оператор "больше"

private:
	char* data;
	size_t size;
};