#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // ULListStr *list = new ULListStr();
  // list->push_front(2);
	const size_t numElements = 50;
	const Seed origSeed = 18;

	std::vector<std::string> contents(makeRandomAlphaStringVector(numElements, origSeed, 12, true));

	ULListStr * list = makeList(contents);

	for(int index = static_cast<int>(contents.size() - 1); index >= 0; --index)
	{
		list->pop_back();
		contents.erase(contents.begin() + index);
		EXPECT_TRUE(checkListContent(list, contents));
	}

	delete list;

}
