#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'sumVips' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY score
 *  2. INTEGER guilder_count
 *  3. INTEGER k
 */

long sumVips(vector<int> score, int guilder_count, int k) {

    vector<int> answer;
    //�õ� Ƚ��
    for (int i = 0; i < guilder_count; i++)
    {
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int size = score.size();

        if (size <= k)      //k�� �̸��϶��� ��ü��Ͽ��� ����
        {
            max3 = *max_element(score.begin(), score.end());

            //�ش� ���� ����
            for (int j = 0; j < score.size(); j++)
            {
                if (score[j] == max3) score.erase(score.begin() + j);
            }

            //�ش���� ����迭�� �߰�
            answer.push_back(max3);
        }
        else
        {
            //�ִ밪 ����
            for (int j = 0; j < k; j++)
            {
                max1 = max(max1, score[j]);
                max2 = max(max2, score[size - j - 1]);
            }
            max3 = max(max1, max2);
            //�ش� ���� ����
            for (int j = 0; j < score.size(); j++)
            {
                if (score[j] == max3) score.erase(score.begin() + j);
            }

            //�ش���� ����迭�� �߰�
            answer.push_back(max3);
        }


    }

    long sum = 0;

    for (int i = 0; i < answer.size(); i++)
    {
        sum += answer[i];
    }

    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string score_count_temp;
    getline(cin, score_count_temp);

    int score_count = stoi(ltrim(rtrim(score_count_temp)));

    vector<int> score(score_count);

    for (int i = 0; i < score_count; i++) {
        string score_item_temp;
        getline(cin, score_item_temp);

        int score_item = stoi(ltrim(rtrim(score_item_temp)));

        score[i] = score_item;
    }

    string guilder_count_temp;
    getline(cin, guilder_count_temp);

    int guilder_count = stoi(ltrim(rtrim(guilder_count_temp)));

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    long result = sumVips(score, guilder_count, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
