#include "IElement.h"
// can remain empty
IElement::~IElement()
{
    ;
}
// overload operator
ostream& operator<<(ostream& out, IElement& item)
{
    return item.Output(out);
}
// overload operator
istream& operator>>(istream& in, IElement& item)
{
    return item.Input(in);
}
