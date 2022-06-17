#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate_array(vector< vector<int>> &mat)
{
    int n=mat.size();
    vector<vector<int>> rotate(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            rotate[j][n-i-1]=mat[i][j];
        }
    }
    return rotate;
}


int main()
{
    vector< vector<int>> v;
    v={{1,2,3},{4,5,6},{7,8,9}};
    vector< vector<int>> rotate=rotate_array(v);
    for(int i=0;i<rotate.size();i++)
    {
        for(int j=0;j<rotate[0].size();j++)
        {
            cout<<rotate[i][j]<<" ";
        }
        cout<<"/n";
    }

}