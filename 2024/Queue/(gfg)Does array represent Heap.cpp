class Solution
{
public:
    // using queue
    // front pe hmesha parent hoga root ka
    bool isMaxHeap(int arr[], int n)
    {
        queue<int> q;
        q.push(arr[0]);

        for (int i = 1; i < n; i++)
        {
            int front = q.front();
            q.pop();
            if (arr[i] > front)
                return false;

            q.push(arr[i]);

            if (i + 1 < n)
            {
                if (arr[i + 1] > front)
                    return false;

                q.push(arr[i + 1]);
                i++;
            }
        }
        return true;
    }
};