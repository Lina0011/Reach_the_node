//
#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

//initialize adjacency matrix to store edges
int adj[MAX+1][MAX+1] = {0};//assign all its values to "0"

int N = 0;//"N" variable for counting the vertices

void InsertVertex()
{
    N++;
}

void InsertEdge(int u, int v)
{
    //adding the edge twice because it is undirected graph
    adj[u][v]=1;
    adj[v][u]=1;
}
void clearQueue(queue<int> &q){
	while(!q.empty()){
		q.pop();
	}
}
     
//uncompleted BFS traversal from source "s" to destination "d"
int BFS(int s,int d) {
    //set the edge counter to 0
        int e=0;
    //create a queue for BFS
        queue <int> q;
    //push the source into queue
        q.push(s);
    //set all vertices to unvisited
        int visited[MAX]={0};
    
        visited[s] = 1;//starting with visiting the source
    
        while(!q.empty()){
            
            if(q.front()==d)//exit the loop when reach the destination
                break;
            int current = q.front();
            q.pop();
            e++;//with each pop count the edges
            for(int i=1;i<N;i++)//loop to visit all connected vertices to the popped vertex
            {
                //check if the connected vertices is not within the source and destination
                if((s<d)&&(i<s||i>d))
                    continue;
                else if((s>d)&&(i>s||i<d))
                    continue;
                else if(adj[current][i])//if found edge and unvisited
                    if(visited[i] == 0)
                    {
                        visited[i] = 1;//make it visited and push it to the queue
                        q.push(i);
                    }
            }
    }
    clearQueue(q);

    return e;//return the minimum number of edges needed from "n" to "d"
        }   


int main()
{
    int n=0,u=0,v=0;
    //enter number of vertices to insert(the loop is used to add n number of vertices)
    cin>>n;
    for (int i=0;i<n;i++){
        InsertVertex();
    }
    // n-1 is the number of edges (in each loop the user add 1 edge between two vertices)
    //assume that the vertices are arranged(connected by edges) in ascending or descending order
    int i=0;
    while (i<n-1){
        cin >> u >> v;
        //the edges must be included within the "n" vertices
        if(u > n|| v > n){
            cout<<"Source or destination vertex is not exist\n" ;
            cout<<"try again\n";
            continue;
        }
        else {
            InsertEdge(u,v);
            i++;
        }
    }

    int q=0;
    //loop q times for each query
    cin>>q;
    int x=0,y=0,a=0,b=0,k=0;
    cout<<endl;
    for (int i=0;i<q;i++){
        //each query include one temporary edge x ,y and testing path from source a to destination b with number of edges = k
        cin>>x>>y>>a>>b>>k;
//path1 is the lenght of k - BFS the source a and the distance b (direct path from a to b)
        
//path2 is the lenght of k - BFS the source a and the distance x and add +1 for xy edge and BFS the source y and the distance b
        //(a -> x -> y -> b )
//path3 is the length of k - BFS the source a and the distance y and add +1 for xy edge and BFS the source x and the distance b
        //(a -> y -> x -> b )
        
        int path1 =k-BFS(a,b);
        int path2 =k-(BFS(a,x)+1+BFS(y,b));
        int path3 =k-(BFS(a,y)+1+BFS(x,b));
/*
 when the path from A to B length is an integer greater than 0 and 
 an even number (this is for visiting the same vertices with same edges multiple times)
 cause going from the vertex and back to it counting the edges by 2
 print YES
 otherwise print NO 
*/
        if ((path1>=0&&path1%2==0)||(path2>=0&&path2%2==0)||(path3>=0&&path3%2==0))
            cout<<"YES"<<"\n\n";
        else
            cout<<"NO "<<"\n\n";
    }
   
  return 0;
}
/*test the input
5
1 2
2 3
3 4
4 5
5
1 3 1 2 2
1 4 1 3 2
1 4 1 3 3
4 2 3 3 9
5 2 3 3 9
the output is
YES
YES
NO
YES
NO
*/

