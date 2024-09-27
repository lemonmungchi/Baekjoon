#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> pocket;
unordered_map<string, int> pocket2;
int main()
{
	int n, m;

	char buffer[21];  // 포켓몬 이름을 받을 버퍼

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		string pocketmon;
		scanf("%s", buffer);
		pocket.push_back(buffer);
		pocket2[buffer] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s", buffer);
		if (isdigit(buffer[0]))
		{
			printf("%s\n", pocket[stoi(buffer)-1].c_str());
		}
		else
		{
			printf("%d\n", pocket2[buffer]);
		}
	}

	return 0;
}