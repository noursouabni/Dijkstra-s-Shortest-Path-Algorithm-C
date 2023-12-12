#ifndef FCHEMIN_H
#define FCHEMIN_H
#include "SCHEMIN.h"

Node createNode(ELEMENT e, int weight);
Graph createGraph(int V);
void addEdge(Graph G, ELEMENT src, ELEMENT dest, int weight);
void printGraph(Graph G);
void shortestPath(Graph G, ELEMENT source, ELEMENT dest);
ELEMENT* findElementByName(Graph g, char* name);
void splitString(char* str, char separator, char** outStr, int* outInt);
void printElement(ELEMENT e);
#endif
