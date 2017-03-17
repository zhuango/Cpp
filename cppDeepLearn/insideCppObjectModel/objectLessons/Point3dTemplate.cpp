#include <iostream>
#include <assert.h>
using namespace std;

template<class T, int dim>
class Point
{
public:
	Point() {}
	Point(T coords[dim])
	{
		for (int i = 0; i < dim; ++i)
		{
			this->mCoords[i] = coords[i];
		}
	}

	T & operator[](int index)
	{
		assert(index < dim && index >= 0);
		return this->mCoords[index];
	}

	T operator[](int index) const
	{
		assert(index < dim && index >= 0);
		return this->mCoords[index];
	}
private:
	T mCoords[dim];
};

void testPoint3dTemplate()
{
	int array[5] = { 1, 2, 3, 4, 5 };
	Point<int, 5> p(array);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
}