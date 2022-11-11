#include "tree.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    address a = CreateNode(1);
    address b = CreateNode(2);
    address c = CreateNode(3);
    address d = CreateNode(4);


    printf("Pass\n");
    
    AssignBranch(&a, &b);
    AssignBranch(&a, &c);

    setTreeElmt(&a, 3);

    PrintTree(a);

    DeleteNode(&a);
    //akhir program
    printf("\nCompile Success!\n");
    scanf("%d", &confirmDone);
    return 0;
}