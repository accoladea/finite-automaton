#include "nfa_to_dfa_conversion.h"

DFA *NFA_to_DFA_convert(NFA *nfa){
    
//    IntSet_free(nfa->currentStates);
//    nfa->currentStates = IntSet_new();
//    IntSet_add(nfa->currentStates, 0);
//    
//    IntSet newStates = IntSet_new();
//    
//    IntSetIterator p = IntSet_iterator(nfa->currentStates);
//    
//    for (int i = 0; i < 128; i++) {
//        while (IntSetIterator_has_next(p)) {
//            IntSet_union(newStates, nfa->states[IntSetIterator_next(p)].transitions[i]);
//        }
//    }
//    
//    //NFA set current states
//    IntSet_free(nfa->currentStates);
//    nfa->currentStates = newStates;
//    
//    //if IntSet is empty return false
//    if(IntSet_is_empty(nfa->currentStates))
//        return false;
//    
    
    
    return 0;
}
