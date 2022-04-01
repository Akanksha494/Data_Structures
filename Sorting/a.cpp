void subsets(vector<int> &A,vector<int> &res,vector<int> &subset,int index,int N)
{
	res.push_back(subset);
	for(int i=index;i<N;i++)
	{
		subset.push_back(A[i]);
		subsets(A,res,subset,i+1,N);
	
	    subset.pop_back();
    }
    return;
}

string solve(int N,vector<int>&A){
   vector<int>subset;
   vector<int> res;
   int mx=0;
   int index=0;
   subsets(A,res,subset,index,N);
   
   string s=to_string(subset);

   
   }

}