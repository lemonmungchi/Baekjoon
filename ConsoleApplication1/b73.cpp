#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string line;

	//���� �Է¹ޱ�
	getline(cin, line);

	istringstream stream(line);
	string word;
	int cnt = 0;

	//������ �������� �ܾ �о����
	while (stream >> word)
	{
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}