#include "nfa.h"

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFA *NFA_new(int nstates)
{
    NFA *newNFA = (NFA *)malloc(sizeof(NFA));
    newNFA->numberOfStates = nstates;
    newNFA->currentStates = IntSet_new();
    newNFA->states=(NFA_Each_State *)malloc(nstates * sizeof(NFA_Each_State));
    IntSet_add(newNFA->currentStates, 0);
    
    int s;
    for(s=0; s < nstates; s++)
    {
        int t;
        for(t=0; t < 128; t++)
        {
            newNFA->states[s].transitions[t] = IntSet_new();
        }
        
        //turn all states to false by default
        newNFA->states[s].accepting_state = false;
    }

    return newNFA;
}

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA *nfa)
{
    int s;
    for(s=0; s < nfa->numberOfStates; s++)
    {
        int t;
        for(t=0; t < 128; t++)
        {
            IntSet_free(nfa->states[s].transitions[t]);
        }
    }
    free(nfa->states);
    free(nfa);
}

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA *nfa)
{
    return nfa->numberOfStates;
}

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern IntSet NFA_get_transitions(NFA *nfa, int state, char sym)
{
    return nfa->states[state].transitions[sym];
}

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA *nfa, int src, char sym, int dst)
{
    IntSet_add(nfa->states[src].transitions[sym], dst);
}

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA *nfa, int src, char *str, int dst)
{
    int t;
    for (t=0;t<strlen(str);t++)
        NFA_add_transition(nfa, src, str[t], dst);
}

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA *nfa, int src, int dst)
{
    
    int t;
    for (t=0;t<128;t++)
        NFA_add_transition(nfa, src, t, dst);
}

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA *nfa, int state, bool value)
{
    nfa->states[state].accepting_state = value;
}

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFA *nfa, int state)
{
    return nfa->states[state].accepting_state;
}

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */



extern bool NFA_execute(NFA *nfa, char *input)
{
    //sets current state to zero
    
    IntSet_free(nfa->currentStates);
    nfa->currentStates = IntSet_new();
    IntSet_add(nfa->currentStates, 0);

    int i;
    for (i = 0; i < strlen(input); i++) {
        
        IntSet newStates = IntSet_new();
        
        IntSetIterator p = IntSet_iterator(nfa->currentStates);
        
        while (IntSetIterator_has_next(p)) {
            IntSet_union(newStates, NFA_get_transitions(nfa, IntSetIterator_next(p), input[i]));
            }
        
        //NFA set current states
        IntSet_free(nfa->currentStates);
        nfa->currentStates = newStates;
        
        //if IntSet is empty return false
        if(IntSet_is_empty(nfa->currentStates))
            return false;
        
    }
    
    //gets the current states and checks if it's accepting state returns true
    IntSetIterator p = IntSet_iterator(nfa->currentStates);
    
    while(IntSetIterator_has_next(p)){
        if (nfa->states[IntSetIterator_next(p)].accepting_state)
            return true;
    }
    
    return false;
}

/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA *nfa)
{
    
}
