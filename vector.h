#include<iostream>
template<class T>
class vector
{
public:
	typedef T value_type;
	typedef T* iterator;
	vector() { _start = _end = _finish = NULL; }
	~vector() { delete[]_start; }
	bool push_back(const T& e)
	{
		if (_end == _finish)resize();
		*_end = e;
		_end++;
		return true;
	}
	bool pop()
	{
		if (_start == _end)return false;
		_end--;
		return true;
	}
	T back()
	{
		return *(_end - 1);
	}
	T front()
	{
		return *_start;
	}
	iterator begin() { return _start; }
	iterator end() { return _end; }
	int size() { return end() - begin(); }
	T operator[](int n)
	{
		if (n<0 || n>=size())exit(0);
		return *(_start + n);
	}
protected:
	iterator _start;
	iterator _end;
	iterator _finish;
private:
	void resize()
	{
		int old_size = _finish - _start;
		int new_size = old_size == 0 ? 1 : 2 * old_size;
		iterator new_start = new T[new_size];
		memcpy(new_start, _start, old_size*sizeof(T));
		delete[] _start;
		_start = new_start;
		_finish = _start + new_size;
		_end = _start + old_size;
	}
};