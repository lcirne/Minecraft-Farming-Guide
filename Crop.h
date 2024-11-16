//
// Created by luke cirne on 10/3/24.
//

#ifndef CROP_H
#define CROP_H
#include<string>

using namespace std;

enum cropType {
    WHEAT = 1,
    POTATO,
    SUGAR_CANE,
    PUMPKIN,
    MELON
};

class Crop {
protected:
    string cropName;
    bool needsSun;
    bool onWater;
    bool needsExtraSpace;

public:
    //constructor
    Crop(int pCropNumber);
    //getters
    string getCropName() const;
    bool getNeedsSun() const;
    bool getOnWater() const;
    bool getNeedsExtraSpace() const;
    //setters
    void setCropType(int pCropNumber);
};



#endif //CROP_H
