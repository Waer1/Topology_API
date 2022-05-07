#pragma once
/**
 * @file Resistance.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief Resistance is there Two terminal Device
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "TwoTerminal.h"
/**
 * @brief Resistance is there Two terminal Device
 * 
 */
class Resistance :
    public TwoTerminal
{
public:
/**
 * @brief Construct a new Resistance object
 * 
 * @param typ the type of that object passed to higher class
 * @param netList the list of connected componentto this device
 * @param def default valude from this device
 * @param max max valude from this device
 * @param min min valude from this device
 */
    Resistance(string id, map<string, string> netList, float def, float max, float min);
/**
 * @brief print the specific device info 
 * 
 */
    virtual void Print_Device();
/**
 * @brief Destroy the Resistance object
 * 
 */
    ~Resistance();

};

