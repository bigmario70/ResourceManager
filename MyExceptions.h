//
// Created by mario on 05/09/23.
//

#ifndef RESOURCELOADER_MYEXCEPTIONS_H
#define RESOURCELOADER_MYEXCEPTIONS_H
#include <stdexcept>
class FailedToOpenFile : public std::runtime_error {
public:
    explicit FailedToOpenFile(const std::string& fName): std::runtime_error(std::string("Failed to open file: ") + fName){}
};
class FailedToLoadResources : public std::runtime_error {
public:
    explicit FailedToLoadResources (const std::string& fName): std::runtime_error(std::string("Failed to open file: ") + fName){}
};


#endif //RESOURCELOADER_MYEXCEPTIONS_H
