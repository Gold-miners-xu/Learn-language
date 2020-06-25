#include<iostream>
#include<string>
using namespace std;
template <class T>
class Vector {
	T* _start;
	T* _finish;
	T* _eos;
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_eos(nullptr)
	{

	}
	size_t size()const {
		return _finish - _start;
	}
	size_t capacity()const {
		return _eos - _start;
	}
	void pushBack(const T& val) {
		if (_finish == _eos) {
			size_t newC = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newC);
		}
		*_finish = val;
		_finish++;
	}
	void reserve(size_t n) {
		if (n > capacity()) {
			T* tmp = new T[n];
			for (int i = 0; i < size(); i++) {
				tmp[i] = _start[i];
			}
			_finish = tmp + size();
			delete[] _start;
			_start = tmp;
			_eos = tmp + n;
		}
	}
	T& operator[](size_t n) {
		if (n < size())
			return _start[n];
	}
	const T& operator[](size_t n)const {
		if (n < size())
			return _start[n];
	}
	iterator begin() {
		return _start;
	}
	iterator end() {
		return _finish;
	}
	const_iterator begin()const {
		return _start;
	}
	const_iterator end()const {
		return _finish;
	}
	void resize(size_t n, const T& val = T()) {
		if (n > capacity())
			reserve(n);
		if (n > size()) {
			while (_finish != _start + n) {
				*_finish = val;
				_finish++;
			}

		}
		_finish = _start + n;
	}
	void insert(iterator pos, const T& val) {
		if (pos >= _start && pos <= _finish) {
			if (_finish == _eos) {
				size_t len = pos - _start;
				size_t newC = capacity() == 0 ? 1 : 2 * capacity();
				reserve(newC);
				pos = _start + len;
			}
			iterator it = _finish;
			while (pos < it) {
				*it = *(it - 1);
				it--;
			}
			*pos = val;
			_finish++;
		}
	}
	iterator erase(iterator pos) {
		if (pos >= _start && pos < _finish) {
			iterator it = pos + 1;
			while (it != _finish) {
				*(it - 1) = *it;
				it++;
			}
			_finish--;
		}
		return pos;
	}
	Vector(const Vector& v) {
		_start = new T[v.size()];
		for (int i = 0; i < v.size(); i++) {
			_start[i] = v[i];
		}
		_finish = _start + v.size();
		_eos = _start + v.capacity();
	}
	~Vector() {
		if (_start) {
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}
	Vector<T>& operator=(Vector<T> v){
		Swap(v);
		return *this;
	}
	void Swap(Vector<T>& v) {
		swap(v._start, _start);
		swap(v._finish, _finish);
		swap(v._eos, _eos);
	}
};
template <class T>
void printVector(const Vector<T>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
int main() {
	Vector<int> v;
	v.pushBack(1);
	v.pushBack(2);
	v.pushBack(3);
	return 0;
}