class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        if (n == 0)
            return 0;

        std::vector<std::pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            int dist = target - position[i];
            double time = static_cast<double>(dist) / speed[i];
            cars.push_back({ position[i], time });
        }

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; // Sort in descending order based on position
        });

        int fleets = 1;
        double currTime = cars[0].second;

        for (int i = 1; i < n; i++) {
            if (cars[i].second > currTime) {
                fleets++;
                currTime = cars[i].second;
            }
        }

        return fleets;
    }
};
