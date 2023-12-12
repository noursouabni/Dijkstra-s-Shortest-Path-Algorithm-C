#include <stdio.h>
#include <stdlib.h>
#include "SCHEMIN.h"
#define gov 5
int main() {
  ELEMENT elem, *esrc, *edest,*s,*d;
  char *token, *src, *dest;
  int i, w;
  Node p;
  char line[512];
  Node newNode;
  Graph graph = createGraph(gov);
  FILE * fp = fopen("Tunisie.txt", "r");

  if (fp == NULL) {
    fprintf(stderr, "Error: cannot open file Tunisie.txt\n");
    exit(EXIT_FAILURE);
  }


  for (i = 0; i < gov; i++) {
    fgets(line, 512, fp);
    token = strtok(line, ",");
    elem.ID = atoi(token);
    token = strtok(NULL, ",");
    strcpy(elem.Nom, token);
    token = strtok(NULL, ",");
    elem.datecreation = atoi(token);
    token = strtok(NULL, ",");
    elem.population = atoi(token);
    token = strtok(NULL, ",");
    elem.superficie = atoi(token);
    token = strtok(NULL, ",");
    elem.nbMunicipalite = atoi(token);
    // Ajout de l'élément à la liste
    newNode = createNode(elem, 0);
    graph -> adjList[elem.ID] = newNode;
  }
  for (i = 0; i < gov; i++) {
    fgets(line, 512, fp);
    src = strtok(line, ",");
    esrc = findElementByName(graph, src);
    token = strtok(NULL, ",");
    while (token != NULL) {
      splitString(token, ':', &dest, &w);
      edest = findElementByName(graph, dest);
      addEdge(graph, esrc, edest, w);
      token = strtok(NULL, ",");
    }
  }
  fclose(fp);
  char str1[50], str2[50];
    printf("**********************************Bienvenue**********************************\n");
  printf("-----------------------------------------------------------------------------\n");
  printf("Ce programme permet de determiner la distance la plus courte entre 2 gouvernorat.\n");
   printf("-----------------------------------------------------------------------------\n");
  printf("Veuillez choisir la Source (Point de depart): \n");
   printf("-----------------------------------------------------------------------------\n");
  scanf("%s", str1);
  printf("-----------------------------------------------------------------------------\n");
  printf("Veuillez maintenant choisir la Destination (arrivee): \n");
   printf("-----------------------------------------------------------------------------\n");
  scanf("%s", str2);
  printf("-----------------------------------------------------------------------------\n");
  s=findElementByName(graph,str1);
  d=findElementByName(graph,str2);
  if (!s||!d){
    printf("Source Ou Destination Fausse!!");
    exit(0);
  }
  shortestPath(graph,s,d);
  printf("-----------------------------------------------------------------------------\n");
  printf("**********************************Au revoir**********************************\n");
}

