//
// Created by luke cirne on 10/3/24.
//

#ifndef FARM_H
#define FARM_H
#include "Crop.h"
#include <vector>
#include "Material.h"
using namespace std;

enum cropFarm {
    WHEAT_FARM = 1,
    POTATO_FARM,
    SUGAR_CANE_FARM,
    PUMPKIN_FARM,
    MELON_FARM
};

class Farm {
protected:
    Crop crop;
    int numberOfDifferentMaterials;
    int farmSize;
    vector<Material> necessaryInventory;
    int farmNumber; //corresponds to cropNumber
    int yield;

public:
    //constructor
    Farm(int pCropNumber, int pFarmSize);
    //getters
    Crop getCrop() const;
    int getNumberOfDifferentMaterials() const;
    int getFarmSize() const;
    int getFarmNumber() const;
    vector<string> getNecessaryInventory() const;
    //setters
    int getYield() const;
    void setCrop(int pCrop);
    void setFarmSize(int pFarmSize);
};



#endif //FARM_H
