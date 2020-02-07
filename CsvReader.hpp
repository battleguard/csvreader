#pragma once
#include <istream>
#include <utility>
#include <vector>

class CsvColumn : public std::vector<double>
{
public:
   CsvColumn(std::string aHeader, int aColumnIndex)
      : Header(std::move(aHeader)),
        ColumnIndex(aColumnIndex) {}

   const std::string Header;
   const int ColumnIndex;
};

class CsvFile : public std::vector<CsvColumn>
{
public:
   size_t GetColumnLength() const { return empty() ? 0 : at(0).size(); }
};

struct CsvReader 
{
   static CsvFile Parse(std::string aFileName);
};
