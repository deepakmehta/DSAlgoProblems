/*You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.



Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0.
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.


Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.*/

#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

bool IntervalCheck(vector<int>first, vector<int>second) {
    return first[0]<second[0];
}

class Solution {
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
      sort(meetings.begin(),meetings.end(),IntervalCheck);
      priority_queue<int,vector<int>,greater<int>> meetingrooms;
      //priority_queue<int,vector<int>,greater<int>> endtimes;
      vector<int> booking(n,0);
      map<int, int> endtimeToMeetingRoom;
      
      for( int i = 0; i < n;++i) {
        meetingrooms.push(i);
      }
      

      int delay=0;
      int meetingtoschedule=0;
      for(int timespend = 0 ; 1;++timespend) {
        cout << "Time spend: " << timespend << " delay: " << delay << endl;
        if(meetingtoschedule >= meetings.size()) break;
        // lets check if any meeting has ended
        if (endtimeToMeetingRoom.find(timespend)!= endtimeToMeetingRoom.end()) {
            cout << " Meeting ended: " << endtimeToMeetingRoom[timespend] << endl; 
            // lets get the room number and add to the queue
            meetingrooms.push(endtimeToMeetingRoom[timespend]);
            //endtimeToMeetingRoom.
        }
        if( (timespend-delay) == meetings[meetingtoschedule][0]) {
            cout << " Meeting to schedule: " << meetingtoschedule  << " start: " << meetings[meetingtoschedule][0] <<
              " end: " << meetings[meetingtoschedule][1] << endl;
            if (meetingrooms.empty()) {
                cout << " Meeting rooms unavailable" << endl;
                delay++; continue;}

          // meeting is there to schedule
          int room = meetingrooms.top(); meetingrooms.pop();
          cout << " Meeting scheduled in room number: " << room << endl;
          booking[room]++;
          cout << "Meeting schedule will end at: " << delay+meetings[meetingtoschedule][1] << endl;
          endtimeToMeetingRoom.insert(std::pair<int,int>( delay+meetings[meetingtoschedule][1] ,room));
          meetingtoschedule++;
        }
      }

      int max = -1;
      int roombooked=-1;
      for ( int i = 0 ; i <n;++i) {
        cout << "Room booked: " << i << " times: " << booking[i] << endl;
        if(booking[i]>max) {
          roombooked=i;
          max=booking[i];
        }
      }
      return roombooked;
    }
};


int main() {
    Solution abc;
    int a=3;
    vector<vector<int>> meetings{{0,10},{1,5},{2,7},{3,4}};
    // cout << "Max booked: " << abc.mostBooked(a, meetings) << endl;
    // a=3;
    // meetings = vector<vector<int>>{{ 1, 20 }, { 2, 10 }, { 3, 5 }, { 4, 9 }, { 6, 8 }};
    // cout << "Max booked: " << abc.mostBooked(a, meetings) << endl;
    // meetings = vector<vector<int>>{{13,16},{12,19}};
    // cout << "Max booked: " << abc.mostBooked(a, meetings) << endl;
    meetings = vector<vector<int>>{{39,49},{28,39},{9,29},{10,36},{22,47},{2,3},{4,49},{46,50},{45,50},{17,33}};
    cout << "Max booked: " << abc.mostBooked(a, meetings) << endl;
    return 0;
}