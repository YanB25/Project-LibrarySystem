#ifndef _MY_LIBRARY_H__
#define _MY_LIBRARY_H__

#include <string>
#include <set>
#include <vector>
#include <utility>
using std::string;
using std::multiset;
using std::vector;
using std::pair;

//below is states about book
enum State {Borrowed, Available};

class Book {
public:
	typedef string name_t;
	
	Book() = delete;//we do not allow default constructor
	explicit Book(const name_t& _name) : name(_name), state(Available) { }
	Book(name_t&& _name) noexcept : name(std::move(_name)), state(Available) { }
	~Book() = default;

	//we use book name to sort
	bool operator<(const Book& other) const { return name < other.name; }
	bool operator==(const Book& other) const { return name == other.name; }

	State GetState() const { return state; }
	name_t GetName() const { return name; }
	void SetName(const name_t& _name) { name = _name; }
	void SetState(State newState) { state = newState; }
private:
	name_t name;
	State state;
};



//below is about library
class Library {
public:
	typedef multiset<Book> data_t;
	typedef typename Book::name_t name_t;
	typedef typename data_t::iterator Iterator;
	typedef vector<Book> Info_t;
	typedef string file_name_t;

	Library() = default;
	//we do not allow copy
	Library(const Library&) = delete;
	Library& operator=(const Library&) = delete;
	
	void Insert(const name_t& bookName) { libraryData.insert(Book(bookName)); }
	bool Remove(const name_t& name);
	bool Borrow(const name_t& name);
	bool GiveBack(const name_t& name);
	//return a container contains the infomation of One book
	Info_t GetBookInfo(const name_t& name) const ;
	Info_t GetAllBookInfo() const;
	//count the number of a certain book
	size_t Count(const name_t& name) const { return libraryData.count(Book(name)); }
	size_t NumOfBook() const { return libraryData.size(); }
	//file io
	void SaveToFile(const file_name_t& fileName) const;
	bool LoadFromFile(const file_name_t& fileName);
private:
	data_t libraryData;
	//return std::pair indicate a range of books with the same name 
	inline auto _find(const name_t& name) const -> const pair<Iterator, Iterator> { return libraryData.equal_range(Book(name)); }
};


#endif
