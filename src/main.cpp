/*
by 颜彬
class 7
student's id 16337269
github: YanB25

*/

#include "MyLibrary.h"
#include "frame.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::find;
using std::string;
using std::istringstream;
using std::regex;
using std::smatch;

/*
note:
use regular expression to check the inputs
the rule of a valid bookname is the same as that of a valid variable named
the name should start with a letter or '_',followed by a series of letters, digits or '_' 
*/

//you do not have to understand them below
const string OrderPattern("^(quit|help|save|load|prta|cnta)(\\s.*)?$|^(add|rm|brw|ret|cnt|prt)");
const string validPattern("^(quit|help|save|load|prta|cnta|(add|rm|brw|ret|cnt|prt) [a-z\\sA-Z_]+(\\w|_)*)$");

int main() {
	Library library; //the system
	PrintInstroduction(cout);
	string order;//the first words that the user inputs
	string name;//the second words that the user inputs
	
	string input;
	//regex
	regex checkOrder(OrderPattern);
	regex checkAll(validPattern);
	smatch results;
	
	while (true) {
		PrintPromt(cout); //print ">>> "
		//when we simply touch "Enter",we creat a new line 
		if (cin.peek() == '\n') {
			cin.get();
			continue;
		}
		
		//get input, order and name
		getline(cin, input);
		istringstream sin(input);
		sin >> order;
		//discard spaces
		while (sin.peek() == ' ') sin.get();
		getline(sin, name);
		
		//check the syntax
		if (!regex_search(input, results, checkOrder)) {
			//print a caret to indicate where the error happened
			//it is like "     ^"
			PrintErrorLocation(cout, 4); 
			PrintError(cout, "Syntax Error: invalid order. use <help> to get help");
			continue;
		} else if (!regex_search(input, results, checkAll)) {
			PrintErrorLocation(cout, order.length() + 5);
			PrintError(cout, "Syntax Error: invalid parameter, please check both number and format");
			continue;
		} 
		
		//work
		if (order == "quit") {
			exit(0);
		}
		
		else if (order == "help") {
			PrintHelp(cout);
		} 
		
		else if (order == "cnta") {
			cout << "the number of books is: " << library.NumOfBook() << endl;
		}
		
		else if (order == "prta") {
			PrintTable(cout, library);
		}
		
		else if (order == "save") {
			library.SaveToFile(FileName); //constant FileName declared in "frame.h"
		}
		
		else if (order == "load") {
			if (!library.LoadFromFile(FileName)) {
				PrintError(cout, "Runtime Error: Fail to open file");
			}
		}
		
		else if (order == "add") {
			library.Insert(name);
		}
	
		else if (order == "rm") {
			if (!library.Remove(name)) {
				PrintError(cout, "Runtime Error: Fail to remove, plz check the book name");
			}
		}
	
		else if (order == "brw") {
			if (!library.Borrow(name)) {
				PrintError(cout, "Runtime Error: Fail to borrow, plz check whether there is any available one");
			}
		}
	
		else if (order == "ret") {
			if (!library.GiveBack(name)) {
				PrintError(cout, "Runttime Error: Fail to return, no this book or no more books borrowed");
			}
		}
	
		else if (order == "cnt") {
			cout << "The number of book named \"" << name << "\" is "<< library.Count(name) << endl;
		}
	
		else if (order == "prt") {
			//if there's no book named name
			if(library.Count(name) == 0) {
				PrintError(cout, "RuntTime Error: No this book");
			} else {
				PrintOneBook(cout, library, name);
			}
		
		} else {
			PrintError(cout, "Syntax Error: no order named " + order);
		}
	}	
}

