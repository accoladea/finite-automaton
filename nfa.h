//
//  nfa.h
//  csc173project1
//
//  Created by Zhan Dov on 9/17/17.
//  Copyright © 2017 accolade. All rights reserved.
//

#ifndef nfa_h
#define nfa_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "IntSet.h"


typedef struct  NFA_Each_State{
    IntSet transitions[128];
    bool accepting_state;
} NFA_Each_State;

typedef struct NFA{
    IntSet currentStates;
    int numberOfStates;
    NFA_Each_State *states;
} NFA;

extern NFA *NFA_new(int nstates);
extern void NFA_free(NFA *nfa);
extern int NFA_get_size(NFA *nfa);
extern IntSet NFA_get_transitions(NFA *nfa, int state, char sym);
extern void NFA_add_transition(NFA *nfa, int src, char sym, int dst);
extern void NFA_add_transition_str(NFA *nfa, int src, char *str, int dst);
extern void NFA_add_transition_all(NFA *nfa, int src, int dst);
extern void NFA_set_accepting(NFA *nfa, int state, bool value);
extern bool NFA_get_accepting(NFA *nfa, int state);
extern bool NFA_execute(NFA *nfa, char *input);
extern void NFA_print(NFA *nfa);

#endif /* nfa_h */
