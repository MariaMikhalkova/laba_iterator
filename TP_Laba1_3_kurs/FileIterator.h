#include <io.h>
#include <iostream>
#include <string>
using namespace std;

class FileItem

{
	string name;
	string path;

public:
	FileItem() {};

	FileItem(const string& name, const string& path)
	{
		this->name = name;
		this->path = path;
	}

	void show()
	{
		cout << "File: " << name <<endl;
		cout << "Directory: " << path <<endl;
		cout << "---------" << endl;
	}
};

class FileIterator
{
	FileItem * cache; 
	string FileMask;

	//FileItem * doSearch(); 
	//FileItem * doSearch(const string & _fileMask);

	inline bool IsDirectory(const _finddata_t &FindData);
	int compareToMask(const string & mask, const string & file);

public:
	FileIterator() {};
	FileIterator(const string & _fileMask);

	bool hasMore(); // true, anee au? anou a iia/eaoaeiaao oaeeu, oaiae. ianea
	FileItem * Next();
};






