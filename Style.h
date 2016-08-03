#include<iostream>
#include<string>
using namespace std;

// The Style object will be a simple struct to hold CSS information. 
struct Style
{
    string element;
    string attribute;
    string value;
    friend istream& operator>>(istream& in, Style& item);
    friend ostream& operator <<(ostream& out, const Style& item);
};