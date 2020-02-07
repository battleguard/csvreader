#include <iostream>
#include "CsvReader.hpp"

int main()
{
   CsvReader::Parse("hw_200.csv");
   std::cout << "Hello World" << std::endl;
}