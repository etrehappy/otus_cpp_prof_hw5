#pragma once
#include "shape.h"

class Circle : public Shapes
{
public:
	Circle();
	~Circle() = default;

	void Draw() const;

private:
	double radius;
};