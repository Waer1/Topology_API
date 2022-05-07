#pragma once
/**
 * @file Pmos.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief Pmos is there Three terminal Device
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "ThreeTerminal.h"
/**
 * @brief Pmos is there Three terminal Device
 * 
 */
class Pmos :
    public ThreeTerminal
{
public:
/**
 * @brief Construct a new Pmos object
 * 
 * @param typ the type of that object passed to higher class
 * @param netList the list of connected componentto this device
 * @param def default valude from this device
 * @param max max valude from this device
 * @param min min valude from this device
 */
    Pmos(string typ, map<string, string> netList, float def, float max, float min);
/**
 * @brief print the specific device info 
 * 
 */
    virtual void Print_Device();
/**
 * @brief Destroy the Pmos object
 * 
 */
    ~Pmos();

};