#include<iostream>
using namespace std;
class String {

	char* _str;
	size_t _size;
	size_t _capacity;
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator begin() const
	{
		return _str;
	}

	const_iterator end() const
	{
		return _str + _size;
	}
	static const size_t npos;
	String()
		:_size(0)
		,_capacity(15)
	{
		_str = new char[15 + 1];
		_str[_size] = '\0';
	}
	String(const char* str)
		:_size(strlen(str))
		,_capacity(strlen(str))
	{
		_str = new char[_size + 1];
		strcpy(_str, str);
	}
	//String(const String& str)
	//	:_str(new char[str._capacity + 1])
	//	,_size(str._size)
	//	,_capacity(str._capacity)
	//{
	//	strcpy(_str, str._str);
	//
	//}
	void Swap(String& str) {
		swap(str._capacity, _capacity);
		swap(str._size, _size);
		swap(str._str, _str);
	}
	String(const String& str)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		String tmp(str._str);
		Swap(tmp);
	}
	//String& operator=(const String& str){
	//	if (&str != this) {
	//		char* tmp = new char[str._capacity + 1];
	//		strcpy(tmp, str._str);
	//		delete[] _str;
	//		_str = tmp;
	//		_capacity = str._capacity;
	//		_size = str._size;
	//	}
	//	return *this;
	//}
	String& operator=(String str) {
		Swap(str);
		return *this;
	}
	const char* c_str() const {
		return _str;
	}
	~String() {
		if (_str) {
			delete _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

	}
	void pushBack(const char& ch) {
		if (_size == _capacity) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}

	void reserve(size_t n) {
		if (n > _capacity) {
			char* tmp = new char[n];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	char& operator[](size_t n) {
		if (n < _size) {
			return _str[n];
		}
	}
	const char& operator[](size_t n) const {
		if (n < _size) {
			return _str[n];
		}
	}
	size_t size() const {
		return _size;
	}
	void Append(const char* str) {
		int len = strlen(str);
		if (_capacity < len + _size) {
			reserve(len + _size);

		}
		strcpy(_str + _size, str);
		_size += len;
	}
	String& operator+=(const char& ch) {
		pushBack(ch);
		return *this;
	}
	String& operator+=(const char* str) {
		Append(str);
		return *this;
	}
	void insert(size_t pos, const char& ch) {
		if (pos > _size)
			return;
		if (_capacity == _size) {
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}
		size_t end = _size + 1;
		while (end > pos) {
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
	}
	void insert(size_t pos, const char* str) {
		if (pos > _size)
			return;
		int len = strlen(str);
		if (_capacity < _size + len) {
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end < pos + len) {
			_str[end] = _str[end - len];
			end--;
		}
		for (int i = 0; i < len; i++) {
			_str[pos + i] = str[i];
		}
		_size += len;
	}
	void resize(size_t n,const char& ch = '\0') {
		if (n > _capacity) {
			reserve(n);
		}
		if (n > _size) {
			memset(_str + _size, ch, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}
	void popBack() {
		erase(_size - 1, 1);
	}
	void erase(size_t pos, size_t n) {
		if (pos < _size) {
			if (pos + n >= _size) {
				_size = pos;
				_str[_size] = '\0';
			}
			else {
				for (int i = pos + n; i <= _size; i++) {
					_str[pos++] = _str[i];
				}
			}
			_size -= n;
		}
	}
	size_t find(const char* str) {
		char* ptr = strstr(_str, str);
		if (str)
			return ptr - _str;
		else
			return npos;
	}
};
const size_t String::npos = -1;
String operator+(const String& s, const String& str)
{
	String ret(s);
	ret += str.c_str();
	return ret;
}
String operator+(const String& s, const char* str)
{
	String ret(s);
	ret += str;
	return ret;
}
String operator+(const String& s, const char& ch)
{
	String ret(s);
	ret += ch;
	return ret;
}
ostream& operator<<(ostream& cout, const String& str)
{

	for (const auto& ch : str)
		cout << ch;


	return cout;
}

void printString(const String& str)
{

	String::const_iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << " ";

		++it;
	}
	cout << endl;
}