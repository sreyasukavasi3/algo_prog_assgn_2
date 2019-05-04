#include<bits/stdc++.h>
#define ll long long
#define str string
#define pb  push_back
#define mp  make_pair
#define ff  first
#define ss  second


using namespace std ;
bool vi[10];
vector< pair< ll , ll > > v[10];
ll shortestpath[10];
ll n , a ,b,V,c;
void Diji()
{
	
	for(int i=0;i<V;i++){
		int min=INT_MAX,k;
		for(int j=0;j<V;j++){
			if(!vi[j]){
				if(min>shortestpath[j]){
					k=j;
					min=shortestpath[j];
				}
			}
		}
		vi[k] = true;
		for( ll p = 0 ; p < v[k].size() ; p++ )
		{
			
				if( v[k][p].second + min < shortestpath[v[k][p].first] )
				{
					shortestpath[v[k][p].first] = v[k][p].second + min;
				} 	 
			
		}
		
	}
}
int main()
{
	
	cout << "enter no.of edges :" ;
	cin >> n;
	cout << "enter no.of vertices: ";
	cin >> V;
	for(int i=1;i<10;i++){
		shortestpath[i]=INT_MAX;
	}
	memset(vi,false,sizeof(vi));
	for( ll i = 0 ; i < n ; i++)
	{
		cin >> a >> b >>c;
		v[a].pb(mp(b , c));
	}
	shortestpath[0]=0;
	Diji();
	for( ll i = 0 ; i < V ; i++)
	{
		cout << shortestpath[i] << " ";
	}
}
