//
// Created by Hunter Harloff on 8/25/17.
//

#include "application.h"

application::application() {
    application::loop();
}

void application::loop() {
    //setup the window
    sf::RenderWindow window(sf::VideoMode(1200, 1200, 32), "Test Environment");
    render rnd(window);
    window.setFramerateLimit(3); //framerate for program
    //window loop
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event)) {
            aH.handleEvent(event, rnd);
        }
        rnd.loop(); //render loop
        window.display();
    }
}