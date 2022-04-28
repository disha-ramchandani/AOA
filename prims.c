#include "stdio.h"
#include "stdlib.h"
#define INF 9999
int V,E=0,cnt=0;
int G[10][10];
int pi[10],key[10];
int priority[10], queue[10],visited[10]; 
/*to implement priority queue, priority array will hold keys and queue array will hold vertices in Q.*/
int startvertex;
int totalcost = 0;
void readGraph()
{
  printf("\nEnter adjacenc matrix \n");
  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      scanf("%d",&G[i][j]);
      if(G[i][j] !=0)
        E++;
    }
  }
}

void displaygraph()
{
  printf("\nGraph is... \n");
  for(int i = 0; i < V; i++)
  {
    for(int j = 0; j < V; j++)
    {
      printf("%d\t",G[i][j]);
    }
    printf("\n");
  }
}

void initialize()
{
  for(int i = 0;i < V; i++)
  {
    
    key[i] = INF;
    pi[i] = -1;
  }
}

void print1Darray(char *str,int a[])
{
  printf("\n%s [] : ",str);
  
  for(int i = 0;i < V; i++)
  {
    printf("\t%d",a[i]);
  }
}

void print_key_pi() //to display key array and pi array
{
  
  print1Darray("KEY array",key);
  print1Darray("PI array",pi); 
}

void print_priority_Queue() //to display priority array and queue array
{
  
  printf("\nQueue array");
  for(int i = 0;i <= V-1; i++)
  {
    printf("\t%d",queue[i]);
  }
  printf("\nPriority array");
  for(int i = 0;i <= V-1; i++)
  {
    printf("\t%d",priority[i]);
  }
}

void createQueue() //inserting in priority queue
{
    for (int i=0; i<V; i++)
    {
        queue[i] = i;
        priority[i] = key[i];
        visited[i]=0;        
    }
    print_priority_Queue();
}
int Extract_Min()
{
    int min = priority[0];
    int pos = 0;
    
    for(int i=1;i<=V-1;i++)
    {
        if(visited[i]==0 && min>priority[i])
        {
            min = priority[i];
            pos = i; 
        }
    }
    return pos;
}

int check(int v)
{
    
        if(visited[v]==0)
            return 1;
        else return 0;
}

void edgesinMST()
{
  printf("\n \nEdges in MST are : ");
  for(int i = 0; i<=V-1;i++)
  {
      if(i==startvertex)
        continue;
      printf("\nEdge (%d,%d) : %d",i,pi[i],G[i][pi[i]]);
      totalcost+=G[i][pi[i]];
      
  }
  printf("\n\nTotal Cost : %d",totalcost);

}

int main()
{
  printf("\nEnter number of vertices\n");
  scanf("%d",&V);
  readGraph();
  displaygraph();
  printf("No.of vertex : %d\nNo.of Edges : %d\n",V,E);

  initialize();
  printf("\nAfter initialization....");
  print_key_pi();
  
  printf("\n\nEnter starting vertex : ");
  scanf("%d",&startvertex);
  printf("\n");
  
  
  key[startvertex] = 0;
  
  //creating minimum priority
  createQueue();
    
  while(cnt<V)
  {
      int u = Extract_Min();
      visited[u]=1;
      print_key_pi();
      printf("\n%d",u);
      
      for(int v= 0; v<V;++v)
      {
          if(G[u][v]!=0)
          {
            if(check(v) && G[u][v]  < key[v])
            {
                pi[v] = u;
                key[v] = G[u][v];
                priority[v] = key[v];
                
            }
          }
      }
      cnt++;
  }
  printf("\n\nFinal Values are.........");
  print_key_pi();
  edgesinMST();
  return 0;
  
}
