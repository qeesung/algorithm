/*************************************************
* @Filename:    c_stack_test.c
* @Author:      qeesung
* @Email:       qeesung@qq.com
* @DateTime:    2015-05-27 13:20:59
* @Version:     1.0
* @Description: ≤‚ ‘c”Ô—‘ µœ÷µƒ’ª
**************************************************/
#include "c_stack.h"
#include "c_stack_int.h"
#include <stdio.h>
#include <stdbool.h>


int main(int argc, char const *argv[])
{
    Stack myStack = createStack();
    int tempData;
    if(myStack == NULL)
    {
        fprintf(stderr, "%s\n", "create stack failed" );
        return -1;
    }
    /** test push */
    fprintf(stderr, "%s\n","test push -------------------------------------------" );
    if(push_intStack(myStack , 10))
        fprintf(stderr, "%s %d\n", "pushed" , 10);
    else
        fprintf(stderr, "%s %d\n", "failed to push" , 10);

    if(push_intStack(myStack , 11))
        fprintf(stderr, "%s %d\n", "pushed" , 11);
    else
        fprintf(stderr, "%s %d\n", "failed to push" , 11);
    print_intStack(myStack);
    fprintf(stderr, "%s\n\n","test push -------------------------------------------" );
    /** test top */
    fprintf(stderr, "%s\n","test top -------------------------------------------" );
    if(topValue_intStack(myStack, &tempData))
        fprintf(stderr, "top data is %d\n", tempData);
    else 
        fprintf(stderr, "%s\n", "get top data failed");
    print_intStack(myStack);
    fprintf(stderr, "%s\n\n","test top -------------------------------------------" );
    fprintf(stderr, "%s\n","test pop -------------------------------------------" );
    /** test pop */
    if(pop_intStack(myStack , &tempData))
        fprintf(stderr, "%s %d\n", "get pop number",tempData );
    else
        fprintf(stderr, "%s\n","pop failed" );
    if(pop_intStack(myStack , &tempData))
        fprintf(stderr, "%s %d\n", "get pop number",tempData );
    else
        fprintf(stderr, "%s\n","pop failed" );
    if(pop_intStack(myStack , &tempData))
        fprintf(stderr, "%s %d\n", "get pop number",tempData );
    else
        fprintf(stderr, "%s\n","pop failed" );
    print_intStack(myStack);
    fprintf(stderr, "%s\n\n","test pop -------------------------------------------" );
    fprintf(stderr, "%s\n","test all -------------------------------------------" );
    /** test push pop top*/
    if(push_intStack(myStack , 12))
        fprintf(stderr, "%s %d\n", "pushed" , 12);
    else
        fprintf(stderr, "%s %d\n", "failed to push" , 12);

    if(topValue_intStack(myStack, &tempData))
        fprintf(stderr, "top data is %d\n", tempData);
    else 
        fprintf(stderr, "%s\n", "get top data failed");

    if(pop_intStack(myStack , &tempData))
        fprintf(stderr, "%s %d\n", "get pop number",tempData );
    else
        fprintf(stderr, "%s\n","pop failed" );

    if(pop_intStack(myStack , &tempData))
        fprintf(stderr, "%s %d\n", "get pop number",tempData );
    else
        fprintf(stderr, "%s\n","pop failed" );
    print_intStack(myStack);
    fprintf(stderr, "%s\n","test all -------------------------------------------" );
    return 0;
}

