#include <iostream>
#include "FileIterator.h"


FileIterator::FileIterator(const string & _fileMask)
{
	this->FileMask = _fileMask;
}



/*FileItem * doSearch()
{
	//...
}
FileItem * doSearch(const std::string & _fileMask)
{
	//...
}*/


bool FileIterator::hasMore()
{
	if (cache != NULL)
		return true;

	//cache = doSearch();
	return cache != NULL;
}


FileItem * FileIterator::Next()
{
	if (!hasMore())
		throw "File not found.";
	FileItem * res = cache;
	cache = NULL;
	return res;
}

inline bool FileIterator::IsDirectory(const _finddata_t &FindData)
{
	return ((FindData.attrib & _A_SUBDIR) != 0);
}


int FileIterator::compareToMask(const string & mask, const string & file)
{
	int pos = 0;
	for (unsigned  int i = 0; i < mask.length(); i++)
		for (unsigned  int j = pos; j < file.length(); j++)
		{
			pos = j;
			if (mask[i] == '*')
			{
				if (file[j] == '.')
					break;
				else
					continue;
			}
			else if ((mask[i] == '?') || (mask[i] == file[j]))
			{
				pos++;
				break;
			}
			return 0;
		}
	return 1;
}


















