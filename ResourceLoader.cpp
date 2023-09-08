//
// Created by mario on 21/06/23.
//

#include <iostream>
#include "ResourceLoader.h"
#include <fstream>
#include <string>



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
        position=resourcesFile.tellg();
        if(position==-1)
            progress=100;
        else
            progress = static_cast<int> (position * 100 / length);
        notify();
    }

    resourcesFile.close();

    /*}
    catch(const std::exception& e){
        fault=true;
        progress=0;
        notify();
        lines.clear();
        //throw FailedToLoadResources(completeFileName);
    }*/
}
/*
void ResourceLoader::saveLines(const std::string& fn){
    completeFileName=fn;
    const int maxChar = 100;
    fault=false;
    std::ofstream resourcesFile;
    try{
        resourcesFile.open(completeFileName, std::ifstream::out);
    }
    catch(const std::exception& e){
        fault=true;
        throw FailedToOpenFile(completeFileName);
    }
    if (!resourcesFile.is_open()){
        fault=true;
        throw FailedToOpenFile(completeFileName);;
    }
    try{
        //Leggo la lunghezza della lista

        long int length = lines.size();

        progress=0;
        int i=0;
        for (auto line :lines) {
            resourcesFile<<line<<std::endl;
            i++;
            progress = static_cast<int> ( i * 100 / length);

            notify();
        }
        progress=100;
        resourcesFile.close();
        notify();
    }
    catch(const std::exception& e){
        fault=true;
        notify();
        progress=0;
        throw FailedToLoadResources(completeFileName);
    }
}
*/