#include "Day1.hpp"
#include <array>

namespace AoC2022
{
  Day1::Day1():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }, 
    _elfWithMaxCalories{ 0 },
    _sumOfTop3WithMaxCalories { 0 }
  {  
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }
  
  void Day1::SolvePuzzles()
  {
    Puzzle1Solver(); 
    _sumOfTop3WithMaxCalories += _elfWithMaxCalories;

    Puzzle2Solver();
    
    std::cout << "[Day 1] Puzzle 1 solution: "
      << _elfWithMaxCalories << " | Puzzle 2 solution: "
      << _sumOfTop3WithMaxCalories << std::endl;
  }
  
  bool Day1::PrepareInputData()
  {
    bool inputParsed = false;
    std::uint16_t lineNum = 1;
    if (_inputFile)
    {
      std::string line = "";

      while (_inputFile)
      {
        getline(_inputFile, line, '\n');

        if (!line.empty())
        {
          _inputData.push_back(std::stoi(line));
        }
        else 
        {
          _inputData.push_back(DISTINGUISHING_ELFS_VALUE);
        }
        lineNum++;
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }
  
  /* Returns max total calories of the food carried by elf */
  std::uint32_t Day1::Puzzle1Solver()
  {
    if (_inputDataReady)
    {
      std::uint32_t currentElfTotalFoodCaloriesCarrying = 0;
      for (auto ind = 0; ind < _inputData.size(); ind++)
      {   
        if (_inputData.at(ind) == -1)
        {
          if (currentElfTotalFoodCaloriesCarrying > _elfWithMaxCalories)
          {
            _elfWithMaxCalories = currentElfTotalFoodCaloriesCarrying;
          }
          currentElfTotalFoodCaloriesCarrying = 0;
        }
        else
        {
          currentElfTotalFoodCaloriesCarrying += _inputData.at(ind);
        }
      }
    }    
    return _elfWithMaxCalories;
  }
  
  /* Finds second two max total calories of the food carried by elf */
  void Day1::Puzzle2Solver()
  {
    if (_inputDataReady)
    {
      std::array<std::uint32_t, static_cast<std::size_t>(2)> second2LargestFoodCalories{ 0, 0 };
      
      std::uint32_t currentElfTotalFoodCaloriesCarrying = 0;
      for (auto ind = 0; ind < _inputData.size(); ind++)
      {
        if (_inputData.at(ind) == -1)
        {
          if(currentElfTotalFoodCaloriesCarrying != _elfWithMaxCalories)
          {
            if (currentElfTotalFoodCaloriesCarrying > second2LargestFoodCalories.at(0))
            {
              second2LargestFoodCalories.at(0) = currentElfTotalFoodCaloriesCarrying;
            }
            else if (currentElfTotalFoodCaloriesCarrying > second2LargestFoodCalories.at(1))
            {
              second2LargestFoodCalories.at(1) = currentElfTotalFoodCaloriesCarrying;
            }
          }
          currentElfTotalFoodCaloriesCarrying = 0;
        }
        else
        {
          currentElfTotalFoodCaloriesCarrying += _inputData.at(ind);
        }
      }

      for (auto calories : second2LargestFoodCalories)
      {
        _sumOfTop3WithMaxCalories += calories;
      }
    }
  }

}
