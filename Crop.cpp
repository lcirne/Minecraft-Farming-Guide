//
// Created by luke cirne on 10/3/24.
//

#include "Crop.h"

Crop::Crop(int pCropNumber) {
    switch (pCropNumber) {
        case WHEAT:
            cropName = "wheat";
            needsSun = false;
            onWater = false;
            needsExtraSpace = false;
        break;
        case POTATO:
            cropName = "potato";
            needsSun = false;
            onWater = false;
            needsExtraSpace = false;
        break;
        case SUGAR_CANE:
            cropName = "sugar cane";
            needsSun = true;
            onWater = true;
            needsExtraSpace = false;
        break;
        case PUMPKIN:
            cropName = "pumpkin";
            needsSun = true;
            onWater = false;
            needsExtraSpace = true;
        break;
        case MELON:
            cropName = "melon";
            needsSun = true;
            onWater = false;
            needsExtraSpace = true;
        break;
        default: // Fallback for unexpected input
            cropName = "unknown crop";
            needsSun = false;
            onWater = false;
            needsExtraSpace = false;
        break;
    }

}

//getters
string Crop::getCropName() const {
    return cropName;
}
bool Crop::getNeedsSun() const {
    return needsSun;
}
bool Crop::getOnWater() const {
    return onWater;
}
bool Crop::getNeedsExtraSpace() const {
    return needsExtraSpace;
}

//setters
void Crop::setCropType(int pCropNumber) {
    switch (pCropNumber) {
        case WHEAT:
            cropName = "wheat";
        break;
        case POTATO:
            cropName = "potato";
        break;
        case SUGAR_CANE:
            cropName = "sugar cane";
        break;
        case PUMPKIN:
            cropName = "pumpkin";
        break;
        case MELON:
            cropName = "melon";
        break;
        default:
            cropName = "unknown crop"; // Fallback for unexpected input
        break;
    }
}