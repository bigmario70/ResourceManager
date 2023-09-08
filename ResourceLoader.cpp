//
// Created by mario on 21/06/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ResourceLoader.h"



void ResourceLoader::notify() {
    for (auto observer : observers)
        observer->update();
}

void ResourceLoader::subscribe(Observer* o) {
    observers.push_back(o);
}

void ResourceLoader::unsubscribe(Observer* o) {
    observers.remove(o);
}

int ResourceLoader::getProgress() const{
    return progress;
}

const std::list<std::string>& ResourceLoader::getLines() const{
    return lines;
}

bool ResourceLoader::isFault() const {
    return fault;
}

const std::string & ResourceLoader::getFilename() const {
    return completeFileName;
}

void ResourceLoader::loadResources(){

    const int maxChar = 100;
    progress=0;
    fault=false;
    lines.clear();
    std::ifstream resourcesFile;
    resourcesFile.open(completeFileName, std::ifstream::in);
    if (!resourcesFile.is_open()){
        fault=true;
        return;
    }

    //Read file length
    resourcesFile.seekg (0, std::ifstream::end);
    long int length = resourcesFile.tellg();

    //Read file one line at a time
    resourcesFile.seekg (0, std::ifstream::beg);
    char line[maxChar];
    long int position;
    while (!resourcesFile.eof()){
        resourcesFile.getline(line, maxChar);
        lines.emplace_back(line);
        if(resourcesFile.tellg() ==-1)
            progress=100;
        else
            progress = static_cast<int> (resourcesFile.tellg() * 100 / length);
        notify();
    }
    resourcesFile.close();

}