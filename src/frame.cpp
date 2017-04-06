#include "MyLibrary.h"
#include "frame.h"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::left;
using std::setw;
using std::string;
//for more details, please refer to "frame.h"

void PrintAllBook(ostream& os, const Library& lib) {
	auto info = lib.GetAllBookInfo();
	for (const auto& book : info) {
		PrintBookInOneLine(os, book);
	}
	cout << endl;
}

void PrintInstroduction(ostream& os) {
	os << "\tWelcome to Books Managment System" << endl;
	os << "\tuse <help> to get tutorial" << endl;
	os << "\tuse <quit> to exit" << endl;
}

void PrintHelp(ostream& os) {
	 os << "\t <add> <BookName>  to add" << endl;
	 os << "\t <rm> <BookName> to delete" << endl;
	 os << "\t <brw> <BookName> to borrow" << endl;
	 os << "\t <ret> <BookName> to give back" << endl;
	 os << "\t <cnt> <BookName> to count the books with the same name" << endl;
	 os << "\t <cnta> to get the totaly number of books" << endl;
	 os << "\t <prt> <BookName> to print the information about the book" << endl;
	 os << "\t <prta> to print all the information about the library" << endl;
	 os << "\t <save> to save the information to a file" << endl;
	 os << "\t <load> to load the information to a file" << endl;
	 os << endl;
}

void PrintOneBook(ostream& os, const Library& lib, const name_t& name) {
	PrintTitle(os);
	auto info = lib.GetBookInfo(name);
	for (const auto& book : info) {
		PrintBookInOneLine(os, book);
	}
	os << endl;
}


