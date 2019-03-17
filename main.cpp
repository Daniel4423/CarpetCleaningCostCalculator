/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Dan
 *
 * Created on March 17, 2019, 5:39 AM
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*Simple program demonstrates utilizing multiple functions.
 *Asks user for dimensions of room to be cleaned, then calculates area
 *and carpet cleaning cost based on flat fee of $99 for 10x12 + .25/sqft above
 * 120sqft.
 * The program does use type double for dollars and cents, which is not typically
 * recommended, but it's only working with increments of 25 cents and the point 
 * is really only to demo function use, so I went with it anyway.
 * 
 */

int GetArea();
double CleaningCost(int area);
   
  
int main(int argc, char** argv) {
    int roomArea;
    char endProgram;
    bool quit = false;
    
    while (quit != true) {
        roomArea = GetArea();
        cout << "Your total carpet cleaning cost for a " << roomArea << 
            " sq ft room is $" <<fixed << setprecision(2) << CleaningCost(roomArea) << endl;
        cout << "Enter q to quit. Press any other key to run again" << endl;
        cin >> endProgram;
        if (endProgram == 'q') {
            quit = true;
        }
    }
    
    return 0;
}

int GetArea() {
    double roomLength;
    double roomWidth;
    
    cout << "Enter the room length in feet" << endl;
    cin >> roomLength;
    cout << "Enter room width in feet" << endl;
    cin >> roomWidth;
    return static_cast<int> (ceil(roomLength * roomWidth));
}

double CleaningCost(int area) {
    int flatCostArea = 120;
    
    if (area > flatCostArea) {
        return 99.0 + (0.25 * (area - flatCostArea));
    } else {
        return 99.0;
    }
}