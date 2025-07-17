class Solution {
public:
	static bool comparator(vector<int> meetingA, vector<int> meetingB) {
		int startA = meetingA[0], endA = meetingA[1];
		int startB = meetingB[0], endB = meetingB[1];

		if (startA == startB) { // Agar do meetings ke start time same hai,
			// then unke end time ke according asending order mei sort kardo
			return endA < endB;
		}

		return startA < startB;

	}

	int minMeetingRooms(vector<vector<int>>& a) {
		sort(a.begin(), a.end(), comparator);

		priority_queue<int, vector<int>, greater<int> > h; // Minheap

		for (int i = 0 ; i < a.size() ; ++i) {
			int currentMeeting_startTime = a[i][0];
			int currentMeeting_endTime = a[i][1];

			if (h.empty()) {
				h.push(currentMeeting_endTime);
			}
			else {
				// Agar ek room mei meeting pehle hi khatam ho rahi hai
				// then ussi room ko use karo
				if (h.top() <= currentMeeting_startTime) {
					h.pop();
					h.push(currentMeeting_endTime);
				}
				else {
					h.push(currentMeeting_endTime);
				}
			}
		}

		return h.size();

	}
};



