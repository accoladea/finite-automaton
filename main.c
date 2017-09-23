//
//  main.c
//  csc173project1
//  
//  Created by Zhan Dov on 9/15/17.
//  Copyright © 2017 accolade. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "nfa_to_dfa_conversion.h"

int main(int argc, const char * argv[]) {

/* PART 1 */
    
    int numberOfDFAs = 5;
    DFA *dfa[numberOfDFAs];
    char *dfa_inputs[5];
    
/* (a) DFA that accepts exactly the string ab */
   
    dfa[0]=createNewDFA(3);
  
    DFA_set_accepting_state(dfa[0],2,true);
    DFA_set_transition(dfa[0], 0, 'a', 1);
    DFA_set_transition(dfa[0], 1, 'b', 2);
    
    // Test it with different inputs
    
    dfa_inputs[0] = "ab";
    

 /* (b) DFA that detects any string that starts with the characters ab */

    dfa[1]=createNewDFA(3);

    DFA_set_accepting_state(dfa[1],2,true);
    DFA_set_transition(dfa[1], 0, 'a', 1);
    DFA_set_transition(dfa[1], 1, 'b', 2);
    DFA_set_transition_all(dfa[1], 2, 2);
    
    // Test it with different inputs
    
    dfa_inputs[1] = "abfinallyitsdone010100101!!!";
    
/* (c) Binary input with an even number of 1’s */
    
    dfa[2]=createNewDFA(2);
    
    DFA_set_accepting_state(dfa[2],0,true);
    DFA_set_transition(dfa[2], 0, '1', 1);
    DFA_set_transition(dfa[2], 1, '1', 0);
    DFA_set_transition(dfa[2], 0, '0', 0);
    DFA_set_transition(dfa[2], 1, '0', 1);
    
    // Test it with different inputs
    
    dfa_inputs[2] = "000000000111100";

/* (d) Binary input with an even number of both 0’s and 1’s */
    
    dfa[3]=createNewDFA(3);
    
    DFA_set_accepting_state(dfa[3],0,true);
    DFA_set_transition(dfa[3], 0, '1', 1);
    DFA_set_transition(dfa[3], 1, '1', 0);
    DFA_set_transition(dfa[3], 0, '0', 2);
    DFA_set_transition(dfa[3], 2, '0', 0);
    
    // Test it with different inputs
    
    dfa_inputs[3] = "0011001100110011";

    
/* (e) accepts strings ending in aql */
    
    dfa[4]=createNewDFA(4);
    
    DFA_set_accepting_state(dfa[4],3,true);
    
    DFA_set_transition_all(dfa[4], 0, 0);
    DFA_set_transition(dfa[4], 0, 'a', 1);
    DFA_set_transition_all(dfa[4], 1, 0);
    DFA_set_transition(dfa[4], 1, 'q', 2);
    DFA_set_transition_all(dfa[4], 2, 0);
    DFA_set_transition(dfa[4], 2, 'l', 3);
    
    // Test it with different inputs
    
    dfa_inputs[4] = "iboli vaqh iymonli aql";
    
    
    printf("Part 1:\n");
    for (int i = 0; i < numberOfDFAs; i++) {
        char *output;
        if (DFA_execute(dfa[i], dfa_inputs[i]))
        {
            output = "True";
        }
        else
        {
            output = "False";
        }
        printf("DFA -> (%c) Result: %s\n", i+'A', output);
        DFA_free(dfa[i]);
    }
    
/* PART 2 */
    
    
    int numberOfNFAs = 3;
    NFA *nfa[numberOfNFAs];
    char *nfa_inputs[3];
    
    /* (a) Strings ending in man */
    
    nfa[0] = NFA_new(4);
    NFA_set_accepting(nfa[0], 3, true);
    NFA_add_transition_all(nfa[0], 0, 0);
    NFA_add_transition(nfa[0], 0, 'm', 1);
    NFA_add_transition(nfa[0], 1, 'a', 2);
    NFA_add_transition(nfa[0], 2, 'n', 3);
    
    // Test for different inputs
    
    nfa_inputs[0] = "asdfman";
    
    
    /* (b) Strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s.
    That is, no string that it accepts can be the string “washington”, although it may
     accept strings that are not “washington”  */
    
    nfa[1] = NFA_new(20);
    
    NFA_set_accepting(nfa[1], 2, true);
    NFA_set_accepting(nfa[1], 4, true);
    NFA_set_accepting(nfa[1], 6, true);
    NFA_set_accepting(nfa[1], 8, true);
    NFA_set_accepting(nfa[1], 11, true);
    NFA_set_accepting(nfa[1], 13, true);
    NFA_set_accepting(nfa[1], 15, true);
    NFA_set_accepting(nfa[1], 17, true);
    NFA_set_accepting(nfa[1], 19, true);
    
    NFA_add_transition_all(nfa[1], 0, 0);
    for (int i = 1; i < 10; i=i+2) {
        NFA_add_transition_all(nfa[1], i, i);
    }
    for (int k = 10; k < 19; k=k+2) {
        NFA_add_transition_all(nfa[1], k, k);
    }

    NFA_add_transition(nfa[1], 0, 'a', 1);
    NFA_add_transition(nfa[1], 1, 'a', 2);
    NFA_add_transition(nfa[1], 0, 'g', 3);
    NFA_add_transition(nfa[1], 3, 'g', 4);
    NFA_add_transition(nfa[1], 0, 'h', 5);
    NFA_add_transition(nfa[1], 5, 'h', 6);
    NFA_add_transition(nfa[1], 0, 'i', 7);
    NFA_add_transition(nfa[1], 7, 'i', 8);
    NFA_add_transition(nfa[1], 0, 'n', 9);
    NFA_add_transition(nfa[1], 9, 'n', 10);
    NFA_add_transition(nfa[1], 10, 'n', 11);
    NFA_add_transition(nfa[1], 0, 'o', 12);
    NFA_add_transition(nfa[1], 12, 'o', 13);
    NFA_add_transition(nfa[1], 0, 's', 14);
    NFA_add_transition(nfa[1], 14, 's', 15);
    NFA_add_transition(nfa[1], 0, 't', 16);
    NFA_add_transition(nfa[1], 16, 't', 17);
    NFA_add_transition(nfa[1], 0, 'w', 18);
    NFA_add_transition(nfa[1], 18, 'w', 19);
    
    // Test for different inputs
    
    nfa_inputs[1] = "aagghhiinnnoossttww";
    
    /* (c) Accepts  a’s, b’s, and c’s only, contains abc anywhere  */
    
    nfa[2] = NFA_new(5);
    NFA_set_accepting(nfa[2], 3, true);
    
    NFA_add_transition_str(nfa[2], 0, "abc", 0);
    NFA_add_transition(nfa[2], 0, 'a', 1);
    NFA_add_transition(nfa[2], 1, 'b', 2);
    NFA_add_transition(nfa[2], 2, 'c', 3);
    NFA_add_transition_str(nfa[2], 3, "abc", 3);

    // Test for different inputs
    
    nfa_inputs[2] = "abc";
    
    printf("Part 2:\n");
    for (int i = 0; i < numberOfNFAs; i++) {
        char *output;
        if (NFA_execute(nfa[i], nfa_inputs[i]))
        {
            output = "True";
        }
        else
        {
            output = "False";
        }
        printf("NFA -> (%c) Result: %s\n", i+'A', output);
        NFA_free(nfa[i]);
    }
    

    printf("Part 3: \n");
    
    
    
    return 0;
}
