#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace AoC2022
{
  /* --- Day 1: Calorie Counting --- */
  class Day1
  {
    public:
      Day1();
      ~Day1() = default;
  
      void SolvePuzzles();
    private:
      static constexpr std::int8_t DISTINGUISHING_ELFS_VALUE = -1;
      
      bool PrepareInputData();
      std::uint32_t Puzzle1Solver();
      void Puzzle2Solver();
      
      std::ifstream _inputFile;
      bool _inputDataReady;
      std::vector<int> _inputData;
      
      std::uint32_t _elfWithMaxCalories; 
      std::uint32_t _sumOfTop3WithMaxCalories; 
  };
}
