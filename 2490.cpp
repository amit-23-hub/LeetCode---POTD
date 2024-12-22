class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
       int n = heights.size(); 
int queryCount = queries.size(); 

// Result array ko initialize karna -1 ke saath (default jab koi meeting place na ho)
vector<int> result(queryCount, -1);

// Deferred queries ko larger index ke basis par group karna
vector<vector<pair<int, int>>> deferredQueries(n);

// Min-Heap banaya hai taaki deferred queries efficiently process ki ja sake
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

// Step 1: Direct cases handle karna aur baaki ko defer karna
for (int queryIndex = 0; queryIndex < queryCount; ++queryIndex) {
    int aliceStart = queries[queryIndex][0]; // Alice ki shuruaati building
    int bobStart = queries[queryIndex][1];  // Bob ki shuruaati building

    if (aliceStart == bobStart) {
        // Agar Alice aur Bob ek hi building mein hain
        result[queryIndex] = aliceStart;
    } else if (aliceStart < bobStart && heights[aliceStart] < heights[bobStart]) {
        // Agar Alice seedha Bob ki building mein jaa sakti hai
        result[queryIndex] = bobStart;
    } else if (aliceStart > bobStart && heights[aliceStart] > heights[bobStart]) {
        // Agar Bob seedha Alice ki building mein jaa sakta hai
        result[queryIndex] = aliceStart;
    } else {
        // Queries defer karna jahan direct movement possible nahi hai
        int maxHeight = max(heights[aliceStart], heights[bobStart]); // Max height calculate karna
        int maxIndex = max(aliceStart, bobStart); // Max index nikalna
        deferredQueries[maxIndex].emplace_back(maxHeight, queryIndex);
    }
}

// Step 2: Buildings ko order mein process karna
for (int currentBuilding = 0; currentBuilding < n; ++currentBuilding) {
    // Min-Heap ke queries ko process karna jo current building se chhoti hain
    while (!minHeap.empty() && minHeap.top().first < heights[currentBuilding]) {
        int queryIndex = minHeap.top().second;
        minHeap.pop();
        result[queryIndex] = currentBuilding; // Current building ko answer ke roop mein assign karna
    }

    // Current building ke deferred queries ko priority queue mein add karna
    for (auto& query : deferredQueries[currentBuilding]) {
        minHeap.emplace(query.first, query.second);
    }
}

return result; 
 
    }
};