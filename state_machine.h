#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "graph.h"

class State_Machine
{
public:
    State_Machine() : cur_state(0) {}

    virtual void run();
    virtual void createGraph();

    virtual ~State_Machine() {}

protected:
    Graph graph;
    State* cur_state;
};

#endif // STATE_MACHINE_H
