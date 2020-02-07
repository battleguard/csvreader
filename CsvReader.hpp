#pragma once
#include <istream>
#include <vector>

struct CsvColumn
{
   std::string Header;
   int ColumnIndex;
   std::vector<double> Data;
};

struct CsvFile
{
   std::vector<CsvColumn> Columns;
   int ColumnLength;
};

struct CsvReader 
{
   static CsvFile Parse(std::string aFileName);
};
