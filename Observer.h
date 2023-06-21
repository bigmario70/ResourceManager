#ifndef LINESLOADER_OBSERVER_H
#define LINESLOADER_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {}
    virtual	void update() = 0;
};


#endif //LINESLOADER_OBSERVER_H
