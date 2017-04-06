#ifndef _FRAME_H_
#define _FRAME_H_

#include <iostream>
#include <iomanip>
using std::ostream;
using std::setw;
using std::left;
using std::endl;
typedef Library::name_t name_t;
//the constant below are for format output.
const int NameLength = 20; //how long does the name of a book takes (see func: void PrintBookInOneLine(...))
const int LengthOfLine = 30; //how long does the split-line takes (see func: void PrintTitle() )
const string FileName = "BookSystemData";

//used to print error message
//s means error message
inline void PrintError(ostream& os, const string& s) {
	os  << s << endl;
}

//print all the book in the library
void PrintAllBook(ostream& os, const Library& lib);

void PrintHelp(ostream& os);
void PrintInstroduction(ostream& os);
inline void PrintPromt(ostream& os) {
	os << ">>> " ;
}

//print the title(head) of the table
inline void PrintTitle(ostream& os) {
	os << endl;
	os << left << setw(NameLength) << "Books' Name" << "State" << endl;
	os << string(LengthOfLine, '-') << endl;
}


//when we want to get all the infomation about the library, we use print-table
//the output may take up many lines
inline void PrintTable(ostream& os, const Library& lib) {
	PrintTitle(os);
	PrintAllBook(os, lib);
}


//function to do the real work, print information of the book in one line
inline void PrintBookInOneLine(ostream& os, const Book& book) {
	os << left << setw(NameLength) << book.GetName() << (book.GetState() == Borrowed ? "Borrowed" : "Available") << endl; 
}

//print a series of books with the same name
//the output may take up one line (when there's only one book has this name)
//or may take up many lines
void PrintOneBook(ostream& os, const Library& lib, const name_t& name); 

//print the location of errors
//it would be like "       ^"
//the caret point to the word that is an error
void inline PrintErrorLocation(ostream& os, size_t pos) {
	os << string(pos, ' ') << '^' << endl;
}
#endif
