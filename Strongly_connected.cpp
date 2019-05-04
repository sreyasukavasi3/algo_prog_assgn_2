#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define str string
#define pb  push_back
#define mp  make_pair
#define ff  first
#define ss  second

using namespace std;

bool vi[10],vi2[10];
vector < int > v[10],v2[10];
stack < int > s;
queue < int > q;
void DFS(ll c)
{	
		vi[c] = true;
		cout << c << " ";
		s.push(c);
		for( ll i = 0 ; i < v[c].size() ; i++  )
		{
			if( vi[v[c][i]] == false)
			{
				DFS(v[c][i]);
			}
		}
		//s.push(c);
		return;
}
void DFS2(ll c)
{	
		vi2[c] = true;
		cout << c << " ";
		for( ll i = 0 ; i < v2[c].size() ; i++  )
		{
			if( vi2[v2[c][i]] == false)
			{
				q.push(v2[c][i]);
				DFS2(v2[c][i]);
			}
		}
		q.push(c);
		return;
}
int main()
{
	cout << "enter no.of edges";
	ll n , a , b;
	cin >> n;
	cout << "enter edges";
	for( ll i = 0 ; i < n ; i++)
	{
		cin >> a >> b;
		v[a].pb(b);
		v2[b].pb(a);
	}
	cout << "enter no.of vertices";
	ll V;
	cin >> V;
	memset(vi,false,sizeof(vi));
	memset(vi,false,sizeof(vi2));
	for( ll i = 0 ; i < V ; i++)
	{
		if( vi[i] == false)
		{
			DFS(i);
		}
	}
	cout << endl;
	while( !s.empty())
	{
		if( vi2[s.top()] == false)
		{
			DFS2(s.top());	
		}
		cout << endl;	
		s.pop();
	}
}

