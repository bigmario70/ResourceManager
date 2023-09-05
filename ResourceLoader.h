//
// Created by mario on 21/06/23.
//

#ifndef LINESLOADER_RESOURCELOADER_H
#define LINESLOADER_RESOURCELOADER_H


#include <list>
#include <string>
#include "Subject.h"
#include <vector>

class ResourceLoader : public Subject {
public:
    ResourceLoader(const std::string& fn): fileName(fn), progress(0), fault(false){}
    virtual ~ResourceLoader () {}
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    void loadLines();

    int getProgress() const;
    const std::vector<std::string>& getLines() const;
    const std::string &getFilename() const;
    bool isFault() const;

private:
    int progress;
    bool fault;
    std::string fileName;
    std::vector<std::string> lines;
    std::list<Observer *> observers;
};


#endif //LINESLOADER_RESOURCELOADER_H
