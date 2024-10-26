#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string line;

	//한줄 입력받기
	getline(cin, line);

	istringstream stream(line);
	string word;
	int cnt = 0;

	//공백을 시준으로 단어를 읽어오기
	while (stream >> word)
	{
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}