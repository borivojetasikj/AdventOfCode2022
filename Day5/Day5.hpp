#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <stack>
#include <array>

namespace AoC2022
{
  /* --- Day 5:  --- */
  class Day5
  {
    public:
      Day5();
      ~Day5() = default;
  
      void SolvePuzzles();
    private:
      bool PrepareInputData();

      void Puzzle1Solver();
      void Puzzle2Solver();

      void ClearStack(std::stack<char>& stack);
      void SetupInitialStacksValues();

      std::ifstream _inputFile;
      bool _inputDataReady;
      
      std::vector<std::string> _inputData;
      std::vector<std::tuple<std::uint8_t, std::uint8_t, std::uint8_t>> _crateMovingFromTo;
      
      static constexpr std::uint8_t TOTAL_STACKS = 9;
      std::array<std::stack<char>, TOTAL_STACKS> _stacksArray;
      
      const char stack1Crates[3] = { 'Z', 'J', 'G'};
      const char stack2Crates[8] = { 'Q', 'L', 'R', 'P', 'W', 'F', 'V', 'C' };
      const char stack3Crates[7] = { 'F', 'P', 'M', 'C', 'L', 'G', 'R' };
      const char stack4Crates[7] = { 'L', 'F', 'B', 'W', 'P', 'H', 'M' };
      const char stack5Crates[6] = { 'G', 'C', 'F', 'S', 'V', 'Q'};
      const char stack6Crates[8] = { 'W', 'H', 'J', 'Z', 'M', 'Q', 'T', 'L'};
      const char stack7Crates[5] = { 'H', 'F', 'S', 'B', 'V'};
      const char stack8Crates[4] = { 'F', 'J', 'Z', 'S'};
      const char stack9Crates[8] = { 'M', 'C', 'D', 'P', 'F', 'H', 'B', 'T'};
  };
}
