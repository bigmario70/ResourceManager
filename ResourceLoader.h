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
    ResourceLoader(): fileName(""), progress(0), fault(false){}
    virtual ~ResourceLoader () {}
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    void loadLines(const std::string& fn);
    void saveLines(const std::string& fn);

    int getProgress() const;
    const std::vector<std::string>& getLines() const;
    void setLines(const std::vector<std::string> & l);
    const std::string &getFilename() const;
    bool isFault() const;

private:
    int progress;
    std::string fileName;
    std::vector<std::string> lines;
    bool fault;
    std::list<Observer *> observers;
};


#endif //LINESLOADER_RESOURCELOADER_H
