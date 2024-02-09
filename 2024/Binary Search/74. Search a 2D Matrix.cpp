class Solution
{
public:
    // brute ofrece O(n^2)(simple 2 lopps and manuaallly check)
    // this is better O(n*log m)(go to each row search like 1D)
    // optimized o(log(m*n))(eliminating row and column)
    //*****************************************************************

    // very easy go to each row search like 1D
    //  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     for(int i=0;i<matrix.size();i++){

    //        int s=0;int e=matrix[i].size()-1;
    //        //s=0 e=n-1;

    //        while(s<=e){
    //            int  mid=s+(e-s)/2;

    //            if(matrix[i][mid]==target)
    //            return true;

    //            else if(matrix[i][mid]>target)
    //            e=mid-1;
    //            else
    //            s=mid+1;
    //        }
    //    }
    //    return false;

    // eliminating a row or a column
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rowsize = matrix.size();
        int colsize = matrix[0].size();

        int startrow = 0;
        int lastcol = colsize - 1;

        while (startrow < rowsize && lastcol >= 0)
        {
            int mid = matrix[startrow][lastcol];

            if (mid == target)
                return true;

            else if (mid > target)
                lastcol--;
            else
                startrow++;
        }

        return false;
    }
};