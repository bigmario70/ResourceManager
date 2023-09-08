//
// Created by mario on 07/09/23.
//

#include "Controller.h"
#include "ResourceLoader.h"
#include "ProgressBar.h"
#include "MyExceptions.h"

int Controller::loadFromFile(const std::string & compFileName){
    std::list<std::string> resList;
    ResourceLoader myLoader(compFileName);
    ProgressBar myPB(&myLoader);
    myLoader.loadResources();
    model->setResList(myLoader.getLines());
    if(myLoader.isFault())
        return -1;
    else
        return 0;
}

int Controller::saveToFile(const std::string & compFileName){
/*

    ResourceLoader myLoader2;
    ProgressBar myPB2(&myLoader2,this);
    int items_count=10;
    resListBox->GetCount();
    int i = 0;
    std::vector<std::string>  list;

    do
    {
    list.emplace_back(resListBox->GetString(i++));
    }
    while(i < items_count);

    myLoader2.setLines(list);

    try {
    myLoader2.saveLines(dirName.ToStdString()+"/"+completeFileName.ToStdString());
    }
    catch(const FailedToOpenFile& e){
    wxMessageBox(wxT("Failed To Open File"+myLoader2.getFilename()),wxT("Error"),wxOK|wxCENTRE,this);
    return;
    }
    */
    return 0;
}