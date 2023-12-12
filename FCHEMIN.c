#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <limits.h>

#include "FCHEMIN.H"

#define MAX_NODES 1000

Node createNode(ELEMENT e, int weight) {
  Node newNode = (Node) malloc(sizeof(structNode));
  newNode -> info = e;
  newNode -> weight = weight;
  newNode -> next = NULL;
  return newNode;
}

Graph createGraph(int V) {
  Graph newGraph = (Graph) malloc(sizeof(strucGraph));
  newGraph -> num_nodes = V;
  for (int i = 0; i < V; i++) {
    newGraph -> adjList[i] = NULL;
  }
  return newGraph;
}

void addEdge(Graph G, ELEMENT src, ELEMENT dest, int weight) {
  Node newNode = createNode(dest, weight);


  Node current = G -> adjList[src.ID];
  if (current == NULL) {

    G -> adjList[src.ID] = current;
  } else {
    while (current -> next != NULL) {
      current = current -> next;
    }

    current -> next = newNode;
  }
}


void printGraph(Graph G) {
  for (int i = 0; i < G -> num_nodes; i++) {
    printf("%d: ", i);
    Node node = G -> adjList[i];
    while (node != NULL) {
      printf("(%s, %d) ", node -> info.Nom, node -> weight);
      node = node -> next;
    }
    printf("\n");
  }
}

void shortestPath(Graph G, ELEMENT source, ELEMENT dest) {
  int dist[G -> num_nodes]; // Tableau de distances
  bool visited[G -> num_nodes]; // Tableau de visites
  int parent[G -> num_nodes]; // Tableau de parents

  // Initialisation des tableaux
  for (int i = 0; i < G -> num_nodes; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
    parent[i] = -1;
  }
  // Définir la distance du nœud source à 0
  int srcIndex = source.ID;
  dist[srcIndex] = 0;


  for (int i = 0; i < G -> num_nodes - 1; i++) {
    // Trouver le nœud non visité avec la plus petite distance à partir du nœud source
    int minDist = INT_MAX, minIndex;
    for (int j = 0; j < G -> num_nodes; j++) {
      if (!visited[j] && dist[j] < minDist) {
        minDist = dist[j];
        minIndex = j;
      }
    }

    // Marquer le nœud comme visité
    visited[minIndex] = true;

    // Parcourir tous les nœuds adjacents non visités et mettre à jour les distances et les parents
    Node curr = G -> adjList[minIndex];
    while (curr != NULL) {
      int currIndex = curr->info.ID;
      int altDist = dist[minIndex] + curr -> weight;
      if (!visited[currIndex] && altDist < dist[currIndex]) {
        dist[currIndex] = altDist;
        parent[currIndex] = minIndex;
      }
      curr = curr -> next;
    }
  }
  // Afficher le chemin le plus court
  printf("Chemin le plus court de %s a %s : ", source.Nom, dest.Nom);
  printPath(G, parent, dest.ID);
  printf("\n");
}

void printPath(Graph G, int parent[], int i) {
  if (i == -1) {
    return;
  }
    printPath(G, parent, parent[i]);
    printf("%s ", G -> adjList[i] -> info.Nom);

}

ELEMENT* findElementByName(Graph g, char* name) {
    int i;
    Node currentNode;
    ELEMENT* currentElement;
    for (i = 0; i < g->num_nodes; i++) {
        currentNode = g->adjList[i];
        while (currentNode != NULL) {
            currentElement = &currentNode->info;
            if (strcmp(currentElement->Nom, name) == 0) {
                return currentElement;
            }
            currentNode = currentNode->next;
        }
    }
    return NULL;
}

void splitString(char* str, char separator, char** outStr, int* outInt) {
      char* p = strchr(str, separator);
    if (p != NULL) {

        *p = '\0';
        *outStr = str;
        *outInt = atoi(p + 1);
    } else {

        *outStr = str;
        *outInt = 0;
    }
}
void printElement(ELEMENT e) {
    printf("ID: %d\n", e.ID);
    printf("Nom: %s\n", e.Nom);
    printf("Date de création: %d\n", e.datecreation);
    printf("Population: %d\n", e.population);
    printf("Superficie: %d\n", e.superficie);
    printf("Nombre de municipalités: %d\n", e.nbMunicipalite);
}
