#include "Day5.hpp"

namespace AoC2022
{
  Day5::Day5():
    _inputFile{ "input.txt", std::ios_base::in },
    _inputDataReady{ false }
  {
    if (PrepareInputData())
    {
      _inputDataReady = true;
    }
  }

  void Day5::SolvePuzzles()
  {
    SetupInitialStacksValues();
    std::cout << "[Day 5] ";
    Puzzle1Solver();
    SetupInitialStacksValues();
    Puzzle2Solver();
  }

  bool Day5::PrepareInputData()
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
          std::string crateNumber = line.substr(line.find_first_of(' '), line.find_first_of(' ') - 1);          
          std::string moveFrom = line.substr(line.find("from") + 4, line.find_first_of(' ') - 1);          
          std::string moveTo = line.substr(line.find_last_of(' '), - 1);
          _crateMovingFromTo.push_back(std::make_tuple(std::stoi(crateNumber), std::stoi(moveFrom), std::stoi(moveTo)));
        }
      }
      _inputFile.close();
      inputParsed = true;
    }
    return inputParsed;
  }

  void Day5::Puzzle1Solver()
  {
    for (auto [totalCrates, from, to] : _crateMovingFromTo)
    {
      std::size_t fromArrayIndex = static_cast<size_t>(from - 1);
      std::size_t toArrayIndex = static_cast<size_t>(to - 1);
      while (totalCrates > 0)
      {
        const char elementToMove = _stacksArray.at(fromArrayIndex).top();
        _stacksArray.at(toArrayIndex).push(elementToMove);
        _stacksArray.at(fromArrayIndex).pop();
        totalCrates--;
      }
    }

    std::cout << "Game 1: ";
    for (auto stack : _stacksArray)
    {
      std::cout << stack.top() << "";
    }
    std::cout << std::endl;
  }
  
  void Day5::Puzzle2Solver()
  {
    for (auto [totalCrates, from, to] : _crateMovingFromTo)
    {
      std::size_t fromArrayIndex = static_cast<size_t>(from - 1);
      std::size_t toArrayIndex = static_cast<size_t>(to - 1);
      
      char elementToMove = _stacksArray.at(fromArrayIndex).top();
      if (totalCrates == 1)
      {
        _stacksArray.at(toArrayIndex).push(elementToMove);
        _stacksArray.at(fromArrayIndex).pop();
      }
      else // > 1
      {
        std::stack<char> helperStack;
        while (totalCrates > 0)
        {
          elementToMove = _stacksArray.at(fromArrayIndex).top();
          helperStack.push(elementToMove);
          _stacksArray.at(fromArrayIndex).pop();

          totalCrates--;
        }

        while (!helperStack.empty())
        {
          _stacksArray.at(toArrayIndex).push(helperStack.top());
          helperStack.pop();
        }
      }
    }

    std::cout << "\tGame 2: ";
    for (auto stack : _stacksArray)
    {
      std::cout << stack.top() << "";
    }
    std::cout << std::endl;
  }

  void Day5::ClearStack(std::stack<char>& stack)
  {
    while (!stack.empty())
    {
      stack.pop();
    }
  }

  void Day5::SetupInitialStacksValues()
  {   
    std::uint8_t stackId = 1;
    char crates[8] = {'\0'}; 
    for (auto& stack : _stacksArray)
    {
      if (!stack.empty())
      {
        ClearStack(stack);
      }

      if (stackId == 1)
      {
        memcpy(crates, stack1Crates, sizeof(stack1Crates));
      }
      else if (stackId == 2)
      {
        memcpy(crates, stack2Crates, sizeof(stack2Crates));
      }
      else if (stackId == 3)
      {
        memcpy(crates, stack3Crates, sizeof(stack3Crates));
      }
      else if (stackId == 4)
      {
        memcpy(crates, stack4Crates, sizeof(stack4Crates));
      }
      else if (stackId == 5)
      {
        memcpy(crates, stack5Crates, sizeof(stack5Crates));
      }
      else if (stackId == 6)
      {
        memcpy(crates, stack6Crates, sizeof(stack6Crates));
      }
      else if (stackId == 7)
      {
        memcpy(crates, stack7Crates, sizeof(stack7Crates));
      }
      else if (stackId == 8)
      {
        memcpy(crates, stack8Crates, sizeof(stack8Crates));
      }
      else if (stackId == 9)
      {
        memcpy(crates, stack9Crates, sizeof(stack9Crates));
      }

      for (auto c : crates)
      {
        if (c != '\0')
        {
          stack.push(c);
        }
      }
      memset(crates, '\0', sizeof(crates));
      stackId++;
    }
  }
}
