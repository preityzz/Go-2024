#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceBalls(const vector<int> &position, int m, int minDist)
{
    int count = 1; // place the first ball
    int last_position = position[0];

    for (int i = 1; i < position.size(); i++)
    {
        if (position[i] - last_position >= minDist)
        {
            count++;
            last_position = position[i];
            if (count == m)
            {
                return true;
            }
        }
    }
    return false;
}

int maxDistance(vector<int> &position, int m)
{
    sort(position.begin(), position.end());

    int left = 1;                              // smallest possible distance
    int right = position.back() - position[0]; // largest possible distance
    int best = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canPlaceBalls(position, m, mid))
        {
            best = mid;
            left = mid + 1; // try for a bigger minimum distance
        }
        else
        {
            right = mid - 1; // try for a smaller minimum distance
        }
    }

    return best;
}

int main()
{
    vector<int> position1 = {1, 2, 3, 4, 7};
    int m1 = 3;
    cout << maxDistance(position1, m1) << endl; // Output: 3

    vector<int> position2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;
    cout << maxDistance(position2, m2) << endl; // Output: 999999999

    return 0;
}
