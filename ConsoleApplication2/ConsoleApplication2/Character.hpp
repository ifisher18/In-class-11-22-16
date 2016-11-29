//
//  Character.hpp
//  CS172
//
//  Created by Stephen Johnson on 11/22/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "MazeItem.hpp"

class Character : public MazeItem
{
public:
    virtual void render();
};

#endif /* Character_hpp */
