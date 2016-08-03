#include <iostream>
#include <string>
#include"IElement.h"
using namespace std;

//Wraps the <input> tag, for a button object.
class Button :public IElement
{
private:
    string m_name;
    string m_value;
public:
    ~Button();
    virtual istream& Input(istream& in);
    virtual ostream& Output(ostream& out);

};