//
// Created by luke cirne on 10/3/24.
//
#include "MinecraftFarmingGuide.h"
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

//validate integer input
int getIntFromUser();
//print the values for the enumerated crop types
void printCropTypes();
//save the crop number, crop name, farm size, yield, and farm name to a csv file
bool saveFarmData(MinecraftFarmingGuide pFarmingGuide, string pFarmName);


int main() {

    int cropType;
    int farmSize;
    bool validInput = false;

    //welcome statement and obtains user input
    cout << "Welcome to the Minecraft Farming Guide! What would you like to build today?" << endl;
    printCropTypes();
    //input validations
    while (!validInput) {
        cropType = getIntFromUser();
        if (cropType > 0 && cropType < 6) {
            validInput = true;
        } else {
            cout << "Integer is not within the valid range. ";
        }
    }
    cout << "How big would you like your farm to be? Enter an integer representing the number of blocks it should take up: ";
    validInput = false;
    while (!validInput) {
        farmSize = getIntFromUser();
        if (farmSize > 0) {
            validInput = true;
        } else {
            cout << "Integer is not within the valid range. ";
        }
    }
    MinecraftFarmingGuide farmingGuide(cropType, farmSize);
    cout << "\nAwesome! ";
    //recap the given info
    farmingGuide.printCurrentFarm();
    //print instructions to the farm
    farmingGuide.generateInstructions();

    //string to decide if input should be saved
    string save;
    //validate save input
    bool validSaveInput = false;
    while (!validSaveInput) {
        cout << "Would you like to save this farm for analysis? Enter YES or NO: ";
        getline(cin, save);

        if (save == "YES") {
            string farmName = "-1";
            cout << "Saving data now! What would you like your farm to be called? ";
            getline(cin, farmName);

            if (farmName != "-1") {
                saveFarmData(farmingGuide, farmName);
            }
            validSaveInput = true;

        } else if (save == "NO") {
            cout << ":(((, your farm will disappear into the void when you're done." << endl;
            validSaveInput = true;

        } else {
            cout << "I didn't like that answer try again. ";
        }
    }

    return 0;
}


//receive and validate integer user input
int getIntFromUser() {
    int input;
    stringstream ss;
    string placeholder;
    while (true) {
        cout << "Enter a number: ";
        getline(cin, placeholder);
        if (placeholder.empty()) {
            cout << "No input. ";
        } else if (ss << placeholder && ss >> input && ss.eof()) {
            return input;
        } else {
            cout << "Invalid input. ";
            ss.str("");
            ss.clear();
        }
    }
}

//print crop options and their corresponding numbers for selection
void printCropTypes() {
    cout << "Wheat: 1" << endl
         << "Potato: 2" << endl
         << "Sugar Cane: 3" << endl
         << "Pumpkin: 4" << endl
         << "Melon: 5" << endl;
}


//save farm data to a csv file and graph yield over time
bool saveFarmData(MinecraftFarmingGuide pFarmingGuide, string pFarmName) {
    //vector to hold the file header if file is new
    vector<string> header;
    header.push_back("farm_number");
    header.push_back("crop_name");
    header.push_back("farm_size");
    header.push_back("yield");
    header.push_back("farm_name");
    //vector to hold farm info that is to be saved to the given file
    vector<string> infoToSave;
    infoToSave.push_back(to_string(pFarmingGuide.getFarm().getFarmNumber()));
    infoToSave.push_back(pFarmingGuide.getFarm().getCrop().getCropName());
    infoToSave.push_back(to_string(pFarmingGuide.getFarm().getFarmSize()));
    infoToSave.push_back(to_string(pFarmingGuide.getFarm().getYield()));
    infoToSave.push_back(pFarmName);

    //receiving and validating filename
    string filename;
    ofstream outfile;
    ifstream infile;
    bool validated = false;

    //validate filename extension
    while (!validated) {
        cout << "What would you like your filename to be called? Please include .csv at the end: ";
        getline(cin, filename);
        if (filename.size() >= 4 && filename.compare(filename.size() - 4, 4, ".csv") == 0) {
            infile.open(filename);
            validated = true;
        } else {
            cout << "Invalid filename, try again. ";
        }
    }

    //check if file is empty
    //add header if so
    if (infile.peek() == ifstream::traits_type::eof()) {
        infile.close();
        outfile.open(filename, ios::app);
        for (int i = 0; i < header.size(); i++) {
            //check if final element of header vector has been reached
            //if not, insert a comma to seperate columns
            //if so, insert newline
            if (i < header.size() - 1) {
                outfile << header[i] << ",";
            } else {
                outfile << header[i] << "\n";
            }
        }
    } else {
        infile.close();
        outfile.open(filename, ios::app);
    }


    for (int i = 0; i < infoToSave.size(); i++) {
        if (i < infoToSave.size() - 1) {
            outfile << infoToSave[i] << ",";
        } else {
            outfile << infoToSave[i] << "\n";
        }
    }
    outfile.close();

    //Create DataEngine.R executable
    system("chmod +x DataEngine.R");
    //Run script
    string command = "Rscript DataEngine.R " + filename;
    system(command.c_str());

    cout << "File has been saved!" << endl;
    return true;
}