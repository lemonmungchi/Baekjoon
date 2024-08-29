#include "iostream"
#include "string"
#include "vector"
#include "utility"

using namespace std;

vector<pair<double, string>> scores;

// ���� ��� �Լ�
double ch(string s)
{
    if (s == "A+")
        return 4.5;
    else if (s == "A0")
        return 4.0;
    else if (s == "B+")
        return 3.5;
    else if (s == "B0")
        return 3.0;
    else if (s == "C+")
        return 2.5;
    else if (s == "C0")
        return 2.0;
    else if (s == "D+")
        return 1.5;
    else if (s == "D0")
        return 1.0;
    else if (s == "F")
        return 0.0;
    else
        return 0.0;  // Default case
}

int main()
{
    string course_name, grade;
    double credit;
    for (int i = 0; i < 20; i++)
    {
        cin >> course_name >> credit >> grade;
        scores.push_back(make_pair(credit, grade));  // ������ ����� ���Ϳ� ����
    }

    double total_score = 0.0;
    double total_credits = 0.0;

    for (int i = 0; i < scores.size(); i++) {
        if (scores[i].second == "P") continue;  // P ����� ������ ��꿡�� ����
        total_score += (scores[i].first * ch(scores[i].second));  // ���� * ��������
        total_credits += scores[i].first;  // �� ����
    }

    // �������� ���
    double gpa = total_score / total_credits;
    //cout << fixed; // ���� �Ҽ��� ����
    //cout.precision(6); // �Ҽ��� �Ʒ� 6�ڸ����� ���
    cout << gpa << endl;

    return 0;
}