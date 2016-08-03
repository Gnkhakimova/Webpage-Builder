#include"Paragraph.h"

// destructor
Paragraph::~Paragraph()
{
    ;
}
// overwrite the function to read in own version
istream& Paragraph::Input(istream& in)
{
    string temper;
    while (getline(in, temper))
    {
        m_text = temper;
    }
    return in;
}
// overwrite the function
ostream& Paragraph::Output(ostream& out)
{
    out << "<p>" << m_text << "</p>" << endl;
    return out;
}