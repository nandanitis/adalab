#include<iostream>
#include<vector>
using namespace std;
#define V 6

int find_minKEY(vector<int>& value, vector<bool>& mst_set)
{
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<V;i++)
    if(mst_set[i]==false && value[i]<min)
    {
        vertex=i;
        min=value[i];
    }
    return vertex;
}

void find_mst(int graph[V][V])
{
    int parent[V];
    vector<int> value(V,INT_MAX);
    vector<bool> set_mst(V,false);
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<V-1;++i)
    {
        int u=find_minKEY(value,set_mst);
        set_mst[u]=true;
        for(int j=0;j<V;++j)
        {
            if(graph[u][j]!=0 && set_mst[j]==false && graph[u][j]<value[j])
            {
                parent[j]=u;
                value[j]=graph[u][j];
            }
        }
    }
    for(int i=1;i<V;i++)
    cout<<parent[i]<<"->"<<i<<"  wt="<<graph[parent[i]][i]<<endl;
}

int main()
{
	int graph[V][V];
    cout<<"Enter graph with "<<V<<" vertices\n";
    for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
    cin>>graph[i][j];
	find_mst(graph);	
	return 0;
}