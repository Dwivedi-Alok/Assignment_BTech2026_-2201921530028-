#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int temp=asteroids[i];
            bool destroyed=false;
            while(!st.empty() && temp<0 && st.top()>0){
                    if(abs(temp)<st.top()){
                        destroyed=true;
                         break;
                    }else if(abs(temp)>st.top()){
                        st.pop();

                    }
                    else {
                        st.pop();
                        destroyed=true;
                        break;
                    }

            }
            if(!destroyed) st.push(temp);

        }
        asteroids.resize(st.size());
        int i=st.size()-1;
        while(!st.empty()){
            asteroids[i]=st.top();
            st.pop();
            i--;
        }
        return asteroids;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>asteroids;
   asteroids.push_back(5);
   asteroids.push_back(10);
   asteroids.push_back(-2);
   asteroids.push_back(7);
   asteroids.push_back(-8);
   asteroids.push_back(9);
    Solution s;
  vector<int> result = s.asteroidCollision(asteroids);
for (int x : result) cout << x << " ";
cout << "\n";

    return 0;
}