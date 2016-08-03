#include"WebCreator.h"

// constructor to set a title
WebCreator::WebCreator(const string& title)
{
    m_title = title;
}
// destructor to cleanup dynamic memory
WebCreator::~WebCreator()
{
    for (int i = 0; i < m_elementList.size(); i++)
    {
        delete m_elementList[i];
        m_elementList[i] = nullptr;
    }
}
// convert files in to html
void WebCreator::ConvertToHtml(const string& stylePath, const string& pagePath, const string& outputPath)
{
    ReadStyle(stylePath);
    ReadPage(pagePath);
    BuildPage(outputPath);
}
// This function will read in the .style script file and create Style objects for each, pushing them onto
//the m_styleList vector once read in.

void WebCreator::ReadStyle(const string& stylePath)
{
    ifstream fin;
    fin.open(stylePath);//"C:\\Users\\Gulnoza\\Desktop\\sample_style.style"
    while (fin.good())
    {
        Style styleObject;
        fin >> styleObject;
        m_styleList.push_back(styleObject);
    }
}
//This function will read in the .page script file and create Element objects for each, pushing a pointer to
//the new element's address onto the m_elementList vector
void WebCreator::ReadPage(const string& PagePath)
{
    string line = "";
    string tmpline = "";
    string type = "";
    bool EverythingProcessed = false;
    ifstream fin(PagePath);

    while (getline(fin, line))
    {
        EverythingProcessed = false;
        if (line == "HEADER" || line == "PARAGRAPH"
            || line == "LINK" || line == "TEXTBOX"
            || line == "BUTTON")

        {
            type = line;
            tmpline = "";
        }
        else if (line != "")
        {
            tmpline = tmpline + line + "\n";
        }
        else if (line == "")
        {
            istringstream ss(tmpline);
            IElement *newElement;
            newElement = nullptr;
            if (type == "HEADER")
            {
                newElement = new Header;
            }
            else if (type == "LINK")
            {
                newElement = new Anchor;
            }
            else if (type == "PARAGRAPH")
            {
                newElement = new Paragraph;
            }
            else if (type == "TEXTBOX")
            {
                newElement = new Textbook;
            }
            else if (type == "BUTTON")
            {
                newElement = new Button;
            }

            ss >> *newElement;
            m_elementList.push_back(newElement);
            string line = "";
            string tmpline = "";
            string type = "";
            ss.clear();
            newElement = nullptr;
            EverythingProcessed = true;
        }
    }

    if (EverythingProcessed == false)
    {
        IElement *newElement2 = NULL;
        istringstream ss2(tmpline);
        if (type == "HEADER")
        {
            newElement2 = new Header;
        }
        else if (type == "LINK")
        {
            newElement2 = new Anchor;
        }
        else if (type == "PARAGRAPH")
        {
            newElement2 = new Paragraph;
        }
        else if (type == "TEXTBOX")
        {
            newElement2 = new Textbook;
        }
        else if (type == "BUTTON")
        {
            newElement2 = new Button;
        }

        ss2 >> *newElement2;
        m_elementList.push_back(newElement2);
        string line = "";
        string tmpline = "";
        string type = "";
        ss2.clear();
        newElement2 = nullptr;
        EverythingProcessed = true;
    }
}
//The build page function will create an ostream object, then pass that object to OutputHeader,
//OutputStyles, OutputElements, OutputFooter, then close the ostream object.

void WebCreator::BuildPage(const string& outputPath)
{
    ofstream out;
    out.open(outputPath);
    OutputHeader(out);
    OutputStyles(out);
    OutputElements(out);
    OutputFooter(out);
    out.close();
}
//Output the header of an HTML file
ostream& WebCreator::OutputHeader(ostream& out)
{
    out << "<!DOCTYPE html><html>" << endl
        << "<head>" << endl
        << "<title>" << m_title << "</title>" << endl
        << "</head><body>" << endl;
    return out;
}
//Output the CSS for a webpage
ostream& WebCreator::OutputStyles(ostream& out)
{
    out << "<style type='text/css'>" << endl;

    for (int i = 0; i < m_styleList.size(); i++)
    {
        out << m_styleList[i];
    }
    out << "</style>" << endl;
    return out;
}
//Output all of the elements from the m_elementList.

ostream& WebCreator::OutputElements(ostream& out)
{
    for (int i = 0; i < m_elementList.size(); i++)
    {
        out << *m_elementList[i];
    }
    return out;
}
//Output the end of the HTML page
ostream& WebCreator::OutputFooter(ostream& out)
{
    out << endl << "</body></html>" << endl;
    return out;
}
