#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "state.h"


class Graph
{
public:
    void addState(State*);
    void setTransition(int, int, int);

    bool loadGraph(const std::string&);
    void saveGraph(const std::string&) const;

    State* getState(int i) const { return i < states.size() ? states[i] : 0; }

    ~Graph();

private:
    std::vector<State*> states;
};

#endif // GRAPH_H
