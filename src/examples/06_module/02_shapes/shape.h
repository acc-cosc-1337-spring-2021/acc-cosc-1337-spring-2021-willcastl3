//shape.h
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape// abstract class
{
public:
    virtual void draw()=0;// pure virtual function
};
#endif