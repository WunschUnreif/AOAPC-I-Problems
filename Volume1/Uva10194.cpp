#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string lower(string s) {
    string ans(s);
    for(auto & c : ans) c = tolower(c);
    return ans;
}

struct Team{
    string name;
    int points = 0;
    int wins = 0;
    int ties = 0;
    int lost = 0;
    int scored = 0;
    int against = 0;
    int gameCnt = 0;

    Team(string name): name(name) {}

    bool operator < (Team& b) {
        if(points > b.points) return true;
        if(points < b.points) return false;
        if(wins > b.wins) return true;
        if(wins < b.wins) return false;
        if(scored-against > b.scored-b.against) return true;
        if(scored-against < b.scored-b.against) return false;
        if(scored > b.scored) return true;
        if(scored < b.scored) return false;
        if(gameCnt < b.gameCnt) return true;
        if(gameCnt > b.gameCnt) return false;
        if(lower(name) < lower(b.name)) return true;
        if(lower(name) > lower(b.name)) return false;
        return false;
    }
};

void solve() {
    string gameName;
    vector<Team> teams;
    getline(cin, gameName);
    cout << gameName << endl;
    map<string, int> nameMap;
    int nameCnt;
    cin >> nameCnt;
    string _; getline(cin, _);
    while(nameCnt--) {
        string name;
        getline(cin, name);
        teams.emplace_back(name);
        nameMap[name] = teams.size() - 1;
    }
    //cout << teams.size() << endl;
    int gameCnt;
    cin >> gameCnt;
    getline(cin, _);
    while(gameCnt--) {
        char game[100];
        cin.getline(game, 100);
        char name1[100], name2[100];
        int goal1, goal2;
        sscanf(game, "%[^#]#%d@%d#%[^\n\r]", name1, &goal1, &goal2, name2);
        //while(getchar() != '\n');
        string t1(name1), t2(name2);
        vector<Team>::iterator team1 = teams.begin() + nameMap[t1], team2 = teams.begin() + nameMap[t2];
        team1->gameCnt++;
        team2->gameCnt++;
        team1->scored += goal1;
        team1->against += goal2;
        team2->scored += goal2;
        team2->against += goal1;
        if(goal1 > goal2) {
            team1->wins++;
            team1->points += 3;
            team2->lost++;
        } else if(goal1 == goal2) {
            team1->points += 1;
            team2->points += 1;
            team1->ties++;
            team2->ties++;
        } else {
            team2->wins++;
            team2->points += 3;
            team1->lost++;
        }
    }
    sort(teams.begin(), teams.end());
    int i = 0;
    for(auto &t : teams) {
        ++i;
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
            i, t.name.c_str(), t.points, t.gameCnt, t.wins, t.ties, t.lost, t.scored - t.against, t.scored, t.against
        );
    }
}

int main() {
    int kase;
    cin >> kase;
    string _;
    getline(cin, _);
    while(kase--) {
        solve();
        if(kase) cout << endl;
    }
}
