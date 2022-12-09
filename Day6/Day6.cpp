#include "Day6.hpp"

namespace AoC2022
{
  Day6::Day6():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }

  void Day6::SolvePuzzles()
  {
    std::cout << "[Day 6] ";
    Puzzle1Solver();
    Puzzle2Solver();
  }

  bool Day6::PrepareInputData()
  {
    bool inputParsed = false;
    if (_inputFile)
    {
      while (_inputFile)
      {
        getline(_inputFile, _inputData, '\0');
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }

  std::uint32_t Day6::FindCharacterMarkerIndex(std::uint8_t totalDistinctCharactersFromBeggining)
  {
    std::string str = "";
    bool duplicate = false;
    std::uint16_t characterMarkerIndex = 0;
    for (std::uint32_t ind = 0; ind < _inputData.size() - totalDistinctCharactersFromBeggining; ind++)
    {
      characterMarkerIndex = ind + totalDistinctCharactersFromBeggining;      
      str.clear();
      str = _inputData.substr(ind, totalDistinctCharactersFromBeggining);
      duplicate = false;
      for (std::string::iterator it = str.begin(); it != str.end(); it++)
      {
        for (std::string::iterator it1 = (it + 1); it1 != str.end(); it1++)
        {
          if (*it == *it1)
          {
            duplicate = true;
            break;
          }
        }
        if (duplicate) break;
      }
      if (!duplicate) break;
    }
    std::cout << str << " ";
    return characterMarkerIndex;
  }

  void Day6::Puzzle1Solver()
  {  
    std::cout << "Part1: " << FindCharacterMarkerIndex(PART1_CHARACTERS_MARKER) << std::endl;
  }
  
  void Day6::Puzzle2Solver()
  {
    std::cout << "\tPart2: " << FindCharacterMarkerIndex(PART2_CHARACTERS_MARKER) << std::endl;
  }
}
