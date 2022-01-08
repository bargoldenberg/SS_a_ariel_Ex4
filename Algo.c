#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Keep the pointer yo the hea of the array
char input;

char inputBack(){
    return input;
}


int toInt(char num)
{
    int ans = num-48;
    return ans; 
}

void build_graph_cmd(pnode *head)
{
    int size, id, index, weight, to = 0; 

    scanf("%d",&size);
    *head = (node*)malloc(sizeof(node)*size);
    printf("size = %d\n",size);
    while(index<size)
    {
        printf("index = %d\n",index);
        (*head+index) -> node_num = index;
        index += 1;
    }
    printf("check @@@ Need to rnter char here!!\n");
    scanf("%c",&input);
    printf("this.input = %c\n",input);
    while(input == 'n'){
        printf("   Got in while loop:\n");
        scanf("%d",&id);
        scanf("%c",&input);
        index = 0;
        pedge ptrE;
        while(input >= 48 && input <= 57)
        {
            printf("one more edge___\n");
            to = toInt(input);
            scanf("%d",&weight);
            edge e = {.weight=weight, .endpoint=to};
            // (ptrE + index) = &e;
            scanf("%c",&input);
        }
        (*head+id) -> edges = ptrE;
    }
}


void insert_node_cmd(pnode *head)
{
    
}


//For Debug!!
void printGraph_cmd(pnode head)
{
    int index=0;
    int size = 4;
    while(index <size)
    {
        printf("index = %d,addres = %p, node_num = %d\n",index,*(head+index), (head+index) -> node_num);
        index += 1;
    }
}








int main(){
    node graph;
    pnode pGraph = &graph;
    char Input = NULL;
    while( scanf("%c",&Input) != EOF)
    {
        if(Input == 'A'){
            build_graph_cmd(pGraph);
            printGraph_cmd(pGraph);
            Input = inputBack();
            printf("Back to A\n");
        }
        else if(Input == 'B'){

        }
        else if(Input == 'D'){}
        else if(Input == 'S'){}
        else if(Input == 'T'){}

    }

}






// int main()
// {
//     node graph;
//     pnode pGraph = &graph;

//     char Input = NULL;
//     while(scanf("%c",&Input) != EOF)
//     {
//         if(Input == 'A')
//         {
//             int id,to,weight;
//             build_graph_cmd(pGraph);
//             printGraph_cmd(pGraph);
//             scanf("%c",&Input);
//             while(Input == 'n')
//             {
//                 scanf("%d",&id);
//                 scanf("%c",&Input);
//                 while(Input >= 48 && Input <= 57)
//                 {
//                     to = toInt(Input);
//                     scanf("%c",&Input);
//                     weight = toInt(Input);
//                     scanf("%c",&Input);

                    
//                 }
//             }
//         }
//     }
// }


// int main()
// {

//     node n;
//     pnode ptr;
//     printf("Hello!\n");
//     ptr = &n;
//     build_graph_cmd(ptr);
//     printGraph_cmd(ptr);

// }

