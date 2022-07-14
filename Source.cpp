#include <iostream>

class my_array
{
public:
	int* m_begin;
	size_t m_size;

	my_array(size_t size) :
		m_size{ size }, m_begin{ (int*) malloc(size * sizeof(int)) } 
	{
		set_default(size);
	}

	void set_default(size_t size)
	{
		for (int i = 0; i < (size * sizeof(int)); i += 4)
		{
			int* start_location = this->m_begin;
			int* next_location = start_location + i;
			*next_location = 0;
		}
	}

	int value_at_index(size_t index)
	{
		int* result_location = this->m_begin + (index * 4);
		return *result_location;
	}

	void insert(size_t index, int value)
	{
		int* location = this->m_begin + (index * 4);
		*location = value;
	}
};

int main()
{
	my_array array1(10);

	array1.insert(5, 26);

	for (int i = 0; i <= array1.m_size; ++i)
	{
		std::cout << array1.value_at_index(i) << std::endl;
	}
}
