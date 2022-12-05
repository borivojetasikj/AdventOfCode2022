#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

namespace AoC2022
{
  /* --- Day 2: Rock Paper Scissors --- */
  class Day2
  {
    public:
      Day2();
      ~Day2() = default;
  
      void SolvePuzzles();
    private:
      enum class ShapeScore : std::uint8_t
      {
        ROCK = 1,
        PAPER = 2,
        SCISSORS = 3,
        UNKNOWN = 0xFF
      };
      
      enum class GameResultScore : std::uint8_t
      {
        LOSE = 0,
        DRAW = 3,
        WIN = 6,
        UNKNOWN = 0xFF
      };

      bool PrepareInputData();
      void Puzzle1Solver();
      void Puzzle2Solver();
      
      std::uint8_t FindShapeScore(const char shapeChar);
      std::uint8_t FindGameScore(const char resultChar);
      
      std::ifstream _inputFile;
      bool _inputDataReady;
      
      std::vector<std::string> _inputData;

      /* 
         1 - (A) ROCK (X)
         2 - (B) PAPER (Y) 
         3 - (C) SCISSORS (Z)
         ----------
         0 - LOSE
         3 - DRAW
         6 - WIN
         ---------- */
      std::map<const std::string, const std::uint8_t> roundsCombinations{{"A X", 3}, {"B X", 0}, {"C X", 6},
                                                                         {"A Y", 6}, {"B Y", 3}, {"C Y", 0},
                                                                         {"A Z", 0}, {"B Z", 6}, {"C Z", 3}};
                                                                         
      /* What to play to:
        ----------
        X - LOSE
        Y - DRAW
        Z - WIN
        ---------- */                                                
      std::map<const std::string, const char> game2rounds {{"A X",'Z'}, {"B X",'X'}, {"C X",'Y'},
                                                           {"A Y",'X'}, {"B Y",'Y'}, {"C Y",'Z'},
                                                           {"A Z",'Y'}, {"B Z",'Z'}, {"C Z",'X'}};

  };
}
