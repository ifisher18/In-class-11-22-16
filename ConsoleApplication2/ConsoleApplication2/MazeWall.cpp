//
//  MazeWall.cpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "MazeWall.hpp"
#include <iostream>
#include <string>

using namespace std;

MazeWall::MazeWall(bool horz)
{
    mHorizontal = horz;
}

void MazeWall::render()
{
    if (mHorizontal)
    {
        cout << "-";
    }
    else
    {
        cout << "|";
    }
}

bool MazeWall::throughWalls() {
	return false;
}

