//
// Created by mario on 21/06/23.
//

#include <iostream>
#include "ResourceLoader.h"
#include <fstream>
#include <string>
#include <limits>


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

void ResourceLoader::loadLines(){
    // constexpr auto max_size = std::numeric_limits<std::streamsize>::max();
    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    if (infile.is_open()){
        infile.seekg (0, infile.end);
        int length = infile.tellg();
        infile.seekg (0, infile.beg);
        char line[100];
        progress =0;
        while (!infile.eof()){
            infile.getline(line,100);
            lines.push_back(std::string(line));
            //char dummyLine[101];
            if (infile.fail()&&!infile.bad()) {
                infile.clear();
                //infile.ignore(max_size, '\n');
                //infile.getline( dummyLine, 100);
            }

            progress=static_cast<int> (infile.tellg()*100/length);
            if (progress==0 ){
                progress=100;
                infile.close();
            }
            notify();
        }
    }else{
        std::cout << "failed to open " << filename << '\n';
    }
}

int ResourceLoader::getProgress() const{
    return progress;
}

const std::vector<std::string>& ResourceLoader::getLines() const{
    return lines;
}