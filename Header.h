#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include"IElement.h"
using namespace std;

//Wraps the <h1>, <h2>, and <h3> tags
class Header : public IElement
{
private:
    string m_text;
    int m_headerLevel;
public:
    Header();
    ~Header();
    virtual istream& Input(istream& in);
    virtual ostream& Output(ostream& out);

};
#endif