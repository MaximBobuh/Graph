#include <algorithm>
#include <fstream>

#include "graph.h"


Graph::~Graph()
{
    for(int i = 0; i < states.size(); ++i)
        delete states[i];
}

//------------------------------------------------


bool Graph::loadGraph(const std::string& name)
{
    int size, type, first, second, key;

    std::fstream file(name.c_str(), std::ios_base::in);
    if(!file.is_open())
        return false;

    file >> size;
    states.resize(size);

    for(int i = 0; i < size; ++i)
    {
        states[i] = CreateState(i);
    }

    while(file >> first >> second >> key)
        states[first]->add_transition(states[second], key);

    return true;
}

void Graph::saveGraph(const std::string& name) const
{
    std::fstream file(name.c_str(), std::ios_base::out);

    file << states.size() << std::endl;
    for(int i = 0; i < states.size(); ++i)
    {
        std::map<int, State*> tmp = states[i]->getTransitions();
        std::map<int, State*>::iterator it = tmp.begin();

        for(; it != tmp.end(); ++it)
        {
            file << i << " ";
            file << std::distance(states.begin(), std::find(states.begin(), states.end(), it->second)) << " ";
            file << it->first << std::endl;
        }
    }
    file.close();
}


//------------------------------------------------

void Graph::addState(State* state)
{
    states.push_back(state);
}

//------------------------------------------------

void Graph::setTransition(int first, int second, int key)
{
    if(first < states.size() && second < states.size())
        states[first]->add_transition(states[second], key);
}





