//
// Created by mario on 21/06/23.
//

#ifndef LINESLOADER_LINESLOADER_H
#define LINESLOADER_LINESLOADER_H


#include <list>
#include <string>
#include "Subject.h"
#include <vector>

class LinesLoader : public Subject {
public:
    LinesLoader(const std::string& fn):filename(fn){}
    virtual ~LinesLoader () {}
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


#endif //LINESLOADER_LINESLOADER_H
