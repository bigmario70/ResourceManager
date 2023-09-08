//
// Created by mario on 02/07/23.
//

#ifndef LINESLOADER_PROGRESSBAR_H
#define LINESLOADER_PROGRESSBAR_H

#include <iostream>
#ifndef WX_PRECOMP
#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/progdlg.h>
#endif

#include "Observer.h"
#include "ResourceLoader.h"

class ProgressBar : public Observer,public wxProgressDialog{
public:

    explicit ProgressBar(ResourceLoader * ll): wxProgressDialog(wxT("Loading resources"), wxT("Loading resources from file:"+ll->getFilename()), 100,nullptr, wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME | wxPD_APP_MODAL), linesLoader(ll){
        linesLoader->subscribe(this);

    }
    virtual ~ProgressBar(){
        linesLoader->unsubscribe(this);
    }

    void update() override{
        wxMilliSleep(250);
        this->Update(linesLoader->getProgress());
    }
private:
    ResourceLoader* linesLoader;
};


#endif //LINESLOADER_PROGRESSBAR_H
