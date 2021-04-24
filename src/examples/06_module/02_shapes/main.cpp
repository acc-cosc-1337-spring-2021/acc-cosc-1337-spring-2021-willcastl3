#include <iostream>
#include<memory>
#include<vector>
#include "shape.h"
#include "line.h"
#include "circle.h"
using std::vector;
using std::unique_ptr; using std::make_unique;

int main()
{
    vector<unique_ptr<Shape>>shapes;
    unique_ptr<Shape> line = make_unique<Line>();
    unique_ptr<Shape> circle = make_unique<Circle>();

    shapes.push_back(std::move(line));
    shapes.push_back(std::move(circle));

    for (auto& shape: shapes)
    {
        shape->draw();

    }
	return 0;
}