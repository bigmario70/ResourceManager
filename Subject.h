#ifndef LINESLOADER_SUBJECT_H
#define LINESLOADER_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {}
    virtual void notify() = 0;
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
};


#endif //LINESLOADER_SUBJECT_H
