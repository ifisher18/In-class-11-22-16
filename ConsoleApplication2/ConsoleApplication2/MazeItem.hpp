//
//  MazeItem.hpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef MazeItem_hpp
#define MazeItem_hpp

#include <stdio.h>

class MazeItem {
public:
    virtual void render();
	// add virtual function to the base class MazeItem
	virtual bool throughWalls();
};


#endif /* MazeItem_hpp */
