#include "Day3.hpp"

namespace AoC2022
{
  Day3::Day3():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }

  void Day3::SolvePuzzles()
  {
    std::cout << "[Day 3] ";
    Puzzle1Solver();
    Puzzle2Solver();
  }

  bool Day3::PrepareInputData()
  {
    bool inputParsed = false;
    if (_inputFile)
    {
      std::string line = "";

      while (_inputFile)
      {
        getline(_inputFile, line, '\n');
        if (!line.empty())
        {
          _inputData.push_back(line);
        }
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }

  void Day3::Puzzle1Solver()
  {
    bool found = false;
    std::uint32_t sumOfThePriorities = 0;

    for (auto line : _inputData)
    {
      found = false;
      std::uint32_t strSize = line.size();
      std::string str1 = line.substr(0, (strSize/2));
      std::string str2 = line.substr((strSize/2), strSize);
      for (auto ch1 : str1)
      {
        for (auto ch2 : str2)
        {
          if (ch2 == ch1)
          {
            sumOfThePriorities += FindItemTypePriority(ch2);            
            found = true;
            break;
          }
        }
        if (found) break; // go to next line
      }
    }
    std::cout << "Game 1: Total score = " << sumOfThePriorities << std::endl;
  }
  
  void Day3::Puzzle2Solver()
  {
    std::uint32_t sumOfThePriorities = 0;
    bool found = false;

    for (int line = 0; line < _inputData.size(); line+=3)
    {
      found = false;
      std::string str1 = _inputData[line].data();
      std::string str2 = _inputData[line+1].data();
      std::string str3 = _inputData[line+2].data();

      for (auto ch1 : str1)
      {
        for (auto ch2 : str2)
        {
          if (ch2 == ch1)
          {
            for (auto ch3 : str3)
            {
              if (ch3 == ch2)
              {
                sumOfThePriorities += FindItemTypePriority(ch3);
                found = true;
                break;
              }
            }
          }
          if (found) break;
        }
        if (found) break;
      }
    }
    std::cout << "\tGame 2: Total score = " << sumOfThePriorities << std::endl;
  }

  std::uint8_t Day3::FindItemTypePriority(const char ch)
  {
    std::uint8_t itemPriority = 0;
    if ((ch >= A_CHAR_ASCII_VAL) && (ch <= Z_CHAR_ASCII_VAL))
    {
      itemPriority = (ch - 38); // uppercase priorities: 27 - 52
    }
    else if ((ch >= a_CHAR_ASCII_VAL) && (ch <= z_CHAR_ASCII_VAL))
    {
      itemPriority = (ch - 96); // lowercase priorities: 1 - 26
    }
    return itemPriority;
  }

}
