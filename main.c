/*
 * File: main.c
 * Creator: George Ferguson
 * Created: Mon Nov 28 14:11:17 2016
 * Time-stamp: <Tue Jul 17 16:02:29 EDT 2018 ferguson>
 */
#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"

/**
 * Two AND gates connected to make a 3-input AND circuit.
 */
// static Circuit* and3_Circuit() {
// 	Boolean* x = new_Boolean(false);
// 	Boolean* y = new_Boolean(false);
// 	Boolean* z = new_Boolean(false);
// 	Boolean** inputs = new_Boolean_array(3);
// 	inputs[0] = x;
// 	inputs[1] = y;
// 	inputs[2] = z;

// 	Boolean* out = new_Boolean(false);
// 	Boolean** outputs = new_Boolean_array(1);
// 	outputs[0] = out;

// 	Gate* A1 = new_AndGate();
// 	Gate* A2 = new_AndGate();
// 	Gate** gates = new_Gate_array(2);
// 	gates[0] = A1;
// 	gates[1] = A2;

// 	Circuit *circuit = new_Circuit(3, inputs, 1, outputs, 2, gates);
// 	Circuit_connect(circuit, x, Gate_getInput(A1, 0));
// 	Circuit_connect(circuit, y, Gate_getInput(A1, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2, 0));
// 	Circuit_connect(circuit, z, Gate_getInput(A2, 1));
// 	Circuit_connect(circuit, Gate_getOutput(A2), out);
// 	return circuit;
// }

static char* b2s(bool b) {
	return b ? "T" : "F";
}

//Circuit a with three inputs and one output
static Circuit* Circuit_a(){
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean* z = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A1 = new_Inverter();
	Gate* A2 = new_AndGate();
    Gate* A3 = new_AndGate();
    Gate* A4 = new_OrGate();
    Gate** gates = new_Gate_array(4);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;

    Circuit *circuit = new_Circuit(3, inputs,1,outputs,4, gates);
    Circuit_connect(circuit, y, Gate_getInput(A1,0));
    Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2,0));
    Circuit_connect(circuit, x, Gate_getInput(A2,1));
    Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 0));
    Circuit_connect(circuit, y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, z, Gate_getInput(A3,1));
    Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 1));
    Circuit_connect(circuit, Gate_getOutput(A4), out);
    return circuit;
}

static Circuit* Circuit_b(){
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean* z = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = z;

	Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

    Gate* A1 = new_Inverter();
	Gate* A2 = new_NAndGate();
    Gate* A3 = new_NAndGate();
    Gate* A4 = new_NOrGate();
    Gate** gates = new_Gate_array(4);
    gates[0] = A1;
    gates[1] = A2;
    gates[2] = A3;
    gates[3] = A4;

    Circuit *circuit = new_Circuit(3, inputs,1,outputs,4, gates);
    Circuit_connect(circuit, y, Gate_getInput(A1,0));
    Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A2,0));
    Circuit_connect(circuit, x, Gate_getInput(A2,1));
    Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A4, 0));
    Circuit_connect(circuit, y, Gate_getInput(A3, 0));
    Circuit_connect(circuit, z, Gate_getInput(A3,1));
    Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A4, 1));
    Circuit_connect(circuit, Gate_getOutput(A4), out);
    return circuit;
}

static Circuit* Circuit_c(){
    Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(2);
    inputs[0] = x;
    inputs[1] = y;

    Boolean* out = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(1);
	outputs[0] = out;

	Gate* A = new_AndGate();
	Gate* B = new_Inverter();
	Gate* C = new_Inverter();
	Gate* D = new_AndGate();
	Gate* E = new_OrGate();
    Gate** gates = new_Gate_array(5);
    gates[0] = A;
    gates[1] = B;
    gates[2] = C;
    gates[3] = D;
    gates[4] = E;

    Circuit *circuit = new_Circuit(2, inputs, 1, outputs, 5, gates);
    Circuit_connect(circuit, x, Gate_getInput(A,0));
    Circuit_connect(circuit, y, Gate_getInput(A,1));
    Circuit_connect(circuit, Gate_getOutput(A), Gate_getInput(E,0));
    Circuit_connect(circuit, x, Gate_getInput(B,0));
    Circuit_connect(circuit, Gate_getOutput(B), Gate_getInput(D,0));
    Circuit_connect(circuit, y, Gate_getInput(C,0));
    Circuit_connect(circuit, Gate_getOutput(C), Gate_getInput(D,1));
    Circuit_connect(circuit, Gate_getOutput(D), Gate_getInput(E,1));
    Circuit_connect(circuit, Gate_getOutput(E), out);
    return circuit;
}

//one-bit-adder circuit
static Circuit* Circuit_one_bit(){
	Boolean* x = new_Boolean(false);
    Boolean* y = new_Boolean(false);
    Boolean* c = new_Boolean(false);
    Boolean** inputs = new_Boolean_array(3);
	inputs[0] = x;
	inputs[1] = y;
	inputs[2] = c;

	Boolean* out1 = new_Boolean(false);
	Boolean* out2 = new_Boolean(false);
	Boolean** outputs = new_Boolean_array(2);
	outputs[0] = out1;
    outputs[1] = out2;

    Gate* G1 = new_Inverter();
	Gate* G2 = new_Inverter();
	Gate* G3 = new_Inverter();
    Gate* A1 = new_And3Gate();
    Gate* A2 = new_And3Gate();
    Gate* A3 = new_And3Gate();
    Gate* A4 = new_And3Gate();
    Gate* A5 = new_And3Gate();
    Gate* A6 = new_And3Gate();
    Gate* A7 = new_And3Gate();	
    Gate* A8 = new_Or4Gate();
    Gate* A9 = new_Or4Gate();	
    Gate** gates = new_Gate_array(12);
    gates[0] = G1;
    gates[1] = G2;
    gates[2] = G3;
    gates[3] = A1;
    gates[4] = A2;
    gates[5] = A3;
    gates[6] = A4;
    gates[7] = A5;
    gates[8] = A6;
    gates[9] = A7;
    gates[10] = A8;
    gates[11] = A9;  
    Circuit *circuit = new_Circuit(3, inputs, 2, outputs, 12, gates);
    //A1
    Circuit_connect(circuit, x, Gate_getInput(G1,0));
    Circuit_connect(circuit, Gate_getOutput(G1), Gate_getInput(A1,0));
    Circuit_connect(circuit, c, Gate_getInput(A1,1));
    Circuit_connect(circuit, y, Gate_getInput(G2,0));
    Circuit_connect(circuit, Gate_getOutput(G2), Gate_getInput(A1,2));
    Circuit_connect(circuit, Gate_getOutput(A1), Gate_getInput(A8,0));
    //A2
    Circuit_connect(circuit, x, Gate_getInput(G1,0));
    Circuit_connect(circuit, Gate_getOutput(G1), Gate_getInput(A2,0));
    Circuit_connect(circuit, y, Gate_getInput(A2,1));
    Circuit_connect(circuit, c, Gate_getInput(G3,0));
    Circuit_connect(circuit, Gate_getOutput(G3), Gate_getInput(A2,2));
    Circuit_connect(circuit, Gate_getOutput(A2), Gate_getInput(A8,1));
    //A3
    Circuit_connect(circuit, x, Gate_getInput(G1,0));
    Circuit_connect(circuit, Gate_getOutput(G1), Gate_getInput(A3,0));
    Circuit_connect(circuit, y, Gate_getInput(A3,1));
    Circuit_connect(circuit, c, Gate_getInput(A3,2));
    Circuit_connect(circuit, Gate_getOutput(A3), Gate_getInput(A9,0));
    //A4
    Circuit_connect(circuit, x, Gate_getInput(A4,0));
    Circuit_connect(circuit, y, Gate_getInput(G2,0));
    Circuit_connect(circuit, Gate_getOutput(G2), Gate_getInput(A4,1));
    Circuit_connect(circuit, c, Gate_getInput(G3,0));
    Circuit_connect(circuit, Gate_getOutput(G3), Gate_getInput(A4,2));
    Circuit_connect(circuit, Gate_getOutput(A4), Gate_getInput(A8,2));
    //A5
    Circuit_connect(circuit, x, Gate_getInput(A5,0));
    Circuit_connect(circuit, y, Gate_getInput(G2,0));
    Circuit_connect(circuit, Gate_getOutput(G2), Gate_getInput(A5,1));
    Circuit_connect(circuit, c, Gate_getInput(A5,2));
    Circuit_connect(circuit, Gate_getOutput(A5), Gate_getInput(A9,1));
    //A6
    Circuit_connect(circuit, c, Gate_getInput(G3,0));
    Circuit_connect(circuit, Gate_getOutput(G3), Gate_getInput(A6,0));
    Circuit_connect(circuit, y, Gate_getInput(A6,1));
    Circuit_connect(circuit, x, Gate_getInput(A6,2));
    Circuit_connect(circuit, Gate_getOutput(A6), Gate_getInput(A9,2));
    //A7
    Circuit_connect(circuit, c, Gate_getInput(A7,0));
    Circuit_connect(circuit, x, Gate_getInput(A7,1));
    Circuit_connect(circuit, y, Gate_getInput(A7,2));
    Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A8,3));
    Circuit_connect(circuit, Gate_getOutput(A7), Gate_getInput(A9,3));
    Circuit_connect(circuit, Gate_getOutput(A8), out1);
    Circuit_connect(circuit, Gate_getOutput(A9), out2);
    return circuit;
}
//for one-bit-adder
static void test3In2Out(Circuit* circuit, bool in0, bool in1, bool in2){
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out1 = Circuit_getOutput(circuit, 0);
	bool out2 = Circuit_getOutput(circuit, 1);
	printf("%s %s %s -> %s %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out1), b2s(out2));
}

static void test3In1Out(Circuit* circuit, bool in0, bool in1, bool in2) {
	Circuit_setInput(circuit, 0, in0);
	Circuit_setInput(circuit, 1, in1);
	Circuit_setInput(circuit, 2, in2);
	Circuit_update(circuit);
	bool out0 = Circuit_getOutput(circuit, 0);
	printf("%s %s %s -> %s\n", b2s(in0), b2s(in1), b2s(in2), b2s(out0));
}

static void test2In1Out(Circuit* circuit, bool in0, bool in1){
	Circuit_setInput(circuit, 0, in0);
    Circuit_setInput(circuit, 1, in1);	
    Circuit_update(circuit);
    bool out0 = Circuit_getOutput(circuit,0);
    printf("%s %s -> %s \n", b2s(in0), b2s(in1), b2s(out0));
}

static void test_Circuit(Circuit* circuit){
	//Circuit_dump(circuit);
	if ( Circuit_numInputs(circuit) == 3){
        test3In1Out(circuit, true, true, true);
        test3In1Out(circuit, true, true, false);
        test3In1Out(circuit, true, false, true);
        test3In1Out(circuit, false, true, true);
        test3In1Out(circuit, false, false, true);
        test3In1Out(circuit, true, false, false);
        test3In1Out(circuit, false, true, false);
        test3In1Out(circuit, false, false, false);
	} else if (Circuit_numInputs(circuit) == 2){
		test2In1Out(circuit, true, true);
		test2In1Out(circuit, true, false);
		test2In1Out(circuit, false, true);
		test2In1Out(circuit, false, false);
	}
	Circuit_free(circuit);
}
int main(int argc, char **argv) {
	Circuit* circuit = Circuit_a();
	Circuit* circuit2 = Circuit_b();
    Circuit* circuit3 = Circuit_c();
    Circuit* circuit4 = Circuit_one_bit();
    printf("Here is circuit a testing\n");
    test_Circuit(circuit);
    printf("\n");
    printf("Here is circuit b testing\n");
    test_Circuit(circuit2);
    printf("\n");
    printf("Here is circuit c testing\n");
    test_Circuit(circuit3);
    printf("\n");
    printf("Here is the extra credit one-bit-adder circuit\n");
    //Circuit_dump(circuit4);
    test3In2Out(circuit4, true, true, true);
    test3In2Out(circuit4, true, true, false);
    test3In2Out(circuit4, true, false, true);
    test3In2Out(circuit4, false, true, true);
    test3In2Out(circuit4, false, false, true);
    test3In2Out(circuit4, true, false, false);
    test3In2Out(circuit4, false, true, false);
    test3In2Out(circuit4, false, false, false);
    Circuit_free(circuit4);
}
