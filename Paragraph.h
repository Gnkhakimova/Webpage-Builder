#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <iostream>
#include<string>
#include"IElement.h"
using namespace std;

// will wrap the <p> tag.
class Paragraph :public IElement
{
private:
    string m_text;
public:
    ~Paragraph();
    virtual istream& Input(istream& in);
    virtual ostream& Output(ostream& out);
};

#endif