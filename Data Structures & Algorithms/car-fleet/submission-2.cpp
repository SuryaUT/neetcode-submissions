class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //car behind can only catch up if speed is greater than front car and distance between the cars/speed of behind car <= distance between front car and end over frint car speed

        //sort array descending based on position
        //compute how many time units till reaches object in front of it (goal for first, cars for the remaining) 
        //if time unit less than or equal to time unit for object in front to make it to goal then it joins fleet so keep fleet counter constant, but if not, then doesn't make fleet and therefore starts a new fleet, so increase counter. and you actually only need to compare with the leading car in the current fleet.
        
        vector<pair<int,int>> paired;
        for(int i = 0; i < position.size(); i++){
            paired.emplace_back(position[i],speed[i]);
        }

        sort(paired.begin(), paired.end());

        for(int i = 0; i < position.size(); i++){
            position[i] = paired[i].first;
            speed[i] = paired[i].second;
            cout << position[i] << ", " << speed[i] << endl;
        }

        int fleetCount = 1;
        int leaderI = 0;
        int len = position.size();
        double leaderTimeToGoal = static_cast<double>(target - position[len - 1]) / speed[len - 1];

        for(int i = len - 1; i >= 0; i--){
            double currTimeToGoal = static_cast<double>(target-position[i])/speed[i];
            if(currTimeToGoal > leaderTimeToGoal){
                fleetCount++;
                leaderTimeToGoal = currTimeToGoal;
            }
        }

        return fleetCount;
    }
};
