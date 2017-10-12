 /*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 2
 SOURCES: stackoverflow.com
 */

#include <iostream>
#include <string>

using namespace std;

int row;
int invalids = 0;
bool P, Q, R;
bool premise, conclusion;

void evaluate_premise() {
    // Hardcode PREMISE here
    /* ? | conditional (->); ^ | exclusive or (XOR); == | biconditional (<->) */
    premise = ((((P || Q) && (Q ? R : true)) ^ (P && R)) == (R && Q));
    
    cout << row << "\t"
         << P << "\t"
         << Q << "\t"
         << R << "\t"
         << premise << "\t";
}

void evaluate_conclusion() {
    // Hardcode CONCLUSION here
    /* ? | conditional (->); ^ | exclusive or (XOR); == | biconditional (<->) */
    conclusion = (P || R);
    
    cout << conclusion << "\t";
}

void evaluate_validity() {
    // Check for validity
    if (premise && !conclusion) {
        cout << "This argument is invalid in row "
             << row
             << "."
             << endl;
        invalids++;
    } else {
        cout << endl;
    }
}

int main() {
    // Print column headers
    cout << "Row" << "\t"
         << "P" << "\t"
         << "Q" << "\t"
         << "R" << "\t"
         << "Prem" << "\t"
         << "Concl" << "\t"
         << endl;
    
    // Evaluate all (8!) possible truth table outputs
    row = 0;
    P = true, Q = true, R = true;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    row = 1;     
    P = true, Q = true, R = false;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    row = 2;
    P = true, Q = false, R = true;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    row = 3;
    P = true, Q = false, R = false;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
         
    row = 4;
    P = false, Q = true, R = true;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    row = 5;
    P = false, Q = true, R = false;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
         
    row = 6;
    P = false, Q = false, R = true;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    row = 7;
    P = false, Q = false, R = false;
    evaluate_premise();
    evaluate_conclusion();
    evaluate_validity();
    
    if (invalids == 0) {
        cout << "This argument is valid." << endl;
    }
}