#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	Node()
	{
		parent = nullptr;
		leafNode = true;
	}

	vector<int> childs;
	Node* parent;
	bool leafNode;
};

vector<Node*> nodes;
int N, ans = 0, rIndex;

void NodeUpdate(Node* curNode)
{
	for (auto child : curNode->childs)
	{
		if (nodes[child] != nullptr)
		{
			curNode->leafNode = false;
			return;
		}
	}
	curNode->leafNode = true;
}

void Solve()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		Node* node = new Node();

		nodes.push_back(node);
	}
	int root_index = 0;

	for(int i = 0; i < N; i++)
	{
		int p;
		cin >> p;

		if (p == -1)
		{
			root_index = i;
			continue;
		}
		nodes[i]->parent = nodes[p];
		nodes[i]->parent->childs.push_back(i);
		if (nodes[i]->parent)
		{
			NodeUpdate(nodes[i]->parent);
		}
	}

	cin >> rIndex;
	if (rIndex == root_index)	// 제거 된게 루트라면
	{
		cout << ans << "\n";
		return;
	}
	Node* parentNode = nodes[rIndex]->parent;
	delete nodes[rIndex];
	nodes[rIndex] = nullptr;
	NodeUpdate(parentNode);

	queue<Node*> q;
	q.push(nodes[root_index]);

	while (!q.empty())
	{
		Node* cur = q.front();
		q.pop();

		if (cur->leafNode) ans++;
		for (auto index : cur->childs)
		{
			if (nodes[index] != nullptr)
			{
				q.push(nodes[index]);
			}
		}
	}

	cout << ans;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}