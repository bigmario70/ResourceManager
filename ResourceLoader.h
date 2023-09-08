//
// Created by mario on 21/06/23.
//

#ifndef RESOURCELOADER_RESOURCELOADER_H
#define RESOURCELOADER_RESOURCELOADER_H


#include <list>
#include <string>
#include "Subject.h"

class ResourceLoader : public Subject {
public:
    explicit ResourceLoader(const std::string& compFileName ): completeFileName(compFileName), progress(0), fault(false){}
    virtual ~ResourceLoader () {}
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;

    void loadResources();

    int getProgress() const;
    bool isFault() const;
    const std::string &getFilename() const;
    const std::list<std::string>& getLines() const;

private:

    std::string completeFileName;
    int progress;
    bool fault;
    std::list<std::string> lines;
    std::list<Observer *> observers;
};


#endif //RESOURCELOADER_RESOURCELOADER_H
