#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumAverage' function below.
 *
 * The function is expected to return an intEGER.
 * The function accepts 2D_intEGER_ARRAY customers as parameter.
 */
bool sortcol( const vector<long long>& v1,
               const vector<long long>& v2 ) {
    return v1[0] > v2[0];
}
long long minimumAverage(vector<vector<long long>> cus) {
    long long N=cus.size();
    sort(cus.begin(), cus.end(),sortcol);
    priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> minH;
    long long total_wait_time=0;
    long long time=0;

    while((!cus.empty())or(!minH.empty())){
        while((!cus.empty())and(cus[cus.size()-1][0]<=time)){
            vector<long long> i=cus[cus.size()-1];
            vector<long long> j;
            j.push_back(i[1]);
            j.push_back(i[0]);
            minH.push(j);
            cus.pop_back();
        }
        if(!minH.empty()){
            vector<long long> k=minH.top();
            minH.pop();
            time += k[0];
            total_wait_time += time - k[1];
        }
        else{
            vector<long long> i=cus[cus.size()-1];
            vector<long long> j;
            j.push_back(i[1]);
            j.push_back(i[0]);
            minH.push(j);
            cus.pop_back();

            time=minH.top()[1];
        }
    }
    return floor(total_wait_time/N);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long long n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<long long>> customers(n);

    for (long long i = 0; i < n; i++) {
        customers[i].resize(2);

        string customers_row_temp_temp;
        getline(cin, customers_row_temp_temp);

        vector<string> customers_row_temp = split(rtrim(customers_row_temp_temp));

        for (long long j = 0; j < 2; j++) {
            long long customers_row_item = stoi(customers_row_temp[j]);

            customers[i][j] = customers_row_item;
        }
    }

    long long result = minimumAverage(customers);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
