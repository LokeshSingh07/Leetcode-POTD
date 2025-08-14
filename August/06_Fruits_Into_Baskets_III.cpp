// 3479. Fruits Into Baskets III

class Solution {
public:
    void build(vector<int> &segmentTree, int i, int l, int r, vector<int> &baskets){
        if(l==r){
            segmentTree[i] = baskets[l];
            return;
        }

        int mid = l+(r-l)/2;
        build(segmentTree, 2*i+1, l, mid, baskets);
        build(segmentTree, 2*i+2, mid+1, r, baskets);

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
    }

    bool query(vector<int> &segmentTree, int i, int l, int r, int val){
        if(segmentTree[i] < val){
            return false;
        }
        if(l==r){
            segmentTree[i] = -1;
            return true;
        }

        int mid = l+(r-l)/2;
        bool placed = true;
        if(segmentTree[2*i+1] >= val){
            placed = query(segmentTree, 2*i+1, l, mid, val);
        }
        else{
            placed = query(segmentTree, 2*i+2, mid+1, r, val);
        }

        segmentTree[i] = max(segmentTree[2*i+1], segmentTree[2*i+2]);
        return placed;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segmentTree(4*n, -1);

        build(segmentTree, 0, 0, n-1, baskets);

        int unplaced = 0;
        for(auto fruit: fruits){
            if(!query(segmentTree, 0, 0, n-1, fruit)){
                unplaced++;
            }
        }

        return unplaced;
    }
};