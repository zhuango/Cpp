#include<iostream>
#include<array>
#include<string>

template <class T, size_t n>//there is a template that class and size_t
void display(const std::array<T, n> & ar);
int main()
{
	std::array<int, 5> ai = {1, 2, 3, 4, 5};
	std::array<std::string, 5> as = {
		"string under sonstruction",
		"stupid string indeed",
		"there'a nothing to see",
		"nothing to do",
		"but enjoy all that is"
	};

	display(ai);;
	display(as);

	return 0;
}

template <class T, size_t n>
void display(const std::array<T, n> & ar)
{
	for(int i = 0; i < 5; i++)
		std::cout << ar[i] << std::endl;
}
