#include "Writer.h"
#include <iostream>

int main()
{
	Writer writer;
	writer.write(65 << 8 | 97);
	std::cout << writer.getContent() << std::endl;
}
