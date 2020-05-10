#include <nanorange.hpp>
#include <fmt/core.h>
#include <vector>

using namespace nano;

int main()
{
	auto v = std::vector{ 1, 2, 3, 4, 5, 6 };
	auto r = v | views::reverse;

	for (auto &&i : r)
	{
		fmt::print("{}, ", i);
	}

	fmt::print("\n{:06.2f}", 3.14159);

	return 0;
}