#include"Header.h"

Header::Header()
{
    ;
}
//destructor
Header::~Header()
{
    ;
}
// overwrite the function to read in own version
istream& Header::Input(istream& in)
{

    string temper = "";

    in >> temper;
    // set headerLevel based on size
    if (temper == "size_big")
    {
        m_headerLevel = 1;
    }
    else if (temper == "size_medium")
    {
        m_headerLevel = 2;
    }
    else if (temper == "size_small")
    {
        m_headerLevel = 3;
    }

    while (getline(in, temper))
    {

        if (temper == "size_big")
        {
            m_headerLevel = 1;
        }
        else if (temper == "size_medium")
        {
            m_headerLevel = 2;
        }
        else if (temper == "size_small")
        {
            m_headerLevel = 3;
        }



        m_text = temper;
    }
    return in;
}
// overwrite the function
ostream& Header::Output(ostream& out)
{
    // output file in order of headerLevel's value
    if (m_headerLevel == 1)
    {
        out << "<h1>" << m_text << "</h1>" << endl;
    }
    else if (m_headerLevel == 2)
    {
        out << "<h2>" << m_text << "</h2>" << endl;
    }
    else if (m_headerLevel == 3)
    {
        out << "<h3>" << m_text << "</h3>" << endl;
    }
    return out;
}