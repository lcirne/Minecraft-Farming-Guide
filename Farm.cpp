//
// Created by luke cirne on 10/3/24.
//

#include "Farm.h"

Farm::Farm(int pCropNumber, int pFarmSize) : crop(pCropNumber) {
    farmNumber = pCropNumber;
    farmSize = pFarmSize;
    Material dirt;
    dirt.name = "dirt";
    Material seed;
    seed.name = "seed";
    Material hoe;
    hoe.name = "hoe";
    Material bucket;
    bucket.name = "bucket";
    Material shovel;
    shovel.name = "shovel";

    switch (pCropNumber) {
        case WHEAT_FARM:
            numberOfDifferentMaterials = 4;
        yield = pFarmSize;
        dirt.quantity = farmSize;
        dirt.required = true;
        seed.quantity = farmSize;
        seed.required = true;
        hoe.quantity = 1;
        hoe.required = true;
        bucket.quantity = 1;
        bucket.required = true;
        //populate necessaryInventory vector
        necessaryInventory.push_back(dirt);
        necessaryInventory.push_back(seed);
        necessaryInventory.push_back(hoe);
        necessaryInventory.push_back(bucket);
        break;
        case POTATO_FARM:
            numberOfDifferentMaterials = 4;
        yield = pFarmSize;
        dirt.quantity = farmSize;
        dirt.required = true;
        seed.quantity = farmSize;
        seed.required = true;
        hoe.quantity = 1;
        hoe.required = true;
        bucket.quantity = 1;
        bucket.required = true;
        //populate necessaryInventory vector
        necessaryInventory.push_back(dirt);
        necessaryInventory.push_back(seed);
        necessaryInventory.push_back(hoe);
        necessaryInventory.push_back(bucket);
        break;
        case SUGAR_CANE_FARM:
            numberOfDifferentMaterials = 3;
        yield = pFarmSize;
        dirt.quantity = farmSize;
        dirt.required = true;
        seed.quantity = farmSize;
        seed.required = true;
        shovel.quantity = 1;
        shovel.required = false;
        //populate necessaryInventory vector
        necessaryInventory.push_back(dirt);
        necessaryInventory.push_back(seed);
        necessaryInventory.push_back(shovel);
        break;
        case PUMPKIN_FARM:
            numberOfDifferentMaterials = 5;
        yield = (pFarmSize / 2) + (pFarmSize % 2);
        dirt.quantity = farmSize / 2;
        dirt.required = true;
        seed.quantity = farmSize / 2;
        seed.required = true;
        hoe.quantity = 1;
        hoe.required = true;
        bucket.quantity = 1;
        bucket.required = true;
        shovel.quantity = 1;
        shovel.required = false;
        //populate necessaryInventory vector
        necessaryInventory.push_back(dirt);
        necessaryInventory.push_back(seed);
        necessaryInventory.push_back(hoe);
        necessaryInventory.push_back(bucket);
        necessaryInventory.push_back(shovel);
        break;
        case MELON_FARM:
            numberOfDifferentMaterials = 5;
        yield = (pFarmSize / 2) + (pFarmSize % 2);
        dirt.quantity = farmSize / 2;
        dirt.required = true;
        seed.quantity = farmSize / 2;
        seed.required = true;
        hoe.quantity = 1;
        hoe.required = true;
        bucket.quantity = 1;
        bucket.required = true;
        shovel.quantity = 1;
        shovel.required = false;
        //populate necessaryInventory vector
        necessaryInventory.push_back(dirt);
        necessaryInventory.push_back(seed);
        necessaryInventory.push_back(hoe);
        necessaryInventory.push_back(bucket);
        necessaryInventory.push_back(shovel);
        break;
        default:
            numberOfDifferentMaterials = 0;
        break;
    }
}

// Getters
Crop Farm::getCrop() const {
    return crop;
}

int Farm::getNumberOfDifferentMaterials() const {
    return numberOfDifferentMaterials;
}

int Farm::getFarmSize() const {
    return farmSize;
}

int Farm::getFarmNumber() const {
    return farmNumber;
}

vector<string> Farm::getNecessaryInventory() const {
    vector<string> inventory;
    for (const Material &material : necessaryInventory) {
        inventory.push_back(material.name);
        inventory.push_back(to_string(material.quantity));
    }
    return inventory;
}

int Farm::getYield() const {
    return yield;
}

// Setter for crop
void Farm::setCrop(int pCrop) {
    crop.setCropType(pCrop);
}

// Setter for farm size
void Farm::setFarmSize(int pFarmSize) {
    farmSize = pFarmSize;
}
