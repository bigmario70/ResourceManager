//
// Created by mario on 21/06/23.
//

#include <iostream>
#include "LinesLoader.h"
#include <fstream>
#include <string>


void LinesLoader::notify() {
    for (auto observer : observers)
        observer->update();
}

void LinesLoader::subscribe(Observer* o) {
    observers.push_back(o);
}

void LinesLoader::unsubscribe(Observer* o) {
    observers.remove(o);
}

void LinesLoader::loadLines(){
    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    if (infile.is_open()){
        infile.seekg (0, infile.end);
        int length = infile.tellg();
        infile.seekg (0, infile.beg);
        char line[101];
        progress =0;
        while (!infile.eof()){
            infile.getline(line,100);
            lines.push_back(std::string(line));
            std::string templine;
            if (infile.fail()&&!infile.bad())
                std::getline(infile,templine);

            progress=static_cast<int> (infile.tellg()*100/length);
            if (progress== -1){
                progress=100;
                infile.close();
            }
            notify();
        }
    }else{
        std::cout << "failed to open " << filename << '\n';
    }
}

int LinesLoader::getProgress() const{
    return progress;
}

void LinesLoader::print() const{
    for (auto line: lines)
        std::cout << line << std::endl;
}