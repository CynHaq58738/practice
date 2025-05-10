
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

/******************************************************************
* Project CS2253
* This program converts from assembly file into a binary file
*
* Cynthia Haque and Jeremy Qiao
* 4-2-2025
******************************************************************* */

/***********************************************************
*function:registerToBinary
*accept: char* register
*this function converts a register to a binary number
************************************************************ */
const char* registerToBinary(const char* reg) 
{
    if (strcmp(reg, "R0") == 0) 
    {
        return "000";
    }
    else if (strcmp(reg, "R1") == 0) 
    {
        return "001";
    }
    else if (strcmp(reg, "R2") == 0) 
    {
        return "010";
    }
    else if (strcmp(reg, "R3") == 0) 
    {
        return "011";
    }
    else if (strcmp(reg, "R4") == 0) 
    {
        return "100";
    }
    else if (strcmp(reg, "R5") == 0) 
    {
        return "101";
    }
    else if (strcmp(reg, "R6") == 0) 
    {
        return "110";
    }
    else if (strcmp(reg, "R7") == 0) 
    {
        return "111";
    }
    else
    {
        //default 000
        return "000"; 
    }
}

/************************************************************************************
*function:branch
*accept: char* condition
*this function converts the branch condition to binary
************************************************************************************* */
const char* branch(const char* condition) 
{
    if (strcmp(condition, "n") == 0) 
    {
        return "100";
    }
    else if (strcmp(condition, "z") == 0) 
    {
        return "010";
    }
    else if (strcmp(condition, "p") == 0) 
    {
        return "001";
    }
    else if (strcmp(condition, "nz") == 0) 
    {
        return "110";
    }
    else if (strcmp(condition, "np") == 0) 
    {
        return "101";
    }
    else if (strcmp(condition, "pz") == 0) 
    {
        return "011";
    }
    else if (strcmp(condition, "nzp") == 0) 
    {
        return "111";
    }
    else
    {
        return "000";
    }
}

/***************************************************************************
*function:immediateToBinary
*accept: int imm, char* output
*this function to convert immediate value(offset) to a 5-bit binary string
**************************************************************************** */
void immediateToBinary(int imm, char* output) 
{
    //5-bit signed numbers range from -16 to 15 
    if (imm < -16 || imm > 15) 
    {
        // Default to zero if out of range
        strcpy(output, "00000"); 
        return;
    }
    //imm is properly represented within a 5-bit range
    //0x1F is 00011111 in binary
    unsigned int value = (imm & 0x1F);
    //imm is 5 numbers, then loop 5 times
    //construct the binary string from most significant bit to least significant bit, so using i--
    for (int i = 4; i >= 0; i--) 
    {
        //conversion from decimal to binary
        if ((value & 1) == 1) 
        {
            output[i] = '1';  
        } 
        else 
        {
            output[i] = '0';  
        }
        //right shifts value by 1 bit  11001
        value >>= 1;
    }
    output[5] = '\0';
}

/*************************************************************************
*function:assembleToBinary
*accept: FILE* input-file, const char* instruction, FILE* output_file
*this function to convert instruction to binary
************************************************************************** */
void assembleToBinary(FILE* output_file, const char* instruction, int line_number) 
{
    // opcode(op[10]),source register(arg1[10]), destination register (arg2[10]), immediate value(arg3[10])
    char op[10], arg1[10]="", arg2[10]="", arg3[10]="";
    sscanf(instruction, "%s %s %s %s", op, arg1, arg2, arg3);
    
    if (strcmp(op, "BR")==0) //only compare first two, "B" and "R"
    {
        //op+2 moves past "BR"
        fprintf(output_file, "0000%s000000000\n", branch(arg1));
    } 
    else if (strcmp(op, "LEA") == 0) 
    {
        fprintf(output_file, "1110%s000000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "LD") == 0) 
    {
        fprintf(output_file, "0010%s000000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "LDR") == 0) 
    {
        fprintf(output_file, "0110%s%s000000\n", registerToBinary(arg1), registerToBinary(arg2));
    } 
    else if (strcmp(op, "STR") == 0) 
    {
        fprintf(output_file, "0111%s%s000000\n", registerToBinary(arg1), registerToBinary(arg2));
    }
    else if (strcmp(op, "ST") == 0) 
    {
        fprintf(output_file, "0011%s000000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "STI") == 0) 
    {
        fprintf(output_file, "1011%s000000000\n", registerToBinary(arg1));
    } 
    //ADD and AND has two way to convert
    else if (strcmp(op, "ADD") == 0 || strcmp(op, "AND") == 0) 
    {
        char opcode[5];
        if (strcmp(op, "ADD") == 0) 
        {
            strcpy(opcode, "0001");  // If operation is ADD, set opcode to "0001"
        } 
        else 
        {
            strcpy(opcode, "0101");  // Otherwise (it must be AND), set opcode to "0101"
        }
        
        if (arg3[0] == 'R') 
        {
            //ADD: 0001 DR SR1 000 SR2
            //AND: 0101 DR SR1 000 SR2
            fprintf(output_file, "%s%s%s000%s\n", opcode, registerToBinary(arg1), registerToBinary(arg2), registerToBinary(arg3));
        } 
        else 
        {
            //ADD: 0001 DR SR1 1 imm5
            //AND: 0101 DR SR1 imm5
            char imm_bin[6];
            immediateToBinary(atoi(arg3), imm_bin);
            fprintf(output_file, "%s%s%s1%s\n", opcode, registerToBinary(arg1), registerToBinary(arg2), imm_bin);
        }
    } 
    else if (strcmp(op, "JMP") == 0) 
    {
        fprintf(output_file, "1100000%s000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "JSR") == 0) 
    {
        fprintf(output_file, "01001%s000000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "JSRR") == 0) 
    {
        fprintf(output_file, "0100000%s000000\n", registerToBinary(arg1));
    } 
    else if (strcmp(op, "NOT") == 0) 
    {
        fprintf(output_file, "1001%s%s111111\n", registerToBinary(arg1), registerToBinary(arg2));
    } 
    else if (strcmp(op, "RET") == 0) 
    {
        fprintf(output_file, "1100000111000000\n");
    } 
    else if (strcmp(op, "TRAP") == 0) 
    {
        //we usually do TRAPx25
        fprintf(output_file, "1111000000100101\n"); 
    } 
    else if(op[0]=='.')
    {
        //if the command is a .FILL, .ORIG, .BLKW or .END we need to convert it to binary
        if(strcmp(op, "FILL")==0)
        {
            int value = atoi(arg1);
            char imm_bin[6];
            immediateToBinary(value, imm_bin);
            fprintf(output_file, "%s\n", imm_bin);
        }
        else if(strcmp(op, "ORIG")==0)
        {
            unsigned int address = strtol(arg1, NULL, 16); 
            for (int i = 15; i >= 0; i--) 
            {
                fprintf(output_file, "%d", (address >> i) & 1);  // Output each bit
            }
            fprintf(output_file, "\n");
            return;  
        }

        else if(strcmp(op, "BLKW")==0)
        {
            int block_size=atoi(arg1);
            for(int i=0; i<block_size; i++)
            {
            fprintf(output_file, "0000000000000000\n");
            }
        }
        else if (strcmp(op, "END")==0)
        {
            return;
        }
    }
    else
    {
        fprintf(output_file, "0000000000000000\n");
    }
fprintf(output_file, ";%s\n", instruction);
}
/***********************************************************
* function:convertAssemblyToBinary
* accept: char* input_filename, char* output_filename
* this function to convert instruction to binary
************************************************************ */
void convertAssemblyToBinary(const char* input_filename, const char* output_filename) 
{
    /********************************************************************
     * Open the input file for reading and output file for writing
     * output file is opened in binary mode
     * input file is opened in text mode
     * ******************************************************************* */
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "wb"); // Open as binary file
    
    if (!input_file || !output_file) 
    {
        printf("Error opening file.\n");
        return;
    }
    
    // 16-bit binary string + null terminator
    char line[MAX_LINE_LENGTH]; 
    // Initialize line number to x3000 for the start of the program in LC-3
    int line_number=0x3000;

    // Read each line from the input file
    // convert it to binary
    while (fgets(line, sizeof(line), input_file)) 
    {
        line[strcspn(line, "\n")] = 0; // remove newline character
        if (line[0] == ';' || strlen(line) == 0) continue; // ignore comments and empty lines
        
        assembleToBinary(output_file, line, line_number);
        line_number++;
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    convertAssemblyToBinary(argv[1], argv[2]);
    printf("Conversion complete. Output saved to %s\n", argv[2]);
    
    return 0;
}