#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <map>


class State
{
    typedef int Key;
    typedef std::map<Key, State*> Map; 

public:
    virtual void action() = 0;
    virtual ~State() {}

    void add_transition(State*, Key);
    State* nextState(Key);

    const Map& getTransitions() { return transitions; }

private:
    Map transitions;
};


//---------------------------------------------

class ChildState1 : public State
{
public:
    void action() { std::cout << "state 1";}
};

class ChildState2 : public State
{
public:
    void action() { std::cout << "state 2";}
};


static State* CreateState(int i)
{
    switch(i)
    {
    case 0:
        return new ChildState1;
    case 1:
        return new ChildState2;
    default:
        return 0;
    }
}

#endif // STATE_H
