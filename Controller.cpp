//
// Created by mario on 07/09/23.
//

#include "Controller.h"
#include "ResourceLoader.h"
#include "ProgressBar.h"

int Controller::loadFromFile(const std::string & compFileName){
    std::list<std::string> resList;
    ResourceLoader myLoader(compFileName);
    ProgressBar myPB(&myLoader);
    myLoader.loadResources();
    if(myLoader.isFault())
        return -1;
    else{
        model->setResList(myLoader.getLines());
        return 0;
    }
}

int Controller::saveToFile(const std::string & compFileName){
    return 0;
}