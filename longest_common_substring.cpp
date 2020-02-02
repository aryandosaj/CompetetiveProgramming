// A C program to implement Ukkonen's Suffix Tree Construction
// Here we build generalized suffix tree for two strings
// And then we find longest common substring of the two input strings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR 256
#include <bits/stdc++.h>
using namespace std;
struct SuffixTreeNode
{
    struct SuffixTreeNode *children[MAX_CHAR];

    //pointer to other node via suffix link
    struct SuffixTreeNode *suffixLink;

    /*(start, end) interval specifies the edge, by which the 
     node is connected to its parent node. Each edge will 
     connect two nodes,  one parent and one child, and 
     (start, end) interval of a given edge  will be stored 
     in the child node. Lets say there are two nods A and B 
     connected by an edge with indices (5, 8) then this 
     indices (5, 8) will be stored in node B. */
    int start;
    int *end;

    /*for leaf nodes, it stores the index of suffix for 
      the path  from root to leaf*/
    int suffixIndex;
};

typedef struct SuffixTreeNode Node;

char text[100];    //Input string
Node *root = NULL; //Pointer to root node

/*lastNewNode will point to newly created internal node, 
  waiting for it's suffix link to be set, which might get 
  a new suffix link (other than root) in next extension of 
  same phase. lastNewNode will be set to NULL when last 
  newly created internal node (if there is any) got it's 
  suffix link reset to new internal node created in next 
  extension of same phase. */
Node *lastNewNode = NULL;
Node *activeNode = NULL;

/*activeEdge is represeted as input string character 
  index (not the character itself)*/
int activeEdge = -1;
int activeLength = 0;

// remainingSuffixCount tells how many suffixes yet to
// be added in tree
int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1; //Length of input string
int size1 = 0; //Size of 1st string

Node *newNode(int start, int *end)
{
    Node *node = (Node *)malloc(sizeof(Node));
    int i;
    for (i = 0; i < MAX_CHAR; i++)
        node->children[i] = NULL;


    node->suffixLink = root;
    node->start = start;
    node->end = end;


    node->suffixIndex = -1;
    return node;
}

int edgeLength(Node *n)
{
    if (n == root)
        return 0;
    return *(n->end) - (n->start) + 1;
}

int walkDown(Node *currNode)
{
    if (activeLength >= edgeLength(currNode))
    {
        activeEdge += edgeLength(currNode);
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}

void extendSuffixTree(int pos)
{

    leafEnd = pos;


    remainingSuffixCount++;


    lastNewNode = NULL;

    while (remainingSuffixCount > 0)
    {

        if (activeLength == 0)
            activeEdge = pos; //APCFALZ

 
        if (activeNode->children] == NULL)
        {
            activeNode->children] = 
                                          newNode(pos, &leafEnd);

            if (lastNewNode != NULL)
            {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = NULL;
            }
        }

        else
        {

            Node *next = activeNode->children];
            if (walkDown(next)) //Do walkdown
            {
                continue;
            }

            if (text[next->start + activeLength] == text[pos])
            {

                if (lastNewNode != NULL && activeNode != root)
                {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = NULL;
                }

                activeLength++;

                break;
            }

            splitEnd = (int *)malloc(sizeof(int));
            *splitEnd = next->start + activeLength - 1;

            Node *split = newNode(next->start, splitEnd);
            activeNode->children] = split;

            split->children] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children] = next;
            if (lastNewNode != NULL)
            {
                lastNewNode->suffixLink = split;
            }
            lastNewNode = split;
        }
        remainingSuffixCount--;
        if (activeNode == root && activeLength > 0) //APCFER2C1
        {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        }
        else if (activeNode != root) //APCFER2C2
        {
            activeNode = activeNode->suffixLink;
        }
    }
}

void print(int i, int j)
{
    int k;
    for (k = i; k <= j && text[k] != '#'; k++)
        printf("%c", text[k]);
    if (k <= j)
        printf("#");
}
void setSuffixIndexByDFS(Node *n, int labelHeight)
{
    if (n == NULL)
        return;
    int leaf = 1;
    int i;
    for (i = 0; i < MAX_CHAR; i++)
    {
        if (n->children[i] != NULL)
        {

            leaf = 0;
            setSuffixIndexByDFS(n->children[i], labelHeight +
                                                    edgeLength(n->children[i]));
        }
    }
    if (leaf == 1)
    {
        for (i = n->start; i <= *(n->end); i++)
        {
            if (text[i] == '#')
            {
                n->end = (int *)malloc(sizeof(int));
                *(n->end) = i;
            }
        }
        n->suffixIndex = size - labelHeight;
    }
}
void buildSuffixTree()
{
    size = strlen(text);
    int i;
    rootEnd = (int *)malloc(sizeof(int));
    *rootEnd = -1;

    /*Root is a special node with start and end indices as -1, 
    as it has no parent from where an edge comes to root*/
    root = newNode(-1, rootEnd);

    activeNode = root; //First activeNode will be root
    for (i = 0; i < size; i++)
        extendSuffixTree(i);
    int labelHeight = 0;
    setSuffixIndexByDFS(root, labelHeight);
}

int doTraversal(Node *n, int labelHeight, int *maxHeight,
                int *substringStartIndex)
{
    if (n == NULL)
    {
        return;
    }
    int i = 0;
    int ret = -1;
    if (n->suffixIndex < 0) //If it is internal node
    {
        for (i = 0; i < MAX_CHAR; i++)
        {
            if (n->children[i] != NULL)
            {
                ret = doTraversal(n->children[i], labelHeight + edgeLength(n->children[i]),
                                  maxHeight, substringStartIndex);

                if (n->suffixIndex == -1)
                    n->suffixIndex = ret;
                else if ((n->suffixIndex == -2 && ret == -3) ||
                         (n->suffixIndex == -3 && ret == -2) ||
                         n->suffixIndex == -4)
                {
                    n->suffixIndex = -4; //Mark node as XY
                    //Keep track of deepest node
                    if (*maxHeight < labelHeight)
                    {
                        *maxHeight = labelHeight;
                        *substringStartIndex = *(n->end) -
                                               labelHeight + 1;
                    }
                }
            }
        }
    }
    else if (n->suffixIndex > -1 && n->suffixIndex < size1) //suffix of X
        return -2;                                          //Mark node as X
    else if (n->suffixIndex >= size1)                       //suffix of Y
        return -3;                                          //Mark node as Y
    return n->suffixIndex;
}

void getLongestCommonSubstring()
{
    int maxHeight = 0;
    int substringStartIndex = 0;
    doTraversal(root, 0, &maxHeight, &substringStartIndex);

    int k;
    for (k = 0; k < maxHeight; k++)
        printf("%c", text[k + substringStartIndex]);
    if (k == 0)
        printf("No common substring");
    else
        printf(", of length: %d", maxHeight);
    printf("\n");
}
int main(int argc, char *argv[])
{
    size1 = 7;
    printf("Longest Common Substring in xabxac and abcabxabcd is: ");
    strcpy(text, "xabxac#abcabxabcd$");
    buildSuffixTree();
    getLongestCommonSubstring();

    return 0;
}