//
// Created by mario on 09/09/23.
//

#ifndef RESOURCEMANAGER_MOCKPROGRESSBAR_H
#define RESOURCEMANAGER_MOCKPROGRESSBAR_H

#include <vector>
#include "../Observer.h"
#include "../ResourceLoader.h"

class MockProgressBar : public Observer{
public:

    explicit MockProgressBar(ResourceLoader * ll): linesLoader(ll){
        linesLoader->subscribe(this);
        progressHistory.reserve(11);

    }
    virtual ~MockProgressBar(){
        linesLoader->unsubscribe(this);
    }

    void update() override{
        progressHistory.push_back(linesLoader->getProgress());
    }

    const std::vector<int>& getProgressHistory(){
        return progressHistory;
    };

private:
    ResourceLoader* linesLoader;
    //int position[20];
    //int lineNumber;
    std::vector<int> progressHistory;
};
#endif //RESOURCEMANAGER_MOCKPROGRESSBAR_H
