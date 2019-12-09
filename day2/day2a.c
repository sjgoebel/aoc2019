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
    //nums[1] = 12;
    //nums[2] = 2;

    int noun = 0;
    int verb = 0;


    while (true)
    {
        /*
        nums[1] = noun;
        nums[2] = verb;
        for (int i = 0; i < pos; i+=4)
        {
            int first = nums[nums[i+1]];
            int second = nums[nums[i+2]];
            int result;
            if (nums[i] == 1)
            {
                result = first + second;
                nums[nums[i+3]] = result;
            }
            else if (nums[i] == 2)
            {
                result = first * second;
                nums[nums[i+3]] = result;
            }
            else if (nums[i] == 99)
            {
                break;
            }
        }
        */

        run_opcodes(nums, noun, verb, pos);

        if (nums[0] == 19690720) break;
        else
        {
            noun++;
            if (noun == 100)
            {
                verb++;
                noun = 0;
            }
            for (int i = 0; i < pos; i++)
            {
                nums[i] = orig_nums[i];
            }
        }
    }
    /*
    for (int i = 0; i < pos; i++)
    {
        printf("%i ", nums[i]);
    }
    */
    int result = 100 * noun + verb;
    printf("noun: %i verb: %i result: %i\n", noun, verb, result);

    //printf("%s\n", input);
}

int run_opcodes(int opcodes[], int noun, int verb, int length)
{
    opcodes[1] = noun;
    opcodes[2] = verb;

    int pos = length;

    for (int i = 0; i < pos; i+=4)
    {
        int first = opcodes[opcodes[i+1]];
        int second = opcodes[opcodes[i+2]];

        int result;

        if (opcodes[i] == 1)
        {
            result = first + second;
            opcodes[opcodes[i+3]] = result;
        }
        else if (opcodes[i] == 2)
        {
            result = first * second;
            opcodes[opcodes[i+3]] = result;
        }
        else if (opcodes[i] == 99)
        {
            break;
        }
    }

    return opcodes[0];
}

