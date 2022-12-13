#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    vector<double> med_res;
    double med = 0;
    int n = a.size();

    priority_queue<double> maxH;
    priority_queue<double, vector<double>, greater<double>> minH;
    
    for(int i = 0; i < n; i++){
        double x = a[i];
      
        if(maxH.size() > minH.size()){
            if(x < med){
                minH.push(maxH.top());
                maxH.pop();
                maxH.push(x);
            }
            else{
                minH.push(x);
            }
            med = (maxH.top() + minH.top()) / 2.0;
        }
        else if(maxH.size() == minH.size()){
            if(x < med){
                maxH.push(x);
                med = maxH.top();
            }
            else{
                minH.push(x);
                med = minH.top();
            }
        }
        else{
            if(x > med){
                maxH.push(minH.top());
                minH.pop();
                minH.push(x);
            }
            else{
                maxH.push(x);
            }
            med = (maxH.top() + minH.top()) / 2.0;
        }
        med_res.push_back(med);
    }

    return med_res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
