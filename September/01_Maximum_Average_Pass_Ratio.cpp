// 1792. Maximum Average Pass Ratio


class Solution {
public:
    using P = pair<double,int>;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P> pq;

        for(int i=0; i<n; i++){
            double PR = (double)classes[i][0]/classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = newPR - PR;
            pq.push({delta, i});
        }

        while(extraStudents--){
            auto [delta, idx] = pq.top();
            pq.pop();

            classes[idx][0]++;
            classes[idx][1]++;

            double PR = (double)classes[idx][0]/classes[idx][1];
            double newPR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double diff = newPR - PR;
            pq.push({diff, idx});
        }

        double result = 0.0;
        for(int i=0; i<n; i++){
            auto [delta, idx] = pq.top();
            pq.pop();
            result += (double)classes[idx][0]/classes[idx][1];
        }
        
        return result/n;
    }
};