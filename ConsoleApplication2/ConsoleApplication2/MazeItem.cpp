//
//  MazeItem.cpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include "MazeItem.hpp"
#include <iostream>
#include <string>

using namespace std;

void MazeItem::render()
{
    cout << " ";
}

bool MazeItem::throughWalls() {
	return true;
}
