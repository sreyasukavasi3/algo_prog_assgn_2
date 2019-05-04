#include<bits/stdc++.h>
#include<stack>
#define ll long long
#define str string
#define pb  push_back
#define mp  make_pair
#define ff  first
#define ss  second

using namespace std;

bool vi[10];
vector < int > v[10];
stack < int > s;
void TopoligicalSort(ll c)
{	
		vi[c] = true;
		for( ll i = 0 ; i < v[c].size() ; i++  )
		{
			if( vi[v[c][i]] == false)
			{
				TopoligicalSort(v[c][i]);
			}
		}
		s.push(c);
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
	}
	ll vertices;
	cout << "enter the no.of vertices :  " ;
	cin >> vertices;
	memset(vi,false,sizeof(vi));
	for( ll i = 0 ; i < n ; i++)
	{
		if(vi[i] == false)
		{
			TopoligicalSort(i);
		}
	}
		while(!(s.empty()))
	{
		cout << s.top() << " ";
		s.pop();
	}

}
	

