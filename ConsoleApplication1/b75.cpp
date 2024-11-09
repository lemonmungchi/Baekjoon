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
    //시도 횟수
    for (int i = 0; i < guilder_count; i++)
    {
        int max1 = 0;
        int max2 = 0;
        int max3 = 0;
        int size = score.size();

        if (size <= k)      //k명 미만일때는 전체목록에서 선택
        {
            max3 = *max_element(score.begin(), score.end());

            //해당 원소 제거
            for (int j = 0; j < score.size(); j++)
            {
                if (score[j] == max3) score.erase(score.begin() + j);
            }

            //해당원소 정답배열에 추가
            answer.push_back(max3);
        }
        else
        {
            //최대값 저장
            for (int j = 0; j < k; j++)
            {
                max1 = max(max1, score[j]);
                max2 = max(max2, score[size - j - 1]);
            }
            max3 = max(max1, max2);
            //해당 원소 제거
            for (int j = 0; j < score.size(); j++)
            {
                if (score[j] == max3) score.erase(score.begin() + j);
            }

            //해당원소 정답배열에 추가
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
