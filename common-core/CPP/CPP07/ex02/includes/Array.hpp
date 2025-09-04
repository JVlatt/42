#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
public:
	size_t size() const
	{
		return _size;
	}

	Array()
	{
		_size = 0;
		_elements = NULL;
	}

	Array(const Array<T> &_other)
	{
		_size = _other.size();
		_elements = new T[_size]();
		for(unsigned int i = 0; i < _size; ++i)
		{
			_elements[i] = T(_other[i]);
		}
	}

	~Array()
	{
		delete[] _elements;
	}

	Array(int _len)
	{
		_size = _len;
		_elements = new T[_size]();
	}

	Array<T> &operator=(const Array<T> &_other)
	{
		if (this != &_other)
		{
			if (_elements)
				delete [] _elements;
			_size = _other.size();
			_elements = new T[_size]();
			for(unsigned int i = 0; i < _size; ++i)
			{
				_elements[i] = T(_other[i]);
			}
		}
		return (*this);
	}

	T &operator[](int i)
	{
		if (i < 0)
			throw(std::invalid_argument("Index cannot be negative !"));
		if (size() <= (unsigned int) i )
			throw(std::out_of_range("Index out of range !"));
		return (_elements[i]);
	}

	T &operator[](int i) const
	{
		if (i < 0)
			throw(std::invalid_argument("Index cannot be negative !"));
		if (size() <= (unsigned int) i )
			throw(std::out_of_range("Index out of range !"));
		return (_elements[i]);
	}

private:
	size_t _size;
	T *_elements;
};

#endif
