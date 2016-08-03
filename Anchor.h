#ifndef ANCHOR_H
#define ANCHOR_H

#include <iostream>
#include <string>
#include"IElement.h"
using namespace std;

//The anchor object will wrap the <a> tag.
class Anchor :public IElement
{
private:
    string m_href;
    string m_text;
public:
    ~Anchor();
    virtual istream& Input(istream& in);
    virtual ostream& Output(ostream& out);
};
#endif