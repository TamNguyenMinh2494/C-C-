#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#define MAX 20  

#define initial 1
#define visited 2 

void InputFromFile(int G[][MAX], int &n);
void graph_traversal();
void DFS(int vertex);
void push(int vertex);
int pop();
int isEmpty();

int stack[MAX];
int top = -1;
int vertices;
int adjacent_matrix[MAX][MAX];
int vertex_status[MAX];

void main()
{
	InputFromFile(adjacent_matrix, vertices);
	graph_traversal();
	_getch();
}

void InputFromFile(int G[][MAX], int &n)
{

	int i, j;
	FILE *f = fopen("data.txt", "rt");
	fscanf(f, "%d", &n);

	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			fscanf(f, "%d", &G[i][j]);

	fclose(f);
}


void graph_traversal()
{
	int vertex;
	for (vertex = 0; vertex < vertices; vertex++)
	{
		vertex_status[vertex] = initial;
	}
	printf("Enter Starting Vertex for DFS:\t");
	scanf("%d", &vertex);
	DFS(vertex);
	printf("\n");
}

void DFS(int vertex)
{
	int count;
	push(vertex);
	while (!isEmpty())
	{
		vertex = pop();
		if (vertex_status[vertex] == initial)
		{
			printf("%3d", vertex);
			vertex_status[vertex] = visited;
		}
		for (count = vertices - 1; count >= 0; count--)
		{
			if (adjacent_matrix[vertex][count] >= 1 && vertex_status[count] == initial)
			{
				push(count);
			}
		}
	}
}

void push(int vertex)
{
	if (top == (MAX - 1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top + 1;
	stack[top] = vertex;
}

int pop()
{
	int vertex;
	if (top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	else
	{
		vertex = stack[top];
		top = top - 1;
		return vertex;
	}
}

int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}