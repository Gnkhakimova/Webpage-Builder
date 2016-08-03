#include "Anchor.h"

Anchor::~Anchor()
{
    ;
}
//overwriting input function to read in own version
istream& Anchor::Input(istream& in)
{
    string temper;
    in >> m_href;
    while (getline(in, temper))
    {
        m_text = temper;
    }
    return in;
}
// overwrinting output function
ostream& Anchor::Output(ostream& out)
{
    out << "<a href='" << m_href << "'>" << m_text << "</a>" << endl;
    return out;
}