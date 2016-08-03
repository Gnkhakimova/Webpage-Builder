#include"Textbook.h"
//destructor
Textbook::~Textbook()
{
    ;
}
//overwrite the function to read in own version
istream& Textbook::Input(istream& in)
{
    in >> m_name;
    return in;
}
// overwrite the function
ostream& Textbook::Output(ostream& out)
{
    out << "<input type='text' name='" << m_name << "'>" << endl;
    return out;
}