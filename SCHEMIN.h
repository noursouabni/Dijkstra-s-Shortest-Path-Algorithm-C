#ifndef SCHEMIN_H
#define SCHEMIN_H
#define MAX_NODES 1000
typedef enum {false, true} bool;

typedef struct Element{
    int ID;
    char Nom[256];
    int datecreation;
    int population;
    int superficie;
    int nbMunicipalite;
}ELEMENT;

typedef struct structNode {
 ELEMENT info;
 int weight;
 struct structNode* next;
} structNode, *Node;


typedef struct strucGraph {
 int num_nodes;
 Node adjList[MAX_NODES];
} strucGraph, *Graph;

typedef struct {
Node tete;
int lg;
} laStruct,*LISTE;
#endif

