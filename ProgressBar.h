//
// Created by mario on 02/07/23.
//

#ifndef LINESLOADER_PROGRESSBAR_H
#define LINESLOADER_PROGRESSBAR_H

#include <iostream>
#include "Observer.h"
#include "LinesLoader.h"

class ProgressBar : public Observer{
public:

    explicit ProgressBar(LinesLoader * ll): linesLoader(ll){
        linesLoader->subscribe(this);

    }
    virtual ~ProgressBar(){
        linesLoader->unsubscribe(this);
    }
    void update() override{
        std::cout << "Lines Loading Progress: " << linesLoader->getProgress()<<std::endl;
    }
private:
    LinesLoader * linesLoader;
};


#endif //LINESLOADER_PROGRESSBAR_H
