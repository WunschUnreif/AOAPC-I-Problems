#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <set>
#include <cctype>
using namespace std;

set<string> ignore;
set<string> keywords;

vector< vector<string> > titles;

string& upper(string & s) {
    for(auto& c : s) c = toupper(c);
    return s;
}

string& lower(string & s) {
    for(auto& c : s) c = tolower(c);
    return s;
}

int find(string& k, vector<string>& t) {
    int ans = 0;
    for(auto i : t) if(i == k) ans++;
    return ans;
}

int main() {
    string ign;
    while(cin >> ign && ign != "::") ignore.insert(ign);
    string title;
    while(getline(cin, title)) {
        titles.emplace_back();
        stringstream ss(title);
        string wd;
        auto& title = titles.back();
        while(ss >> wd) {
            lower(wd);
            title.push_back(wd);
            if(ignore.find(wd) == ignore.end()) {
                keywords.insert(wd);
            }
        }
    }
    for(auto k : keywords) {
        for(auto t : titles) {
            int cnt = 0;
            if((cnt = find(k, t)) != 0) {
                for(int tm = 0; tm < cnt; ++tm) {
                    bool first = true;
                    int cnt = 0;
                    for(auto i : t) {
                        if(!first) cout << ' ';
                        if(i == k) {
                            cnt++;
                            if(cnt == tm + 1)
                                cout << upper(i);
                            else cout << i;
                        }
                        else cout << i;
                        first = false;
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
