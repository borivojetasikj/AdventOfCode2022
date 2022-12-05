#include "Day2.hpp"

namespace AoC2022
{
  Day2::Day2():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }

  void Day2::SolvePuzzles()
  {
    std::cout << "[Day 2] ";
    Puzzle1Solver();
    Puzzle2Solver();
  }

  bool Day2::PrepareInputData()
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

  void Day2::Puzzle1Solver()
  {
    std::uint32_t totalScore = 0;
    for (auto round : _inputData)
    {
      if (auto search = roundsCombinations.find(round); search != roundsCombinations.end())
      {
        totalScore += ((search->second) + FindShapeScore(search->first.at(2)));
      }
    }
    std::cout << "Game 1: Total score = " << totalScore << std::endl;
  }
  
  void Day2::Puzzle2Solver()
  {
    std::uint32_t totalScore = 0;
    for (auto round : _inputData)
    {
      if (auto search = game2rounds.find(round); search != game2rounds.end())
      {        
        totalScore += (FindShapeScore(search->second) + FindGameScore(search->first.at(2)));
      }
    }
    std::cout << "\tGame 2: Total score = " << totalScore << std::endl;
  }

  std::uint8_t Day2::FindShapeScore(const char shapeChar)
  {
    ShapeScore shapeScore = ShapeScore::UNKNOWN;
    switch (shapeChar)
    {
      case 'X':
        shapeScore = ShapeScore::ROCK;
        break;
      case 'Y':
        shapeScore = ShapeScore::PAPER;
        break;
      case 'Z':
        shapeScore = ShapeScore::SCISSORS;
        break;
      default:
        break;
    }
    return static_cast<std::uint8_t>(shapeScore);
  }
  
  std::uint8_t Day2::FindGameScore(const char resultChar)
  {
    GameResultScore gameScore = GameResultScore::UNKNOWN;
    switch (resultChar)
    {
    case 'X':
      gameScore = GameResultScore::LOSE;
      break;
    case 'Y':
      gameScore = GameResultScore::DRAW;
      break;
    case 'Z':
      gameScore = GameResultScore::WIN;
      break;
    default:
      break;      
    }
    return static_cast<std::uint8_t>(gameScore);
  }
}
