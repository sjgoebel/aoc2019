#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int run_opcodes(int opcodes[], int noun, int verb, int length);

int main(int argc, string argv[])
{
    string input = get_string("");
    string delim = ",";
    int nums[300];
    int pos = 0;

    char *ptr = strtok(input, delim);

    while (ptr != NULL)
    {
        //printf("%s\n", ptr);
        nums[pos] = atoi(ptr);
        pos++;
        ptr = strtok(NULL, delim);
    }

    int orig_nums[pos];
    for (int i = 0; i < pos; i++)
    {
        orig_nums[i] = nums[i];
    }

    printf("%i\n", run_opcodes(nums, 100, -1, 5));


}

int run_opcodes(int opcodes[], int noun, int verb, int length)
{
    opcodes[1] = noun;
    opcodes[2] = verb;

    int step = 0;

    int pos = length;

    for (int i = 0; i < pos; i+= step)
    {
        bool quit_loop = false;


        int result;

        int opcode = opcodes[i] % 100;
        int modes = opcodes[i] / 100;
        int first_mode = modes / 10;
        int second_mode = modes % 10;
        int first;
        int second;

        if (modes > 0)
        {
            if (first_mode == 0)
            {
                first = opcodes[opcodes[i + 1]];
            }
            else
            {
                first = opcodes[i + 1];
            }
            if (second_mode == 0)
            {
                second = opcodes[opcodes[i + 2]];
            }
            else
            {
                second = opcodes[i + 2];
            }
        }

        switch(opcode)
        {
            case 1:
                result = first + second;
                opcodes[opcodes[i+3]] = result;
                step = 4;
                break;
            case 2:
                result = first * second;
                opcodes[opcodes[i+3]] = result;
                step = 4;
                break;
            case 3:
                opcodes[opcodes[i+1]] = opcodes[i+1];
                step = 2;
                break;
            case 4:
                opcodes[0] = opcodes[i+1];
                quit_loop = true;
                break;
            case 99:
                quit_loop = true;
                break;
        }
        if (quit_loop) break;

        /*
        if (opcodes[i] == 1)
        {
            result = first + second;
            opcodes[opcodes[i+3]] = result;
            step = 4;
        }
        else if (opcodes[i] == 2)
        {
            result = first * second;
            opcodes[opcodes[i+3]] = result;
            step = 4;
        }
        else if (opcodes[i] == 99)
        {
            break;
        }
        */
    }

    return opcodes[0];
}