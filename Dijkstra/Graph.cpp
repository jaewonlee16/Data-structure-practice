#include "Graph.h"

Graph* CreateGraph(){
	Graph* newGraph = (Graph*)malloc(sizeof(Graph));
	
	newGraph->Vertices = NULL;
	newGraph->VertexCount = 0;
	
	return newGraph;
}

void DestroyGraph (Graph* G){
	while (G->Vertices != NULL){
		Vertex* nextVertex = G->Vertices->Next;
		DestroyVertex (G->Vertices);
		
		G->Vertices = nextVertex;
	}
	
	free(G);
}


Vertex* CreateVertex (ElementType Data){
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
	
	newVertex->Data = Data;
	newVertex->AdjacencyList = NULL;
	newVertex->Next = NULL;
	newVertex->Index = -1;
	newVertex->Visited = NotVisited;
	
	return newVertex;
}

void DestroyVertex (Vertex* V){
	while (V->AdjacencyList != NULL){
		Edge* nextEdge = V->AdjacencyList->Next;
		DestroyEdge(V->AdjacencyList);
		V->AdjacencyList = nextEdge;
	}
	
	free(V);
}


Edge* CreateEdge (Vertex* From, Vertex* Target, int Weight){
	Edge* newEdge = (Edge*)malloc(sizeof(Edge));
	
	newEdge->From = From;
	newEdge->Target = Target;
	newEdge->Weight = Weight;
	newEdge->Next = NULL;
	
	return newEdge;
}

void DestroyEdge (Edge* E){
	free(E);
}


void AddVertex (Graph* G, Vertex* V){
	Vertex* VertexList = G->Vertices;
	if (G->Vertices == NULL)
		G->Vertices = V;
	else{
		while (VertexList->Next != NULL){
			VertexList = VertexList->Next;
		}
		VertexList->Next = V;
	}
	
	V->Index = G->VertexCount++;
}

void AddEdge (Vertex* V, Edge* E){
	if (V->AdjacencyList == NULL)
		V->AdjacencyList = E;
	else{
		Edge* AdjacencyList = V->AdjacencyList;
		while (AdjacencyList->Next != NULL){
			AdjacencyList = AdjacencyList->Next;
		}
		AdjacencyList->Next = E;
	}
}

void PrintGraph (Graph* G){
	Vertex* V = G->Vertices;
	
	if (V == NULL)
		return;
	
	while (V != NULL){
		printf("%c: ", V->Data);
		
		Edge* E = V->AdjacencyList;
		if (E == NULL){
			V = V->Next;
			printf("\n");
			continue;
		}
		
		while (E != NULL){
			printf("%c[%d] ", E->Target->Data, E->Weight);
			E = E->Next;
		}
		
		V = V->Next;
		printf("\n");
	}
}
