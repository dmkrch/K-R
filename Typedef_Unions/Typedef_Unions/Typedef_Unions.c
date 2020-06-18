#include <iostream>
#include <string>
#include <malloc.h>


union code
{
    int digit;
    char letter;
};

typedef int Int;
typedef char* String;
typedef int (*strActions)(char*, char*);

typedef struct Node
{
    Node* next;
    Int data;
    String message;
} TreeNode;


int main()
{
    /* UNIONS */
    union code id;

    id.digit = 120;
    printf("%d - %c \n", id.digit, id.letter);  // 120 - x
    printf("%d - %d \n", id.digit, id.letter);  // 120 - 120

    id.letter = 87;
    printf("%d - %c \n", id.digit, id.letter);  // 87 - W



    /* TYPEDEF */
    Int a = 5;
    Int b = 7;
    printf("%d", a + b); // 12

    char arr[] = "how are u";
    String str = arr;
    printf("%s", str);

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
}