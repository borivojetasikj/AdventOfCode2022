#include "Day4.hpp"

namespace AoC2022
{
  Day4::Day4():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }

  void Day4::SolvePuzzles()
  {
    std::cout << "[Day 4] ";
    Puzzle1Solver();
    Puzzle2Solver();
  }

  bool Day4::PrepareInputData()
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
          std::string pair1Str = line.substr(0, ',');
            pair1.push_back(std::make_pair(std::stoi(pair1Str.substr(0, pair1Str.find_first_of('-'))),
              std::stoi(pair1Str.substr(pair1Str.find_first_of('-')+1, pair1Str.size()))));

            std::string pair2Str = line.substr(line.find_last_of(',') + 1, line.size());
            pair2.push_back(std::make_pair(std::stoi(pair2Str.substr(0, pair2Str.find_first_of('-'))),
              std::stoi(pair2Str.substr(pair2Str.find_first_of('-') + 1, pair2Str.size()))));
        }
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }

  void Day4::Puzzle1Solver()
  {
    std::uint32_t pairsFullyContainingOthers = 0;
    for (int ind = 0; ind < pair1.size(); ind++)
    {
      // P1(A1,A2) vs. P1(B1,B2)
      std::uint8_t A1 = pair1.at(ind).first;
      std::uint8_t A2 = pair1.at(ind).second;
      std::uint8_t B1 = pair2.at(ind).first;
      std::uint8_t B2 = pair2.at(ind).second;

      if (((A1 != A2) && (B1 != B2))
        || ((A1 != A2) && (B1 == B2))
        || ((A1 == A2) && (B1 != B2)))
      {
        // ex. 3-5, 1-6
        if (((A1 >= B1) && (A2 <= B2)) ||
        // ex. 1-6, 3-5 
            ((A1 <= B1) && (A2 >= B2)))
        {
          pairsFullyContainingOthers++;
        }
      }
      else if(A1 == A2)
      { 
        //ex. 3-3, 1-5
        if ((A1 >= B1) && (A2 <= B2))
        {
          pairsFullyContainingOthers++;
        }
      
      }
      else if (B2 == B2)
      {
        //ex. 1-5, 3-3
        if ((A1 <= B1) && (A2 >= B2))
        {
          pairsFullyContainingOthers++;
        }
      }
    }
    std::cout << "Game 1: Total score = " << pairsFullyContainingOthers << std::endl; // 464 sol. pt 1
  }
  
  void Day4::Puzzle2Solver()
  {
    std::uint32_t pairsOverlapping = 0;
    for (int ind = 0; ind < pair1.size(); ind++)
    { 
      // P1(A1,A2) vs. P2(B1,B2)
      std::uint8_t A1 = pair1.at(ind).first;
      std::uint8_t A2 = pair1.at(ind).second;
      std::uint8_t B1 = pair2.at(ind).first;
      std::uint8_t B2 = pair2.at(ind).second;

      if ((A1 == B1) || (A2 == B2))
      {
        pairsOverlapping++;
      }
      else if (A1 > B1)
      {
        if (B2 >= A1)
          pairsOverlapping++;
      }
      else
      {
        if(A2>=B1)
          pairsOverlapping++;
      }
    }
    std::cout << "\tGame 2: Total score = " << pairsOverlapping << std::endl;
  }
}
