#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <array>

namespace AoC2022
{
  /* --- Day 6: Tuning Trouble --- */
  class Day6
  {
    public:
      Day6();
      ~Day6() = default;
  
      void SolvePuzzles();
    private:
      static constexpr std::uint8_t PART1_CHARACTERS_MARKER = 4;
      static constexpr std::uint8_t PART2_CHARACTERS_MARKER = 14;

      bool PrepareInputData();

      std::uint32_t FindCharacterMarkerIndex(std::uint8_t totalDistinctCharactersFromBeggining);

      void Puzzle1Solver();
      void Puzzle2Solver();

      std::ifstream _inputFile;
      bool _inputDataReady;
      
      std::string _inputData;
  };
}
