/* Using maps to optimize target sum problem
 * C++14
 *
 * References:
 * https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/#
 * https://leetcode.com/problems/two-sum/description/
 *
 */
#include <map>
#include <iostream>

using namespace std;

int main() {
    // declare map
    map<int,int> map1;
    // initialize key-value pairs
    map1[0] = 1;
    map1[1] = 2;
    map1[2] = 3;
    map1[3] = 4;
    int Target = 5;

    auto it = map1.begin();

    // print out key-value pair
    // if based on conventional array sequence
    for(int i =0; i < map1.size();i++){
        cout << "key: " << i << " , value: " << map1[i] << endl;
    }
    cout << endl;

    // if based on other declared type like string/int/char/etc
    while(it != map1.end()){
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
        ++it;
    }
    cout << endl;

    // map1 [1,2,3,4]
    map<int,int> map2;
    // reset iterator
    it = map1.begin();
    while(it != map1.end()){
        int curr = it->second;
        // Two sum problem:
        // Target = curr + x
        // x = Target - curr
        int x = Target - curr;
        if(map2.count(x)){
            cout << "[" << it->first << "," << map2.at(x) << "]" << endl;
            //break;
        }
        map2.insert(pair<int, int>(it->second, it->first));
        it++;
    }
    // Time complexity: O(n) //where n is the size of map.
    // Auxiliary Space: O(n)

    return 0;
}

/*  Brute force approach
 *  O(n^2) time complexity approach
 * for(int i = 0; i < nums.size() ; i++ ) {
            for(int j = i + 1; j < nums.size() ; j++){
                if(target == nums[i] + nums[j]){
                    return {i,j};
                }
            }
        }
 */
