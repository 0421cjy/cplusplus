#pragma once

#include <iostream>

class MyMathClass
{
public:
    MyMathClass();
    ~MyMathClass();

public:
    void FindPrimeFactor();
    void FindPrimeFactor2();

private:
    void FindPrimeFactor(int number);
};
