//
// Created by Hunter Harloff on 8/25/17.
//

#include <SFML/Graphics.hpp>
#include "actionHandler.h"

#ifndef SFMLPROJECT_APPLICATION_H
#define SFMLPROJECT_APPLICATION_H

class application {
public:
    application();
private:
    void loop();
    actionHandler aH;
};


#endif //SFMLPROJECT_APPLICATION_H
