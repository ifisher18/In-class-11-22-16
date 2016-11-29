//
//  Maze.hpp
//  MazeGrame
//
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <string>
#include "MazeItem.hpp"

using namespace std;

class Maze {
private:
    
    //Two dimensional array of MazeItems
    MazeItem*** maze;
    int mazeWidth;
    int mazeHeight;
    
    int char_x;
    int char_y;
    
    MazeItem* constructItemForChar(char c);
    
public:
    
    Maze(string* initialMaze, int numLines);
    ~Maze();
    
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    
    void render();
    
    void updateMovableItemPositions();
};

#endif /* Maze_hpp */
