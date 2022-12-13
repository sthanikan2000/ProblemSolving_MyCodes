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
        
        // case 1 : maxH half has more elements 
        if(maxH.size() > minH.size()){
            
            // new element is less than med median
            if(x < med){
                
                // move one element from maxH heap to minH heap
                minH.push(maxH.top());
                maxH.pop();
                // add new element into maxH heap
                maxH.push(x);
            }
            
            // new element is greater than or equal to med median
            else{
                // everything is OK, minH heap has less elements
                // and new element is greater than med median
                // so, add it in minH heap.
                minH.push(x);
            }
            // update median
            med = (maxH.top() + minH.top()) / 2.0;
        }
        // case 2 : both heaps are balanced
        else if(maxH.size() == minH.size()){
            // both heaps have same size, so just need to check if new element
            // is less than med median or greater and add accordingly
            if(x < med){
                maxH.push(x);
                med = maxH.top();
            }
            else{
                minH.push(x);
                med = minH.top();
            }
        }
        // case 3 : minH heap has more number of elements
        else{
            if(x > med){
                // move one element from minH heap to maxH heap
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
