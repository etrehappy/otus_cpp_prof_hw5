#include "circle.h"

Circle::Circle()
	:radius{1.}
{
}

void Circle::Draw() const
{	
	std::cout << "The circle is drawn.\n";	
}