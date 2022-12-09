#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <utility>

namespace AoC2022
{
  /* --- Day 4: Camp Cleanup --- */
  class Day4
  {
    public:
      Day4();
      ~Day4() = default;
  
      void SolvePuzzles();
    private:
      bool PrepareInputData();
      void Puzzle1Solver();
      void Puzzle2Solver();
      
      std::uint8_t FindShapeScore(const char shapeChar);
      std::uint8_t FindGameScore(const char resultChar);
      
      std::ifstream _inputFile;
      bool _inputDataReady;
      
      std::vector<std::string> _inputData;
      std::vector<std::string> _inputDataPair1;
      std::vector<std::string> _inputDataPair2;
      
      std::vector<std::pair<std::uint8_t, std::uint8_t>> pair1;
      std::vector<std::pair<std::uint8_t, std::uint8_t>> pair2;
  };
}
