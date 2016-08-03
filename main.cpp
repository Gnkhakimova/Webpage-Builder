/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program: Webpage Builder.
Due Date:	04/10/2016
Description:  For this program, a user will be able to create a webpage by writing some script files. These script files
are not HTML and CSS, but contain the basic information needed to build the HTML and CSS from
within our program.
Inputs:  Will load in a .page file and a .style file, then build a .html page.
Outputs: Web Page
Algorithm:
-Style Object-Element Objects   -Anchor Object   -Paragraph Object   -Header Object   -Textbox Object   -Button Object-WebCreator Object-The main() functionPRE:Input files (Style Page, Sample Page) 
POST: Webpage Output file(Output)
*/

#include<iostream>
#include "WebCreator.h"

using namespace std;

//  will create a WebCreator object (pass in
//a page title to the constructor), then call ConvertToHtml on that object, passing in the paths for the
//input files and output file.
int main()
{
    WebCreator webObject("Dog Adoption");
    // change paths as needed, path to input and output files
    webObject.ConvertToHtml("C:\\Users\\Gulnoza\\Desktop\\sample_style.style",
        "C:\\Users\\Gulnoza\\Desktop\\sample_page.page",
        "C:\\Users\\Gulnoza\\Desktop\\output.html");
    return 0;
}