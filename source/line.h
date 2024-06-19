#pragma once
#include "shape.h"

class Line : public Shapes
{
public:
	Line();
	~Line() = default;

	void Draw() const;

private:
	double point_a;
	double point_b;
};