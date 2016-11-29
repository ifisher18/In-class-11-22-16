//
//  Maze.cpp
//  MazeGrame
//
//  Created by Stephen Johnson on 11/28/16.
//  Copyright © 2016 Glacier Peak Studios LLC. All rights reserved.
//

#include <iostream>
#include <string>
#include "Maze.hpp"
#include "MazeItem.hpp"
#include "Character.hpp"
#include "MazeWall.hpp"

Maze::Maze(string* initialMaze, int numLines)
{
    this->mazeHeight = numLines;
    this->mazeWidth = (int)initialMaze[0].length();
    this->maze = new MazeItem**[numLines];
    
    for (int i = 0; i < this->mazeHeight; i++)
    {
        this->maze[i] = new MazeItem*[this->mazeWidth];
        for (int j = 0; j < this->mazeWidth; j++)
        {
            maze[i][j] = NULL;
        }
    }
    
    this->char_x = 0;
    this->char_y = 0;
    for (int i = 0; i < this->mazeHeight; i++)
    {
        string line = initialMaze[i];
        for (int j = 0; j < line.length(); j++)
        {
            char c = line.at(j);
            
            //Constructo the object for this location
            maze[i][j] = constructItemForChar(c);
            
            //Check if this is the character and if
            //it is then we need to track its position
            if (maze[i][j] != NULL && typeid(*(maze[i][j])) == typeid(Character))
            {
                this->char_x = j;
                this->char_y = i;
            }
        }
    }
    
}

Maze::~Maze()
{
    //Delete the memory
    for (int i = 0; i < this->mazeHeight; i++)
    {
        for (int j = 0; j < this->mazeWidth; j++)
        {
            if (maze[i][j] != NULL)
            {
                delete maze[i][j];
            }
        }
        delete[] maze[i];
    }
    delete[] maze;

}

MazeItem* Maze::constructItemForChar(char c)
{
    if (c == '-')
    {
        return new MazeWall(true);
    }
    else if (c == '|')
    {
        return new MazeWall(false);
    }
    else if (c == '*')
    {
        return new Character();
    }
    
    return NULL;
    
}

void Maze::moveLeft()
{
	if (char_x > 0 && (maze[char_y][char_x-1] == 0 || maze[char_y][char_x-1]->throughWalls()))
    {
        MazeItem* character = maze[char_y][char_x];
        maze[char_y][char_x] = NULL;
        char_x--;
        maze[char_y][char_x] = character;
    }
    
}

void Maze::moveRight()
{
    if (char_x < this->mazeWidth - 1 && (maze[char_y][char_x + 1] == 0 || maze[char_y][char_x + 1]->throughWalls()))
    {
        MazeItem* character = maze[char_y][char_x];
        maze[char_y][char_x] = NULL;
        char_x++;
        maze[char_y][char_x] = character;
    }

    
}

void Maze::moveUp()
{
    if (char_y > 0)
    {
        MazeItem* character = maze[char_y][char_x];
        maze[char_y][char_x] = NULL;
        char_y--;
        maze[char_y][char_x] = character;
    }
}

void Maze::moveDown()
{
    if (char_y < this->mazeHeight - 1)
    {
        MazeItem* character = maze[char_y][char_x];
        maze[char_y][char_x] = NULL;
        char_y++;
        maze[char_y][char_x] = character;
    }
    
}

void Maze::updateMovableItemPositions()
{
    for (int i = 0; i < this->mazeHeight; i++)
    {
        for (int j = 0; j < this->mazeWidth; j++)
        {
            //Check if maze[i][j] can move
            //if it can move, then randomly move up, down, left, or right
            //and only do it, if that is a valid location.
        }
    }
}

void Maze::render()
{
    for (int i = 0; i < this->mazeHeight; i++)
    {
        for (int j = 0; j < this->mazeWidth; j++)
        {
            if (maze[i][j] != NULL)
            {
                maze[i][j]->render();
            }
            else
            {
                cout << " ";
            }
        }
        
        cout << endl;
    }

}
