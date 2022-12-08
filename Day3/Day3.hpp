#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

namespace AoC2022
{
  /* --- Day 3: Rucksack Reorganization  --- */
  class Day3
  {
    public:
      Day3();
      ~Day3() = default;
  
      void SolvePuzzles();
    private:
      static constexpr std::uint8_t A_CHAR_ASCII_VAL = 65;
      static constexpr std::uint8_t Z_CHAR_ASCII_VAL = 90;
      static constexpr std::uint8_t a_CHAR_ASCII_VAL = 97;
      static constexpr std::uint8_t z_CHAR_ASCII_VAL = 122;

      bool PrepareInputData();
      void Puzzle1Solver();
      void Puzzle2Solver();
      
      std::uint8_t FindItemTypePriority(const char ch);

      std::ifstream _inputFile;
      bool _inputDataReady;

      std::vector<std::string> _inputData;
  };
}
