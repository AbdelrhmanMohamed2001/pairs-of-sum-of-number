using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
void get_Pairs(int arr[], int n, int target)                   //get pairs
{

    unordered_map<int, int> hash;      // storing elements in map(hash table)

    for (int i = 0; i < n; i++)
    {
        int num_2=arr[i];
        int num_1 = target - num_2;
        if (hash.find(num_1) != hash.end())
        {
            int count = hash[num_1];
            for (int j = 0; j < count; j++)
                cout <<"The pairs are [ " << num_1 << " , "<< num_2 << " ]" << endl;
        }

        hash[arr[i]]++;
    }
}


int get_Pairs_Count(int arr[], int n, int target)              //number of pairs
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[j] + arr[i] == target)
                count++;

    return count;
}

bool existing_pairs(int arr[], int n, int target)                    //valid pairs or not
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] + arr[i] == target)
            {
                cout << "Pair with a given sum " << target<< endl;

                return 1;
            }
        }
    }

    return 0;
}


int main()
{
    int arr[] = {8,5,2,1,3,7,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target ;
    cout<<"what's your target"<<endl;
    cin>>target;

    if (existing_pairs(arr, n, target))
    {
        cout << "Valid pair exists" << endl;
    }
    else
    {
        cout << "No valid pair exists for " << target << endl;
    }

    get_Pairs(arr, n, target);

    cout << "Count of pairs is "<< get_Pairs_Count(arr, n, target);
    return 0;
}
