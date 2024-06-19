#pragma once
#include <iostream>

class Shapes
{
public:
	Shapes() = default;
	virtual ~Shapes() = default;

	virtual void Draw() const = 0;

private:

};