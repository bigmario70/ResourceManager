//
// Created by mario on 07/09/23.
//

#include "Model.h"

void Model::notify() {
    for (auto observer : observers)
        observer->update();
}

void Model::subscribe(Observer* o) {
    observers.push_back(o);
}

void Model::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Model::insertResourceAt(int position,const std::string& resource){
    if ((0 <= position) && (position <=resList.size())){
        auto it = resList.begin();
        for(int i=0;i<position;i++){
            it++;
        }
        resList.insert(it,resource);
        notify();
    }
}

void Model::deleteResourceAt(int position){
    if ((0 <= position) && (position <resList.size())){
        auto it = resList.begin();
        for(int i=0;i<position;i++){
            it++;
        }
        resList.erase(it);
        notify();
    }
}

void Model::setResList(const std::list<std::string>& newList){
    /*resList.clear();
    for(auto res:newList){
        this->resList.emplace_back(res);
    }*/
    resList=newList;
    notify();
}