#include "GraphTraversal.h"

void DFS(Vertex* V){
	Edge* E = NULL;
	
	printf("%d ", V->Data);
	V->Visited = Visited;
	E = V->AdjacencyList;
	
	while (E != NULL){
		if (E->Target != NULL && E->Target->Visited == NotVisited)
			DFS (E->Target);
		E = E->Next;
	}
}

void BFS(Vertex* V, LinkedQueue* Queue){
	printf("%d ", V->Data);
	LQ_Enqueue(Queue, LQ_CreateNode(V));
	V->Visited = Visited;
	
	while (!LQ_IsEmpty(Queue)){
		Node* Popped = LQ_Dequeue(Queue);
		V = Popped->Data;
		Edge* E = V->AdjacencyList;
		
		while (E != NULL){
			if (E->Target != NULL && E->Target->Visited == NotVisited){
				printf("%d ", E->Target->Data);
				LQ_Enqueue(Queue, LQ_CreateNode(E->Target));
				E->Target->Visited = Visited;
			}
			
			E = E->Next;
		}
	}
}
