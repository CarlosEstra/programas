#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
	int array[]{ 30, 50, 20, 10, 40 };
	constexpr int lenght{ static_cast<int>(std::size(array)) };

	for (int startIndex{ 0 }; startIndex < lenght - 1; ++startIndex)
	{
		int smallestIndex{ startIndex };
		for (int currentIndex{ startIndex + 1 }; currentIndex < lenght; ++currentIndex)
		{
			if(array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex
		}

		std::swap(array[startIndex], array[smallestIndex]);
	}
	for (int index{ 0 }; index < lenght; ++index)
		std::cout << array[index] << ' ';

	std::cout << '\n';

	return 0;
}