#include "ARGE/ARGE.hpp"

namespace ARGE
{
	ARGE::ARGE()
	{

	}
}

using namespace ARGE;

int main()
{
	Window* window = new Window();
	window->Create();
	while (window->Loop());
	return 0;
}