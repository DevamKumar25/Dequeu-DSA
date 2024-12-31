#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfSubarray(vector<int> arr, int n, int k) 
{
    vector<int> result;

    deque<int> dq;

    // Process first k elements of the array

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process the rest of the array

    for (int i = k; i < n; i++) {
        // The front of the deque is the maximum element of the previous window

        result.push_back(arr[dq.front()]);

        // Remove elements which are out of the current window

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements that are smaller than the current element arr[i]

        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque

        dq.push_back(i);
    }

    // Add the maximum element of the last window
	
    result.push_back(arr[dq.front()]);

    return result;
}




/*
// Time complexity = O(N^2);
// space complexity  = O(N);



	for(int i=0;i<n-k+1;i++){
		int mx = arr[i];
		for(int j=i+1;j<i+k;j++){
			mx = max(arr[j],mx);
		}
		result.push_back(mx);

	}
	return result;


*/
