#ifndef STATEDEF_H
#define STATEDEF_H

#include "State.h"
#include <stack>
#include <memory>

namespace nn{
    typedef std::unique_ptr<State> StateRef;
    class StateMachine{
    public:
        StateMachine(){}
        ~StateMachine(){}

        void AddState(StateRef newState, bool isReplacing = true); //Add state to the stack, replaces top state from the stack if isReplacing is true
        void RemoveState();
        void ProcessStateChanges();
        StateRef &GetActiveState();

    private:
        std::stack<StateRef> m_states;
        StateRef m_newState;
        bool m_isRemoving;
        bool m_isAdding;
        bool m_isReplacing;
    };
}

#endif
