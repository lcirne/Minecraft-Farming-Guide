# M3OEP-lcirne

Luke Cirne
Module 3
Open Ended Project

Note: program requires R to run, as well as the following packages:
dplyr, ggplot2, tidyr, ggrepel, pacman

My program creates a guide for Minecraft players to create crop farms. These directions include any necessary conditions such as proximity to water, any necessary blocks for building the farm, as well as any tools needed and how to build it.
The program asks the user to choose which type of crop they'd like to grow and how big the farm should be using blocks as a unit. It then gives users the option to save their farm, and if they choose to do so it collects a farm name and .csv file 
to save the info to. The program writes the farm info to a .csv file and then uses the command line to compile and execute an R script which graphs the yield for the farm over a 10 day period. I plan on expanding on this proejct in the future by 
creating a graphic of what the user's farm would look like.

A list of concepts used so far:
Multiple classes, 
Separate header and cpp files, 
Enumerated types, 
Input validation, 
has-a relationships, 
structs, 
Must be ran from command line, 
Multiple languages, 
Passing arguments between languages using cli

Rubric:<br>
Main Program Complexity: Great (40) Expansive main program that requires significant user interaction and execute complex functions

Use of Multiple Languages: Great (20) Work done in R makes sense, proportionally much less R code than c++ however the data manipulation is significantly complex.

Choice of Languages: Great (20) R is a very logical choice for manipulating and graphing as it has a huge number of built-in packages for manipulating and plotting data (and I'm more comfortable using R than Python).

Command Line Arguments or File IO: Good-Great (15) Main program both writes to a csv and passes the name of that csv using the command line when executing the R script to make finding and manipulating the data easy. -5 points as it is not a relatively large amount of data that gets passed between languages, I used R to expand the data that gets extracted from the csv file.

Style and Documentation: Default (0) Meets all specifications.

Video: Default (0) Meets all specifications.

Lifespan of Project: Default (0) Repository commits span 7 days and significant
contributions are made on more than 3 separate days.