//
//  dfa.h
//  csc173project1
//
//  Created by Zhan Dov on 9/15/17.
//  Copyright © 2017 accolade. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef dfa_h
#define dfa_h

#define MAX_ASCII_CHARS 128
#define NO_TRANSITION -1

typedef struct  DFA_Each_State{
    int transitions[(unsigned char)MAX_ASCII_CHARS];
    bool accepting_state;
} DFA_Each_State;

typedef struct DFA{
    int currentState;
    int numberOfStates;
    DFA_Each_State *states;
} DFA;

extern DFA *createNewDFA(int nstates);
extern void DFA_free(DFA *dfa);
extern int DFA_get_size(DFA *dfa);
extern int DFA_get_transition(DFA *dfa, int state_src, char sym);
extern void DFA_set_transition(DFA *dfa, int state_src, char sym, int state_dst);
extern void DFA_set_transition_all(DFA *dfa, int state_src, int state_dst);
extern void DFA_set_transition_str(DFA *dfa, int state_src, char *str, int state_dst);
extern void DFA_set_accepting_state(DFA *dfa, int state, bool accepting_state_value);
extern void DFA_set_current_state(DFA *dfa, int state);
extern bool DFA_get_accepting_state(DFA *dfa, int state);
extern bool DFA_execute(DFA *dfa, char *input);
extern void DFA_print(DFA *dfa);

#endif /* dfa_h */

