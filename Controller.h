//
// Created by mario on 07/09/23.
//

#ifndef RESOURCEMANAGER_CONTROLLER_H
#define RESOURCEMANAGER_CONTROLLER_H
#include "Model.h"


class Controller {
public:
    Controller(Model* m): model(m){}
    void loadFromFile(const std::string & filePath);
    void saveToFile(const std::string & filePath);
private:
    Model* model;
};


#endif //RESOURCEMANAGER_CONTROLLER_H
