#include "dfa.h"


/**
 * Allocates and returns a new DFA containing the given number of states.
 */
DFA *createNewDFA(int nstates)
{
    DFA *newDFA;
    newDFA = (DFA *)malloc(sizeof(DFA));
    newDFA->currentState = 0;
    newDFA->numberOfStates = nstates;
    newDFA->states = (DFA_Each_State *)malloc(nstates * sizeof(DFA_Each_State));
    
    int i, s;
    for(i=0; i < nstates;i++)
    {
        
        //set all states to have no transitions (-1)
        for(s=0; s < MAX_ASCII_CHARS; s++)
        {
            newDFA->states[i].transitions[s] = NO_TRANSITION;
        }

        //turn all states to false by default
        newDFA->states[i].accepting_state = false;
    }
    return newDFA;
}

/**
 * Frees the given DFA.
 */
void DFA_free(DFA *dfa){
    free(dfa->states);
    free(dfa);
}

/**
 * Returns the number of states in the given DFA.
 */
int DFA_get_size(DFA *dfa)
{
    return dfa->numberOfStates;
}

/**
 * Returns the state specified by the given DFA's transition function from
 * state src on input symbol sym.
 */
int DFA_get_transition(DFA *dfa, int state_src, char sym)
{
    return dfa->states[state_src].transitions[sym];
}

/**
 * For the given DFA, set the transition from state_src on input symbol
 * sym to be the state_dst.
 */
void DFA_set_transition(DFA *dfa, int state_src, char sym, int state_dst)
{
    dfa->states[state_src].transitions[sym] = state_dst;
}

/**
 * Set the transitions of the given DFA for each symbol in the given str.
 * This is a nice shortcut when you have multiple labels on an edge between
 * two states.
 */
void DFA_set_transition_str(DFA *dfa, int state_src, char *str, int state_dst)
{
    int i;
    for(i=0; i < strlen(str); i++)
    {
        DFA_set_transition(dfa, state_src, str[i], state_dst);
    }
}

/**
 * Set the transitions of the given DFA for all input symbols.
 * Another shortcut method.
 */
void DFA_set_transition_all(DFA *dfa, int state_src, int state_dst)
{
    int i;
    for(i=0;i < MAX_ASCII_CHARS;i++)
    {
        DFA_set_transition(dfa,state_src,i,state_dst);
    }
}

/**
 * Set whether the given DFA's state is accepting or not.
 */
inline void DFA_set_accepting_state(DFA *dfa, int state, bool accepting_state_value)
{
    dfa->states[state].accepting_state = accepting_state_value;
}

/**
 * Return true if the given DFA's state is an accepting state.
 */
bool DFA_get_accepting_state(DFA *dfa, int state)
{
    return dfa->states[state].accepting_state;
}

void DFA_set_current_state(DFA *dfa, int state)
{
    dfa->currentState=state;
}

/**
 * Run the given DFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
bool DFA_execute(DFA *dfa, char *input)
{
    DFA_set_current_state(dfa, 0);
    
    int i;
    for (i = 0; i < strlen(input); i++) {
        
        dfa->currentState = DFA_get_transition(dfa, dfa->currentState, input[i]);
        
        // OR more detailed version
        // dfa->currentState = dfa->states[dfa->currentState].transitions[input[i]];
        
        if (dfa->currentState == NO_TRANSITION)
        {
            return false;
        }
    }
    if (dfa->states[dfa->currentState].accepting_state)
        return true;
    
    return false;
}

/**
 * Print the given DFA to System.out.
 */
void DFA_print(DFA *dfa)
{
}

