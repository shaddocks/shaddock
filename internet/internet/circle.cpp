#include "stdafx.h"
#include "circle.h"


circle::circle()
{
	r = 5;
}

circle::circle(double R) {
	r = R;
}

double circle::area() {
	return 3.14*r*r;
}

circle::~circle()
{
}
