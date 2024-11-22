#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<char, char>> tree;

//전위 순회
void preorder(char node)
{
	if (node == '.')return;
	cout << node;
	preorder(tree[node].first);
	preorder(tree[node].second);
}
//중위순회
void inorder(char node)
{
	if (node == '.')return;
	inorder(tree[node].first);
	cout << node;
	inorder(tree[node].second);
}
//후위순회
void postorder(char node)
{
	if (node == '.')return;
	postorder(tree[node].first);
	postorder(tree[node].second);
	cout << node;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;
		tree[parent] = { left, right }; // 부모와 자식 관계 저장
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}