//
// Created by Hunter Harloff on 8/20/17.
//

#ifndef SFMLPROJECT_RENDER_H
#define SFMLPROJECT_RENDER_H


#include <vector>
#include <SFML/Graphics.hpp>


 class render {
     //methods
 public:
     render(sf::RenderWindow&);
     void loop();
 private:
     //variables
 public:
     sf::RenderWindow *window;
     sf::RectangleShape *grid; //pointer variable to hold grid array

     //MODIFY THESE VARIABLES!
     int aliveC = 225; //color for alive cells
     int deadC = 25; //color for dead cells
     int s = 10; //variable to control size of cells
     int rate = 9; //rate at which cells are spawned at start
 };


#endif //SFMLPROJECT_RENDER_H
