#include <iostream>
#include <string>
#include"IElement.h"
using namespace std;

//Wraps the <input> tag, for a text object
class Textbook :public IElement
{
private:
    string m_name;
public:
    ~Textbook();
    virtual istream& Input(istream& in);
    virtual ostream& Output(ostream& out);
};

