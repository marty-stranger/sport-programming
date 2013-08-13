// Algorytm Edmondsa
// W ramach zadania 1099 - Work Scheduling (acm.timus.ru)

#include <cstdlib>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>

#define self (*this)

struct UnionFind {
	std::map<int, int> parents;
	std::vector<int> weights;

	int operator[] (int const &i) {
		if(parents.find(i) == parents.end()) {
			parents[i] = i;
			weights[i] = 1;
			return i;
		} else {
			int root = parents[i];
			std::vector<int> path;
			path.push_back(i);
			while(root != path.back()) {
				path.push_back(root);
				root = parents[root];
			}
			for(unsigned int i = 0; i < path.size(); ++i) {
				parents[path[i]] = root;
			}
			return root;
		}
	}

	void perform_union(std::vector<int> path) {
		std::vector<int> roots;
		int hr, hw = INT_MIN;
		for(unsigned int i = 0; i < path.size(); ++i){
			roots.push_back(self[path[i]]);
		}
		for(unsigned int i = 0; i < roots.size(); ++i) {
			if(weights[roots[i]] > hw ||
					(weights[roots[i]] == hw && roots[i] > hr)) {
				hr = roots[i];
				hw = weights[roots[i]];
			}
		}
		for(unsigned int i = 0; i < roots.size(); ++i) {
			if(roots[i] != hr) {
				weights[hr] += weights[roots[i]];
				parents[roots[i]] = hr;
			}
		}
	}

	inline void clear() {
		parents.clear();
		weights.clear();
	}

	UnionFind() {}

	UnionFind(size_t const &size) {
		weights.resize(size, 0);
	}
};

typedef std::vector<unsigned int> nb_list;

struct g_vert {
	nb_list nb;
};

typedef std::vector<g_vert> graph;

void add_edge(graph &G, unsigned int const &a, unsigned int const &b) {
	G[a].nb.push_back(b);
	G[b].nb.push_back(a);
}

struct MatchingFindingEnvironment {
	UnionFind leader;
	std::map<int, int> S;
	std::map<int, int> T;
	std::vector<int> unexplored;
	std::map <int, std::pair<int, int> > base;
	std::vector<int> matching;

	void find_side(std::vector<int> &path, int const &v, int const &w,
		int const &a) {
		std::pair<int,int> b(v, w);
		path.push_back(leader[v]);
		while(path.back() != a) {
			int tnode = S[path.back()];
			path.push_back(tnode);
			base[tnode] = b;
			unexplored.push_back(tnode);
			path.push_back(leader[T[tnode]]);
		}
	}

	void blossom(int const &v, int const &w, int const &a) {
		std::vector<int> path1;
		std::vector<int> path2;
		find_side(path1, v, w, a);
		find_side(path2, w, v, a);
		leader.perform_union(path1);
		leader.perform_union(path2);
		S[leader[a]] = S[a];
	}

	void alternating_path(std::vector<int> &path, int start,
			int const &goal = -1) {
		while(true) {
			while(T.find(start) != T.end()) {
				std::pair<int, int> t = base[start];
				int v = t.first;
				int w = t.second;
				std::vector<int> vs;
				alternating_path(vs, v, start);
				for(std::vector<int>::reverse_iterator it = vs.rbegin();
						it != vs.rend(); ++it) {
					path.push_back(*it);
				}
				start = w;
			}
			path.push_back(start);
			if(matching[start] == -1) {
				return;
			} else {
				int tnode = matching[start];
				path.push_back(tnode);
				if(tnode == goal) return;
				else start = T[tnode];
			}
		}
	}

	void alternate(int const &v) {
		std::vector<int> path;
		std::vector<int>::reverse_iterator end;
		alternating_path(path, v);
		end = path.rend() - 1;
		for(std::vector<int>::reverse_iterator it = path.rbegin();
				it < end; it += 2) {
			matching[it[0]] = it[1];
			matching[it[1]] = it[0];
		}
	}
	
	void add_match(int const &v, int const &w) {
		alternate(v);
		alternate(w);
		matching[v] = w;
		matching[w] = v;
	}
	
	int step(std::map<int, int> &path, int head) {
		int parent;
		head = leader[head];
		parent = leader[S[head]];
		if(parent  == head) {
			return head;
		} else {
			path[head] = parent;
			path[parent] = leader[T[parent]];
			return path[parent];
		}
	}

	bool ss(int const &v, int const &w) {
		if(leader[v] == leader[w]) {
			return false;
		} else {
			std::map<int, int> path1, path2;
			int head1 = v, head2 = w;
			while(true) {
				head1 = step(path1, head1);
				head2 = step(path2, head2);
				if(head1 == head2) {
					blossom(v, w, head1);
					return false;
				} else if(leader[S[head1]] == head1 &&
						leader[S[head2]] == head2) {
					add_match(v, w);
					return true;
				} else if(path2.find(head1)!= path2.end()) {
					blossom(v, w, head1);
					return false;
				} else if(path1.find(head2) != path1.end()) {
					blossom(v, w, head2);
					return false;
				}
			}
		}
	}

	bool augment(graph &G) {
		unsigned int current;
		int v;
		leader.clear();
		S.clear();
		T.clear();
		unexplored.clear();
		base.clear();
		for(unsigned int i = 0; i < G.size(); ++i) {
			if(matching[i] == -1) { S[i] = i; unexplored.push_back(i); }
		}
		current = 0;
		while(current < unexplored.size()) {
			v = unexplored[current++];
			for(unsigned int i = 0; i < G[v].nb.size(); ++i) {
				if(S.find(leader[G[v].nb[i]]) != S.end()) {
					if(ss(v, G[v].nb[i])) return true;
				} else if(T.find(G[v].nb[i]) == T.end()) {
					int u = matching[G[v].nb[i]];
					T[G[v].nb[i]] = v;
					if(S.find(leader[u]) == S.end()) {
						S[u] = G[v].nb[i];
						unexplored.push_back(u);
					}
				}
			}
		}
		return false;
	}

	void find_matching(graph &G) {
		leader = UnionFind(G.size());
		matching.resize(G.size(), -1);
		for(unsigned int i = 0; i < G.size(); ++i) {
			for(unsigned int j = 0;
					matching[i] == -1 && j < G[i].nb.size(); ++j) {
				if(matching[G[i].nb[j]] == -1) {
					matching[i] = G[i].nb[j];
					matching[G[i].nb[j]] = i;
				}
			}
		}
		while(augment(G));
	}
};

int main() {
	graph G;
	MatchingFindingEnvironment env;
	unsigned int N, C;

	scanf("%u", &N);
	G.resize(N + 1);

	while(true) {
		unsigned int i, j;
		if(! ~scanf("%u %u", &i, &j)) break;
		if(i != j) add_edge(G, i, j);
	}

	env.find_matching(G);

	C = 0;
	for(unsigned int i = 0; i <= N; ++i) C += (env.matching[i] != -1);
	printf("%u\n", C);

	for(unsigned int i = 0; i <= N; ++i) {
		if(env.matching[i] != -1 && i < (unsigned int) env.matching[i]) {
			printf("%d %d\n", i, env.matching[i]);
		}
	}

	return EXIT_SUCCESS;
}
