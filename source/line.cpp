#include "line.h"

Line::Line()
	:point_a{0.}, point_b{1.}
{
}

void Line::Draw() const
{
	std::cout << "The line is drawn.\n";	
}
