#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Helper function for recursive backtracking.
void helper(vector<int> &weight,int s, int total_apples,int total_weight,int ram_prcntg, int sham_prcntg, int rahim_prcntg){
    vector<int> ans;
    int wt = (accumulate(ans.begin(),ans.end(),0)*100)/total_weight;

    //Check if the combination is proportional to the moneny spent by each person.
    if( wt < ram_prcntg + 5 && wt > ram_prcntg + 5){ //(+5 for approx)
        cout<<"Ram: "<< ans[0]<<ans[1]<<ans[2]<<endl;
    }
    if( wt < sham_prcntg + 5 && wt > sham_prcntg + 5){
        cout<<"Sham: "<< ans[0]<<ans[1]<<ans[2]<<endl;
    }
    if( wt < rahim_prcntg + 5 && wt > rahim_prcntg + 5){
        cout<<"Rahim: "<< ans[0]<<ans[1]<<ans[2];
    }
     
    // Recursive backtracking to explore all combinations of apples.
    for(int i = s ; i<3 ; i++){
        ans.push_back(weight[i]); // Include current apple in the combination.
        helper(weight,s+1,total_apples,total_weight,ram_prcntg,sham_prcntg, rahim_prcntg); //Recursive call.
        ans.pop_back(); // Backtrack to explore other combinations.
        }
}

int main()
{
    int total_amount;
    cin>>total_amount; //Input for total amount spent.
    int Ram,Sham,Rahim;
    cin>>Ram>>Sham>>Rahim; //Input for amount spent by Ram, Sham, Rahim respectively.
    
    int total_apples;
    cin>>total_apples;
    vector<int> weight; //Vector to store all the weight of apples.
    for(int i = 0 ; i<total_apples ; i++){
        int temp = 0;
        cin>>temp;
        weight.push_back(temp);
    }
    
    //Calculating percentage of  (money spent by each person/total amount spent).
    int ram_prcntg = (Ram/total_amount)*100;
    int sham_prcntg = (Sham/total_amount)*100;
    int rahim_prcntg = (Rahim/total_amount)*100;
    //total weight of apples brought.
    int total_weight = accumulate(weight.begin(),weight.end(),0);

    //Function call
    helper(weight,0,total_apples,total_weight,ram_prcntg,sham_prcntg,rahim_prcntg);

    return 0;
}