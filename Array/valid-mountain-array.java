/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*/

class Solution {
    public boolean validMountainArray(int[] arr) {
        int i = 0, mount = 0;
        int n = arr.length;
        if(n<3) return false;
        while(i<n-1 && mount==0) {
            if(arr[i+1]==arr[i]) return false;
            else if(arr[i+1] < arr[i]) {
                if(i==0) return false;
                mount = 1;
            }
            i++;
        }
        while(i<n-1 && mount==1) {
            if(arr[i+1] >= arr[i]) return false;
            i++;
        }
        return mount == 1;
    }
}
