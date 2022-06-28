#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#define SIZE 1400000// Max vertex input
#include <time.h>

//Code STACK
struct Stack
{
  int top;
  unsigned capacity;
  int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
  return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty1(struct Stack* stack)
{
  return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
  if (isFull(stack))
      return;
  stack->array[++stack->top] = item;
    //printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty1(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty1(stack))
        return INT_MIN;
    return stack->array[stack->top];
}


struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);


//CODE QUEUE
struct queue
{
  int items[SIZE];
  int front;
  int rear;
};
// Create a queue
struct queue* createQueue()
{
  struct queue* q =(queue *) malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value)
{

  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else
  {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q)
{
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty");
    item = -1;
  } 
  else
  {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q)
{

  int i = q->front;

  if (isEmpty(q))
  {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++)
    {
      printf("%d ", q->items[i]);
    }
  }
}


// CODE NODE
struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int numEdge;
    int* visited;
    struct node** adjLists; 
};

struct Graph* createGraph(FILE *f);
void Addedge(struct Graph*, int, int);
void printGraph(struct Graph*);
void BFS(struct Graph*, int);
void DFS(struct Graph*, int);

struct node* createNode(int v)
{
    struct node* newNode =(node *) malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(FILE *f)
{
  char arr[80];
  for(int i = 0; i < 4; i++)
  {
    fgets(arr, 80, f);
  }
    printf("Loading file...");
    struct Graph* graph =(Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = SIZE;
    graph->adjLists =(node**) malloc(SIZE * sizeof(struct node*));
    graph->visited = (int*)malloc(SIZE * sizeof(int));
    int i;
    for (i = 0; i < SIZE; i++)
    {
      graph->adjLists[i] = NULL;
      graph->visited[i] = 0;
    }
    return graph;
}

void Addedge(struct Graph* graph, int src, int dest)
{
  struct node* newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
           if(temp!=NULL){
		    printf("\n Adjacency list of vertex %d\n ", v);
	      } 
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
    }
}

// DFS algorithm
void DFS(struct Graph* graph, int startvertex)
{
	struct Stack* s=createStack(SIZE);
	push(s,startvertex);
	while (!isEmpty1(s))
	{
		int startvertex = peek(s);
		pop(s);
		if (graph->visited[startvertex]==0)
    {
      printf(" %d->", startvertex);
      graph->visited[startvertex] = 1;
    }
    struct node* temp = graph->adjLists[startvertex];
    while (temp)
    {
      int adjVertex = temp->vertex;
      if (graph->visited[adjVertex]==0) push(s,adjVertex);
      temp = temp->next;
    }
	}
}

// BFS algorithm
void BFS(struct Graph* graph, int startVertex)
{
  struct queue* q = createQueue();
  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) 
  {
    int currentVertex = dequeue(q);
    printf("%d ->", currentVertex);

    struct node* temp = graph->adjLists[currentVertex];

    while (temp)
    {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0)
      {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}
// Clear Visit
void Clear_visited(Graph* graph)
{
  for(int i = 0 ; i < graph->numVertices; i++)
  {
    graph->visited[i] = 0;
  }
}
void NumberOfConnectedComponents()
{
  printf("\nChua xong!");
}
int main()
{    
	clock_t batdau,end;
    int src,des,chon,start;
    char fname[20];
    printf("****** PROJECT I - 20212******\n\n");
    printf("-----------------------------------\n");
    printf("Setup Max Process: 20193245 Vertex!\n");
    printf("SV:Tran Duc Cuong - MSSV: 20193245\n");
    printf("GVHD: TS.Trinh Anh Phuc\n");
    printf("-----------------------------------\n");
    printf("Moi ban nhap ten tap input: ");
    scanf("%s",fname);
    FILE *f = fopen(fname,"r");
    if(f == NULL)
    {
      printf("%s file not open!\n", fname);
      return -1;
    }
    struct Graph* graph = createGraph(f);
    int checkEdge=0;
    while(fscanf(f,"%d %d",&src, &des)!=EOF)
    {
    	Addedge(graph, src,des);
    	checkEdge++;
    }
	graph->numEdge = (checkEdge)/2;
    printf("\nQua trinh doc file va tao do thi hoan tat!\n");
    fclose(f);
	//MENU
	do
  {
	  printf("\nMENU:\n");
	  printf("Nhap 1. De in ra do thi vua tao\n");
    printf("Nhan 2. De hien ket qua duyet BFS\n");
    printf("Nhan 3. De hien ket qua duyet DFS\n");
    printf("Nhan 4. De dem so thanh phan lien thong\n");
    printf("Nhan 0. Thoat \n");
    printf("Moi ban chon menu: ");
    scanf("%d",&chon);
    switch(chon)
    {
			case 1: 
			  printf("Do thi ban vua nhap la:");
			  printGraph(graph);
			break;
			case 2: 
				printf("Nhap dinh xuat phat theo BFS:");
				scanf("%d",&start);
				batdau=clock();
				Clear_visited(graph);	
		        BFS(graph,start);
		        end=clock();
		        int time_use;
		        time_use=(int)(end-batdau)/CLOCKS_PER_SEC;
		        printf("Thoi gian chay %d",time_use);
			break;
			case 3: 
				printf("Nhap dinh xuat phat theo DFS:");
				scanf("%d",&start);
				Clear_visited(graph);	
		        DFS(graph,start);
			break;
      case 4:
        printf("\nSo thanh phan lien thong la:");
        NumberOfConnectedComponents();
			default:
				printf("Ket thuc chuong trinh");
			break;
		}
		
		printf("\nBan co muon tiep tuc khong? (Nhap y/n)");
		char c;
		fflush(stdin);
		scanf("%c", &c);
		if(c == 'y')
    {
			chon = -1; 
		}else
    {
			printf("Tam biet!");
      break;
		}
	} while(chon != 1 && chon != 2 && chon !=3 && chon!=0);
	
    return 0;
}

