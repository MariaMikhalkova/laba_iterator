
#include <io.h>
#include <iostream>

#include <string>


#include "FileIterator.h"

void main(int argc, char *argv[])
{
	std::string FileMask;
	FileIterator * it = new FileIterator();

	if (argc > 1)
		FileMask = argv[1];
	else
	{
		std::cout << "Vvedite disk and path: " << std::endl;
		std::cin >> FileMask;
		if (!FileMask.length())
			return;

	}

	/*
	~smth~
	while(it->hasMore)
	it->Next();
	*/
}










