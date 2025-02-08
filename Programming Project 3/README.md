This program is meant to simulate the behavior of a computer by reading files that contain up to 20 instructions (elf.txt) and executing those instructions based on defined opcodes and memory addresses (myvm.c)


Opcode	mnemonic	meaning

01	    LOAD		A <- Mem[x]

02	    ADD		    A <- A + Mem[x]

03	    STORE		Mem[x] <- A

04	    SUB		    A <- A - Mem[x]

05	    IN		    A <- read from device

06	    OUT		    A -> output to device

07	    END		    STOP

08	    JMP		    PC <- x

09	    SKIPZ		If A = 0, skip next instruction


Assignment: HW 3 Tiny Harvard Architecture ISA

Author: Kaitlyn Stagg

School: University of Central Florida

Professor: Euripides Montagne
Class: Computer Architecture Concepts

Language: C

To Compile, make sure the C file and input file are in the same directory. Then run gcc myvm.c, then run ./a.out input.txt

When: Must use a .txt file with opcodes & addresses in pairs of 2 per line.

