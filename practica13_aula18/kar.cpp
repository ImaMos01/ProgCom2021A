#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n=rooms.size();
    vector<bool> visit(n,false);
   
    deque<int> vis;
    vis.push_back(0); 
    while(!vis.empty()){
        int x=vis.front();
        vis.pop_front();

        visit[x]=true;
        for(int i=0; i<rooms[x].size();i++){
            if(visit[rooms[x][i]]==false){
                vis.push_front(rooms[x][i]);
            }
        }
    }
    for(int j=0;j<n;j++){
        if(visit[j]==false) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> rooms={{1,3},{3,0,1},{2},{0}};

    cout<<canVisitAllRooms(rooms);
}