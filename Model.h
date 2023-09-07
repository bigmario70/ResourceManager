//
// Created by mario on 07/09/23.
//

#ifndef RESOURCEMANAGER_MODEL_H
#define RESOURCEMANAGER_MODEL_H

#include "Subject.h"
#include <list>
#include <string>

class Model:public Subject {
public:
    Model(){}
    virtual ~Model () {}
    void notify() override;
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void insertResourceAt(int position,const std::string& resource);
    void deleteResourceAt(int position);
    void setResList(const std::list<std::string>& newList);
    const std::list<std::string> &getResList() const {
        return resList;
    }

private:
    std::list<std::string> resList;
    std::list<Observer *> observers;
};


#endif //RESOURCEMANAGER_MODEL_H
