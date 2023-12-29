#include "ShortestPath.h"

void Daijkstra(Graph* G, Vertex* StartVertex, Graph* ShortestPath){
	PQNode StartNode = {0, StartVertex};
	
	PriorityQueue* PQ = PQ_Create(10);
	
	int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
	Vertex** ShortestPathVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	int* Fringes = (int*)malloc(sizeof(int) * G->VertexCount);
	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	
	
	Vertex* CurrentVertex = G->Vertices;
	while (CurrentVertex != NULL){
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(ShortestPath, NewVertex);
		
		Weights[CurrentVertex->Index] = MAX_WEIGHT;
		Fringes[CurrentVertex->Index] = 0;
		ShortestPathVertices[CurrentVertex->Index] = NewVertex;
		Precedences[CurrentVertex->Index] = NULL;
		
		CurrentVertex = CurrentVertex->Next;
	}
	
	PQ_Enqueue(PQ, StartNode);
	
	Weights[StartVertex->Index] = 0;
	
	while (!PQ_IsEmpty(PQ)){
		PQNode Popped;
		
		PQ_Dequeue(PQ, &Popped);
		CurrentVertex = (Vertex*)Popped.Data;
		
		Fringes[CurrentVertex->Index] = 1;
		
		Edge* CurrentEdge = CurrentVertex->AdjacencyList;
		while (CurrentEdge != NULL){
			int isAddQueue = Fringes[CurrentEdge->Target->Index] == 0 
							&& Weights[CurrentVertex->Index] + CurrentEdge->Weight < Weights[CurrentEdge->Target->Index];
								
			if (isAddQueue){
				PQNode NewNode = {CurrentEdge->Weight, CurrentEdge->Target};
				PQ_Enqueue(PQ, NewNode);
				Weights[CurrentEdge->Target->Index] = CurrentEdge->Weight + Weights[CurrentVertex->Index];
				Precedences[CurrentEdge->Target->Index] = CurrentEdge->From;
			}
			CurrentEdge = CurrentEdge->Next;
		}
		
		for (int i = 0; i < G->VertexCount; i++){
			if (Precedences[i] == NULL)
				continue;
			
			int fromIndex = Precedences[i]->Index;
			
			AddEdge(ShortestPathVertices[fromIndex], 
					CreateEdge(ShortestPathVertices[fromIndex], ShortestPathVertices[i], Weights[i]));
		}
	}
}
