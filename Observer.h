#ifndef RESOURCELOADER_OBSERVER_H
#define RESOURCELOADER_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}
    virtual	void update() = 0;
};


#endif //RESOURCELOADER_OBSERVER_H
