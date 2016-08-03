#include"Button.h"
//destructor
Button::~Button()
{
    ;
}
// overwrite the function to read in own version
istream& Button::Input(istream& in)
{
    string temper;
    in >> m_name;
    while (getline(in, temper))
    {
        m_value = temper;
    }
    return in;
}
// overwrite the function
ostream& Button::Output(ostream& out)
{
    out << "<input type='button' name='" << m_name << "' value='" << m_value << "'>" << endl;
    return out;
}
