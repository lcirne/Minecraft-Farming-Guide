//
// Created by luke cirne on 10/3/24.
//

#include "MinecraftFarmingGuide.h"
#include <iostream>
#include "Farm.h"
#include <cmath>

MinecraftFarmingGuide::MinecraftFarmingGuide(int pCropNumber, int pFarmSize) : farm(pCropNumber, pFarmSize) {}

//get farm
Farm MinecraftFarmingGuide::getFarm() const {
    return farm;
}

//print current farm information
void MinecraftFarmingGuide::printCurrentFarm() const {
    cout << "We are currently building a " << farm.getCrop().getCropName() << " farm that is " << farm.getFarmSize() << " blocks in size." << endl;
}

//generate instructions for farming guide
void MinecraftFarmingGuide::generateInstructions() const {

    int length_width = sqrt(farm.getFarmSize());
    int remainder =  farm.getFarmSize() - pow(length_width, 2);
    vector<string> inventory;

    cout << "\n1. To generate a " << farm.getCrop().getCropName() << " farm we'll need to clear an area first. "
                                                                "You can start by obtaining the necessary materials:" << endl;
    inventory = farm.getNecessaryInventory();
    for (int i = 0; i < inventory.size(); i += 2) {
        cout << inventory[i] << ": " << inventory[i+1] << endl;
    }
    //for sugar cane
    if (farm.getCrop().getOnWater()) {
        cout << "\n2. Once you've got everything, find a large body of water to build your farm on. On the bank of the water body, "
                "create a horizontal line of dirt by digging out blocks or placing extra blocks so that each block in the horizontal line "
                "has water touching one side of it (besides the blocks on either end that will have two sides touching water)." << endl;
        cout << "The line of blocks should be " << to_string(length_width * 2) << " blocks long. After that, use the rest of your "
                                                                                  "dirt blocks to build columns that extend vertically from "
                                                                                  "the horizontal base, and two water columns in between them. "
                                                                                  "These columns should be " << to_string(length_width) <<
                                                                                  " blocks in length. ";
        if (remainder > 0) {
            cout << "You can use the remaining blocks by creating another shorter column or adding onto existing columns." << endl;
        } else {
            cout << endl;
        }
        cout << "\n3. Your farm is nearly complete! just plant your seeds and watch them grow!\n" << endl;

    } else {
        cout << "\n2. Once you've got everything, find a nice place to build your farm and flatten it out. It should be at least "
                << to_string(length_width) << " by " << to_string(length_width) << " blocks in size. ";
        //check if there are remaining blocks
        if (remainder > 0) {
            cout << "You can place the remaining " << to_string(remainder) << " blocks adjacent to the main farm area wherever you like. " << endl;
        } else {
            cout << "\n";
        }
        if (farm.getCrop().getNeedsSun()) {
            cout << "Make sure that your area is above ground with access to sunlight or your crop won't grow!" << endl;
        }
        cout << "\n3. Now that your area is clear, you can go back and make sure each block in your farm area is dirt, "
                "replace any blocks that aren't with the dirt in your inventory. "
                "Your " << farm.getCrop().getCropName() << " seeds will need to be somewhat close to water in order to grow, so in your farming area dig holes "
                "that are 1 block deep such that every planting block on your farm is within a range of 4 blocks to a water block." << endl;
        cout
                << "\n4. We're almost finished up! The only thing left to do is find a source of water to fill in the water blocks on your farm. "
                   "Take your bucket and find the nearest water source! "
                   "If the source is close enough, you can just run back and forth, filling in each water block. If the source is particularly far "
                   "you can build an infinite water source by digging a 1 by 2 hole near your farm and filling both blocks with water from a bucket. "
                   "This will allow you to infinitely refill your bucket. " << endl;
        if (farm.getCrop().getNeedsExtraSpace()) {
            cout << "\n5. After filling in all of the water blocks on your farm, use your hoe to till each planting block and "
                    "plant each of your seeds so that there is at least one open block adjacent to each stem. " << endl;
        } else {
            cout << "\n5. After filling in all of the water blocks on your farm, "
                    "use your hoe to till each planting block and place a seed in each one." << endl;
        }
        cout << "Congratulations! your farm is complete!\n" << endl;
    }

}