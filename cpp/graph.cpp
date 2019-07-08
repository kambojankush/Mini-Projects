#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Graph
{
	map <T, list<T>> adjList;

public:
	Graph()
	{

	}

	void add_edge(T u, T v, bool bidir=true)
	{
		adjList[u].push_back(v);

		if (bidir)
		{
			adjList[v].push_back(u);
		}
	}

	void print_adjList()
	{
		for (auto node : adjList)
		{
			cout << node.first << "->";

			for (auto neighbour : node.second) cout << neighbour << ",";
			cout << endl;

		}
	}

	void bfs(T start)
	{
		map <T, bool> visited;
		queue <T> q;

		q.push(start);
		visited[start] = true;

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto neighbour : adjList[node])
			{
				if (!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}

		cout << endl;
	}

	map<T, int> shortest_path(T src)
	{
		map <T, int> dist;
		queue <T> q;

		for (auto node : adjList)
		{
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			for (auto neighbour : adjList[node])
			{
				if (dist[neighbour] == INT_MAX)
				{
					dist[neighbour] = dist[node] + 1;
					q.push(neighbour);
				}
			}
		}

		return dist;
	}

	void dfsHelper(T node, map <T, bool> &visited)
	{
		visited[node] = true;
		cout << node << " ";

		for (auto neighbour : adjList[node])
		{
			if (!visited[neighbour]) dfsHelper(neighbour, visited);
		}
	}

	// for topological sorting
	void dfsHelper(T node, map <T, bool> &visited, stack<T> &ordering)
	{
		visited[node] = true;

		for (auto neighbour : adjList[node])
		{
			if (!visited[neighbour]) dfsHelper(neighbour, visited, ordering);
		}

		ordering.push(node);
	}

	int dfs(T src)
	{
		map <T, bool> visited;
		int components = 1;
		
		dfsHelper(src, visited);
		cout << endl;

		for (auto i : adjList)
		{
			T node = i.first;
			if (!visited[node])
			{
				components++;
				dfsHelper(node, visited);
				cout << endl;
			}
		}

		return components;

	}

	stack <T> dfsTopologicalSort()
	{
		map <T, bool> visited;
		stack <T> ordering;

		for (auto i : adjList)
		{
			T node = i.first;
			if (!visited[node])
			{
				dfsHelper(node, visited, ordering);
			}
		}

		return ordering;
	}

	void topologicalSort()
	{
		map <T, bool> visited;
		map <T, int> indegree;

		queue <T> q;

		for (auto i : adjList)
		{
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		for (auto i : adjList)
		{
			T node = i.first;
			for (auto neighbour : adjList[node])
			{
				indegree[neighbour]++;
			}
		}

		for (auto i : adjList)
		{
			T node = i.first;
			if (indegree[node] == 0)
			{
				visited[node] = true;
				q.push(node);
			}
		}

		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << " ";

			for (auto neighbour : adjList[node])
			{	
				indegree[neighbour]--;
				if (indegree[neighbour] == 0)
				{
					visited[neighbour] = true;
					q.push(neighbour);
				}
			}
		}
	}

	bool bfsIscyclic(T src)
	{
		map <T, bool> visited;
		map <T, T> parent;
		queue <T> q;

		visited[src] = true;
		parent[src] = src;
		q.push(src);

		while (!q.empty())
		{
			T node = q.front();
			q.pop();

			for (auto neighbour : adjList[node])
			{
				if (visited[neighbour] && neighbour != parent[node]) return true;
				else if (!visited[neighbour])
				{
					visited[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}

		return false;
	}
	
	bool iscyclicHelper(T node, map <T, bool> &visited, map <T, bool> &inStack)
	{
		visited[node] = true;
		inStack[node] = true;

		for (auto neighbour : adjList[node])
		{
			if (visited[neighbour] && inStack[neighbour]) return true;
			else if (!visited[neighbour] && iscyclicHelper(neighbour, visited, inStack)) return true;
		}

		inStack[node] = false;
		return false;
	}

	bool directedIscyclic()
	{
		map <T, bool> visited;
		map <T, bool> inStack;

		bool res = false;

		for (auto i: adjList)
		{
			T node = i.first;
			if (!visited[node]) res = iscyclicHelper(node, visited, inStack);
			if (res) return true;
		}

		return false;
	}
	
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Graph <int> g;

	g.add_edge(0, 2, false);
	g.add_edge(0, 1, false);
	g.add_edge(2, 3, false);
	g.add_edge(2, 4, false);
	g.add_edge(3, 1, false);
	g.add_edge(4, 5, false);
	g.add_edge(1, 5, false);

	cout << g.directedIscyclic();

	// cout << x << endl;

	// for (auto node : d) cout << "distance of " << node.first << " = " << node.second << endl; 

	fclose(stdout);
	fclose(stdin);
	return 0;
}