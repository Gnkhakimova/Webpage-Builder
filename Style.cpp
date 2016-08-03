#include "Style.h"

// operator overloading to read in own version
istream& operator>>(istream& in, Style& item)
{
    in >> item.element >> item.attribute >> item.value;
    return in;
}
// operator overloading
ostream& operator <<(ostream& out, const Style& item)
{
    if (item.element != "")
    {
        out << item.element << "{ " << item.attribute << ": " << item.value << "; }" << endl
            << "\n"; //can add this line to have extra new line, but don't think it is needed...
        return out;
    }
}
