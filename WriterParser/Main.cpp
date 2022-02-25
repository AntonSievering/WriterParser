#include "Writer.h"
#include "Parser.h"
#include <iostream>

int main()
{
	Writer writer;
	writer.write(1234567890ui64);

	Parser parser = Parser(writer.getContent());
	std::cout << parser.parse<uint64_t>() << std::endl;
}
