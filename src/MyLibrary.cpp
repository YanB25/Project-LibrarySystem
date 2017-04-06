#include "MyLibrary.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
//codes below implements "MyLibrary.h"
//for the function below, "name" means the name of the book

//libraryData.find(...) return iterator
bool Library::Remove(const name_t& name) {
	auto it = libraryData.find(Book(name));
	if (it == libraryData.end()) {
		return false;
	}
	libraryData.erase(it);
	return true;
}

//_find(...) is a private member that return std::pair<iterator, iterator>, denoted a range
bool Library::Borrow(const name_t& name) {
	auto pairs = _find(name);
	auto it = pairs.first;
	for (auto it = pairs.first; it != pairs.second; ++it) {
		if (it->GetState() == Available) {
			//it may not be a good style but it helps
			Book& borrowBook = const_cast<Book&> (*it);
			borrowBook.SetState(State::Borrowed);
			return true;
		}
	}

}

bool Library::GiveBack(const name_t& name) {
	auto pairs = _find(name);
	for (auto it = pairs.first; it != pairs.second; ++it) {
		if (it->GetState() == State::Borrowed) {
			//it may not be a good style but it helps
			Book& giveBackBook = const_cast<Book&> (*it);
			giveBackBook.SetState(Available);
			return true;
		}
	}
	return false;
}

vector<Book> Library::GetBookInfo(const name_t& name) const {
	auto pairs = _find(name);
	return vector<Book>(pairs.first, pairs.second);
}

vector<Book> Library::GetAllBookInfo() const {
	return vector<Book>(libraryData.begin(), libraryData.end());
}

void Library::SaveToFile(const file_name_t& fileName) const {
	ofstream of(fileName);
	for (auto it = libraryData.begin(); it != libraryData.end(); ++it) {
		of <<(int) (it->GetState()) << " " << it->GetName() << endl;
	}
}
		
bool Library::LoadFromFile(const file_name_t& fileName) {
	ifstream inf(fileName);
	if (!inf) {
		return false;
	}
	libraryData.clear();
	string name;
	int state;
	while (inf >> state) {
		while(inf.peek() == ' ') inf.get();
		getline(inf, name);
		Book inputBook(name);
		inputBook.SetState(State(state));
		libraryData.insert(inputBook);
	}
	return true;
}
		
