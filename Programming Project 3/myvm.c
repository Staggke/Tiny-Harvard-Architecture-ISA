//Kaitlyn Stagg

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXPROGRAMSIZE 20

typedef struct {
    int opCode;
    int address;
}instruction;

instruction IM[MAXPROGRAMSIZE];
instruction IR;//instruction register
instruction MDR1;//memory data register
int DM[MAXPROGRAMSIZE]; 
int pc = 0;//program counter
int a = 0;//accumulator 
int MAR1 = 0;//memory access register
int MAR2 = 0;//^^^^
int MDR2 = 0;//memory data register
int run = 1;
int opCode = 0;
int address = 0;
int i = 0;


int main (int argc, char *argv[])
{
    if(argc != 2)
    {
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    
    if(f == NULL)
    {
        printf("Can't open file");
        return 1;
    }
    
    while(fscanf(f, "%d %d", &opCode, &address) == 2) //read file & store in instruct mem arr
    {
        IM[i].opCode = opCode;
        IM[i].address = address;
        i++;
    }
    fclose(f);

    printf("Assembling program...\n");
    printf("Program Assembled\n");

    while(run != 0)
    {
        //fetch 
        MAR1 = pc;
        pc++;
        MDR1 = IM[MAR1];
        IR = MDR1;

        switch(IR.opCode)
        {
            case 1: //LOAD
                MAR2 = IR.address;
                MDR2 = DM[MAR2];
                a = MDR2;
                printf("\n/* loading from address %d */", MAR2);
                break;
            case 2: //ADD
                MAR2 = IR.address;
                MDR2 = DM[MDR2];
                a += MDR2;
                printf("\n/* adding value %d to accumulator */", MDR2);
                break;
            case 3: //STORE
                MAR2 = IR.address;
                MDR2 = a;
                DM[MAR2] = MDR2;
                printf("\n/* storing accumulator to memory location %d */", MAR2);
                break;
            case 4: //SUB
                MAR2 = IR.address;
                MDR2 = DM[MAR2];
                a -= MDR2;
                printf("\n/* subtracting value %d from accumulator */", MDR2);
                break;
            case 5: //IN
                printf("\n/* input value */\n");
                scanf("%d", &a);
                break;
            case 6: //OUT
                printf("\n/* outputting accumulator to screen */");
                printf("\n%d\n", a);
                break;
            case 7: //END
                run = 0;
                printf("\nProgram complete.\n");
                break;
            case 8: //JMP
                pc = IR.address;
                printf("\n/* jumping to address %d */", pc);
                break;
            case 9: //SKIPZ
                if(a == 0)
                {
                    printf("\n/* skipping */");
                    pc++;
                }
                else if(a != 0){
                    printf("\n/* attempted to skip but accumulator was not 0 */\n");
                }
                break;
            default:
                printf("\nInvalid Operation %d\n", IR.opCode);
                break;
        }

        if(IR.opCode != 7 && IR.opCode < 10){
            printf("\nPC = %d | A = %d | DM = [", pc, a);
            for(int j = 0; j < MAXPROGRAMSIZE; j++)
            {
                printf("%d" , DM[j]);            
                if(j != (MAXPROGRAMSIZE-1)){
                    printf(", ");
                }
                
            }
            printf("]\n");
        }

    }

    return 0;
}



    
