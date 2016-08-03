#ifndef WEBCREATOR_H
#define WEBCREATOR_H
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include "IElement.h"
#include"Anchor.h"
#include "Button.h"
#include "Header.h"
#include"Paragraph.h"
#include"Textbook.h"
using namespace std;

//The WebCreator object contains all relevant functionality and information for our Script-to-HTML
//converter.
class WebCreator
{
private:
    vector <Style> m_styleList;
    vector <IElement*> m_elementList;
    string m_title;
    void ReadStyle(const string& stylePath);
    void ReadPage(const string& ReadPage);
    void BuildPage(const string& outputPath);
    ostream& OutputHeader(ostream& out);
    ostream& OutputStyles(ostream& out);
    ostream& OutputElements(ostream& out);
    ostream& OutputFooter(ostream& out);

public:
    WebCreator(const string& title);
    ~WebCreator();
    void ConvertToHtml(const string& stylePath, const string& pagePath, const string& outputPath);
};

#endif