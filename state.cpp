#include "state.h"

void State::add_transition(State* state, Key key)
{
    transitions[key] = state;
}

State* State::nextState(Key key)
{
    Map::const_iterator it = transitions.find(key);
    return it != transitions.end() ? it->second : this;
}
