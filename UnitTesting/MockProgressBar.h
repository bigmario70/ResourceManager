//
// Created by mario on 09/09/23.
//

#ifndef RESOURCEMANAGER_MOCKPROGRESSBAR_H
#define RESOURCEMANAGER_MOCKPROGRESSBAR_H

#include "../Observer.h"
#include "../ResourceLoader.h"

class MockProgressBar : public Observer{
public:

    explicit MockProgressBar(ResourceLoader * ll): linesLoader(ll),lineNumber(0){
        linesLoader->subscribe(this);

    }
    virtual ~MockProgressBar(){
        linesLoader->unsubscribe(this);
    }

    void update() override{
        progressHistory[lineNumber++]= linesLoader->getProgress();
    }

    int*  getProgressHistory(){
        return progressHistory;
    };

private:
    ResourceLoader* linesLoader;
    //int position[20];
    int lineNumber;
    int progressHistory[11];
};
#endif //RESOURCEMANAGER_MOCKPROGRESSBAR_H
