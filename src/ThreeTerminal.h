#pragma once
/**
 * @file ThreeTerminal.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief inheritance class from Device that contain all devices with three terminal 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Device.h"
/**
 * @brief inheritance class from Device that contain all devices with three terminal 
 * 
 */
class ThreeTerminal :
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
    ThreeTerminal(string id, map<string, string> netList, float defalutval, float max, float min);
    /**
     * @brief Get src of the three terminal Device 
     * 
     * @return string 
     */
    string getSrc();
    /**
     * @brief Get the Drain of the three terminal Device
     * 
     * @return string 
     */
    string getDrain();
    /**
     * @brief Get the Gate of the three terminal Device 
     * 
     * @return string 
     */
    string getGate();
    /**
     * @brief Set the Src of the three terminal Device
     * 
     * @param src 
     */
    void setSrc(string src);
    /**
     * @brief Set the Gate of the three terminal Device
     * 
     * @param gate 
     */
    void setGate(string gate);
    /**
     * @brief Set the Drain of the three terminal Device
     * 
     * @param drain 
     */
    void setDrain(string drain);

    ~ThreeTerminal();
    
};

