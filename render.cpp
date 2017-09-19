//
// Created by Hunter Harloff on 8/20/17.
//

#include "render.h"
#include <iostream>

render::render(sf::RenderWindow &w) {
    window = &w;

    //make grid
    int cols = window->getSize().y/s;
    int rows = window->getSize().x/s;

    grid = new sf::RectangleShape[rows*cols]; //initialize grid array into pointer grid

    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            //proceeding code creates a rectangle object in using SFML to represent a cell
            sf::RectangleShape r;
            r.setPosition(x*s,y*s);
            r.setSize(sf::Vector2f(s,s));
            r.setFillColor(sf::Color(deadC, deadC, deadC));
            //randomly assign certain cells to be "alive" (1/modulus chance)
            if(rand()%rate == 1) {
                r.setFillColor(sf::Color(aliveC,aliveC,aliveC));
            }
            int i = y*cols+x;
            grid[i] = r; //store created rectangle in grid
        }
    }
}

void render::loop() {
    int rows = window->getSize().x/s;
    int cols = window->getSize().y/s;
    sf::RectangleShape tmpGrid[rows*cols]; //array to hold values of grid while new grid is being calculated

    //main embedded loop for game logic (die, survive, reproduce)
    for(int y = 0; y < cols; y++) {
        for(int x = 0; x < rows; x++) {
            int adj = 0;
            int cI = y*rows+x;
            tmpGrid[cI] = grid[cI]; //hold val

            //determine how many living cells are adjacent to the current
            //embedded for loop calculates top and bottom row, the following if statements calculate left and right
            for(int j = -1; j < 2; j+=2) {
                for (int i = -1; i < 2; i++) {
                    if (y > 0) {
                        if (grid[(y + j) * rows + (x + i)].getFillColor() == sf::Color(aliveC, aliveC, aliveC)) {
                            adj++;
                        }
                    }
                }
            }
            if(grid[y*rows+x-1].getFillColor() == sf::Color(aliveC,aliveC,aliveC)) {
                adj++;
            }

            if (grid[y * rows + x + 1].getFillColor() == sf::Color(aliveC, aliveC, aliveC)) {
                adj++;
            }

            //based on # of adjacent, make decision on cells updated state
            if(adj < 2 && grid[cI].getFillColor() == sf::Color(aliveC,aliveC,aliveC)) {
                tmpGrid[cI].setFillColor(sf::Color(deadC, deadC, deadC));
            } else if(adj == 3 && grid[cI].getFillColor() == sf::Color(deadC, deadC, deadC)) {
                tmpGrid[cI].setFillColor(sf::Color(aliveC,aliveC,aliveC));
            } else if(adj > 3 && grid[cI].getFillColor() == sf::Color(aliveC,aliveC,aliveC)) {
                tmpGrid[cI].setFillColor(sf::Color(deadC, deadC, deadC));
            }
        }
    }

    //update the grid to reflect newly calculated states and print grid to the screen
    for(int i = 0; i < sizeof(tmpGrid)/sizeof(tmpGrid[0]); i++) {
        grid[i] = tmpGrid[i];
        window->draw(grid[i]);
    }
}