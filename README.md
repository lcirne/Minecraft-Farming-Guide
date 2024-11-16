# Minecraft Farming Guide

### Luke Cirne

This creates a guide for Minecraft players to create crop farms. These directions include any necessary conditions such as proximity to water, any necessary blocks for building the farm, as well as any tools needed to build the farm.
The program asks the user to choose which type of crop they'd like to grow and how big the farm should be using blocks as a unit. It then gives users the option to save their farm, and if they choose to do so it collects a farm name and .csv file to save the info to. 
The program writes the farm info to a .csv file and then uses the command line to compile and execute an R script which takes command line arguments for the .csv file. 
The objective of this R script is to plot the yield of the user's farm over a 10 day period for both linear and exponential growth of the farm. It uses R packages to manipulate the data in the csv file into a graphable format and then through the ggplot package generates a single graph with each growth path.

## Languages used:
C++
  * Version 17+

R
  * Version 4.4.1+
  * Required packages:
    * pacman
    * tidyr
    * dplyr
    * gpplot2
    * ggrepel

## Running the Program
Program must be run through command line in the program directory:

Compile: ```g++ -std=c++17 Crop.cpp Farm.cpp MinecraftFarmingGuide.cpp Main.cpp```

Run: ```./a.out```


*All code authored by Luke Cirne*
