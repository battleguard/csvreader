#include "CsvReader.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

CsvFile CsvReader::Parse(std::string aFileName)
{
   CsvFile file;
   std::ifstream fs(aFileName);
   assert(fs.good());

   { // get headers
      std::string         headers;
      std::getline(fs, headers);
      std::stringstream   headerStream(headers);
      for (std::string header; std::getline(headerStream, header, ',');)
      {
         CsvColumn column = { header, static_cast<int>(file.Columns.size())};
         file.Columns.push_back(column);
      }
   }
   { // get data
      for(std::string line; std::getline(fs, line);)
      {
         std::stringstream   lineStream(line);
         std::string cell;
         for(auto& column : file.Columns)
         {
            std::getline(lineStream, cell, ',');
            column.Data.push_back(std::stod(cell));
         }
      }
      file.ColumnLength = static_cast<int>(file.Columns.front().Data.size());
   }
   return file;
}
