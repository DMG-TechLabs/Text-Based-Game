#pragma once

#include <vector>
#include <string>

/**
 * @brief Mission class
 * 
 */
class Mission{
private:

public:
    //Class variables
    std::string description;
    bool completed;

    //Constructors
    Mission();
    Mission(std::string description, bool completed);
    ~Mission();
}; 