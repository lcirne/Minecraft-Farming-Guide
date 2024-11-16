//
// Created by luke cirne on 10/3/24.
//

#ifndef MINECRAFTFARMINGGUIDE_H
#define MINECRAFTFARMINGGUIDE_H
#include <vector>
#include <string>
#include "Farm.h"

using namespace std;



class MinecraftFarmingGuide {

private:
    Farm farm;

public:
    MinecraftFarmingGuide(int pCropNumber, int pFarmSize);
    //get farm
    Farm getFarm() const;
    //print current farm information
    void printCurrentFarm() const;
    //generate instructions for farming guide
    void generateInstructions() const;
};



#endif //MINECRAFTFARMINGGUIDE_H
