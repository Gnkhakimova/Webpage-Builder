#ifndef IELEMENT_H
#define IELEMENT_H

#include <iostream>
#include<string>
#include"Style.h"

using namespace std;
// parent class
class IElement
{
public:
    ~IElement();
    friend ostream& operator<<(ostream& out, IElement& item);
    friend istream& operator>>(istream& in, IElement& item);
protected:
    // make functions pure virtual in order to overwrite them in dirived classes
    virtual ostream& Output(ostream& out) = 0;
    virtual istream& Input(istream& in) = 0;
};

#endif