#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minimumDivisor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER threshold
 */
// devo risolverlo considerando che l'array non è ordinato
/*

|------------|----------|
min    sum>threshold    max

*/
 int minimumDivisor(vector<int> arr, int threshold) {
    int min_div = 1;
    int max_div = 0;
    for (int v: arr){
        if(v>max_div){
            max_div = v;
            while (min_div < max_div){
                int m_div = (min_div+max_div)/2;

                itn sum = 0;
                for(int v: arr){
                    int d = (v%m_div == 0) ? v/m_div : v/m_div+1;
                    sum = sum + d;
                }
                if(sum > threshold){
                    min_div = m_div + 1;
                } else {
                    max_div = m_div;
                }
            }
        }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    int result = minimumDivisor(arr, threshold);

    fout << result << "\n";

    fout.close();

    return 0;
}


string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end());
    return s;
}
