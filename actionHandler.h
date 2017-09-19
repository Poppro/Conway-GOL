//
// Created by Hunter Harloff on 8/20/17.
//

#ifndef SFMLPROJECT_ACTIONHANDLER_H
#define SFMLPROJECT_ACTIONHANDLER_H
#include <SFML/Graphics.hpp>
#include "render.h"

class actionHandler {
public:
    void handleEvent(sf::Event&, render&);
private:
};


#endif //SFMLPROJECT_ACTIONHANDLER_H
