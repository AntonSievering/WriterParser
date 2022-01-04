#include "Writer.h"
#include "Parser.h"
#include <iostream>

int main()
{
	Writer writer;
	int v1 = 100001;
	int v2 = 200002;
	writer.write(v1);
	writer.write(v2);
	std::cout << writer.getContent() << std::endl;
	
	StackParser sp = StackParser(writer.getContent());
	std::cout << sp.parse<int>() << " " << sp.parse<int>() << std::endl;

	Parser parser = Parser(writer.getContent());
	std::cout << parser.parse<int>() << " " << parser.parse<int>() << std::endl;
}
