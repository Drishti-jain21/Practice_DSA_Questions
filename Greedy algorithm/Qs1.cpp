// N meetings in one room
// time complexity O(nlogn)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> timing;
        for(int i=0;i<n;i++){
            int st = start[i];
            int en = end[i];
            pair<int,int> meeting;
            meeting.first = st;
            meeting.second = en;
            timing.push_back(meeting);
        }
        sort(timing.begin(),timing.end(),cmp);
        int count = 1;
        int ansEnd = timing[0].second;
        for(int i=1;i<n;i++){
            if(ansEnd<timing[i].first){
                ansEnd = timing[i].second;
                count++;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends