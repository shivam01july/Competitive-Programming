/******************************************/
/*              Binary Search             */
/******************************************/

#include <bits/stdc++.h>
using namespace std;


int BinarySearch1(vector<int> v, int key)
{
    int low = 0, high = v.size()-1, mid = 0;
    
    while((high - low) > 1)
    {
        mid = (high + low) / 2;
        
        if(v[mid] < key)
            low = mid + 1;
        else
            high = mid;
    }
    
    if(v[low] == key)
        return low;
    else if(v[high] == key)
        return high;
    else
        return -1;
}


int BinarySearch2(vector<int> v, int key)
{
    int start = 0, end = v.size()-1, mid = 0;
    
    while(start <= end)
    {
        // Decrease and Conquer algo
        mid = start + ((end - start) / 2);
        
        // Check if key is present at mid
        if(v[mid] == key)
            return mid;
        
        // If x greater, ignore left half    
        else if(v[mid] < key)
            start = mid + 1;
            
        // If x is smaller, ignore right half    
        else
            end = mid - 1;
    }
    
    // If we reach here, then element was not present
    return -1;    
}


int main()
{
    vector<int> v {2, 3, 5, 10, 15, 23, 40};
    int key, res;
    
    cout << "List: ";
    for(auto it : v)
        cout << it << " ";
    cout << endl;    
    
    
    key = 23;
    res = BinarySearch1(v, key);
    if(res < 0)
        cout << key <<" is Not Found" << endl;
    else
        cout << key <<" is Found at index " << res << endl;
        
  
    key = 5;
    res = BinarySearch2(v, key);
    if(res < 0)
        cout << key <<" is Not Found" << endl;
    else
        cout << key <<" is Found at index " << res << endl;
        
        
    key = 1;
    res = BinarySearch2(v, key);
    if(res < 0)
        cout << key <<" is Not Found" << endl;
    else
        cout << key <<" is Found at index " << res << endl;

    return 0;
}
