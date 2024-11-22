#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<char, char>> tree;

//���� ��ȸ
void preorder(char node)
{
	if (node == '.')return;
	cout << node;
	preorder(tree[node].first);
	preorder(tree[node].second);
}
//������ȸ
void inorder(char node)
{
	if (node == '.')return;
	inorder(tree[node].first);
	cout << node;
	inorder(tree[node].second);
}
//������ȸ
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
		tree[parent] = { left, right }; // �θ�� �ڽ� ���� ����
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}