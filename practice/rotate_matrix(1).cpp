#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> & mat)
{
    int n=mat.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }

    for(int i=0;i<n;i++)
    {
        reverse(mat.begin(),mat.end());
    }
    return mat;
}
int main()
{
    vector<vector<int>> v;
    v={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr=rotate(v);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();i++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"/n";
    }
    return 0;

}
