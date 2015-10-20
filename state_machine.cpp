#include <iostream>

#include "state_machine.h"

void State_Machine::createGraph()
{
    graph.addState(new ChildState1);
    graph.addState(new ChildState2);

    graph.setTransition(0, 1, 123);
    graph.setTransition(1, 0, 333);


    cur_state = graph.getState(0);

    graph.saveGraph("D:/txt");
}

void State_Machine::run()
{
    createGraph();

    while(1)
    {
        cur_state->action();

        int type;
        std::cin >> type;

        cur_state = cur_state->nextState(type);
    }
}
