//
// Created by Hunter Harloff on 8/20/17.
//

#include "actionHandler.h"

void actionHandler::handleEvent(sf::Event &event, render &rend) {
    //handle closing window
    if (event.type == sf::Event::Closed) {
        rend.window->close();
    }

    //handle all key events
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {

        }
    }


}
