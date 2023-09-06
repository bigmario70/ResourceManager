//
// Created by mario on 21/06/23.
//

#include <iostream>
#include "ResourceLoader.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include "MyExceptions.h"


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

const std::vector<std::string>& ResourceLoader::getLines() const{
    return lines;
}

void ResourceLoader::setLines(const std::vector<std::string> & l){
    lines = l;
}

bool ResourceLoader::isFault() const {
    return fault;
}

const std::string & ResourceLoader::getFilename() const {
    return fileName;
}

void ResourceLoader::loadLines(const std::string& fn){
    fileName=fn;
    const int maxChar = 100;
    fault=false;
    std::ifstream resourcesFile;
    try{
        resourcesFile.open(fileName, std::ifstream::in);
    }
    catch(const std::exception& e){
            fault=true;
            throw FailedToOpenFile(fileName);
    }
    if (!resourcesFile.is_open()){
        fault=true;
        throw FailedToOpenFile(fileName);;
    }
    try{
        //Leggo la lunghezza del file
        resourcesFile.seekg (0, std::ifstream::end);
        long int length = resourcesFile.tellg();

        resourcesFile.seekg (0, std::ifstream::beg);
        char line[maxChar];
        progress=0;

        while (!resourcesFile.eof()){
            resourcesFile.getline(line, maxChar);
            lines.emplace_back(line);
            if(resourcesFile.tellg() ==-1)
                progress=100;
            else
                progress = static_cast<int> (resourcesFile.tellg() * 100 / length);
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
        lines.clear();
        throw FailedToLoadResources(fileName);
    }
}
void ResourceLoader::saveLines(const std::string& fn){
    fileName=fn;
    const int maxChar = 100;
    fault=false;
    std::ofstream resourcesFile;
    try{
        resourcesFile.open(fileName, std::ifstream::out);
    }
    catch(const std::exception& e){
        fault=true;
        throw FailedToOpenFile(fileName);
    }
    if (!resourcesFile.is_open()){
        fault=true;
        throw FailedToOpenFile(fileName);;
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
        throw FailedToLoadResources(fileName);
    }
}



