//
// Created by mario on 07/09/23.
//

#ifndef RESOURCEMANAGER_CONTROLLER_H
#define RESOURCEMANAGER_CONTROLLER_H
#include "Model.h"


class Controller {
public:
    explicit Controller(Model* m): model(m){}
    int loadFromFile(const std::string & completeFileName);
    int saveToFile(const std::string & completeFileName);
    void deleteItemAt(int position){
        model->deleteResourceAt(position);
    }
    void insertItemAt(int position,const std::string& resource){
        model->insertResourceAt(position,resource);
    }

private:
    Model* model;
};


#endif //RESOURCEMANAGER_CONTROLLER_H
