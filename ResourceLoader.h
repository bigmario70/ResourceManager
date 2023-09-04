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
    ResourceLoader(const std::string& fn): filename(fn){}
    virtual ~ResourceLoader () {}
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    int getProgress() const;

    const std::vector<std::string>& getLines() const;
    void loadLines();

private:
    int progress;
    std::string filename;
    std::vector<std::string> lines;
    std::list<Observer *> observers;
};


#endif //LINESLOADER_RESOURCELOADER_H
