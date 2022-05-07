#pragma once
/**
 * @file TwoTerminal.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief inheritance class from Device that contain all devices with TWo terminal 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Device.h"
/**
 * @brief inheritance class from Device that contain all devices with TWo terminal 
 * 
 */
class TwoTerminal :
    public Device
{
public:
/**
 * @brief Construct a new Three Terminal object
 * 
 * @param id the type of that object passed to higher class
 * @param netList the list of connected componentto this device
 * @param defalutval default valude from this device
 * @param max max valude from this device
 * @param min min valude from this device
 */
    TwoTerminal(string id, map<string, string> netList, float defalutval, float max, float min);
    /**
     * @brief get the first connected device  
     * 
     * @return string id of this connected device
     */
    string getT1();
    /**
     * @brief get the Second connected device
     * 
     * @return string 
     */
    string getT2();
    /**
     * @brief set the first connected device
     * 
     * @param t1 
     */
    void setT1(string t1);
    /**
     * @brief set the Second connected device
     * 
     * @param t2 
     */
    void setT2(string t2);
};

