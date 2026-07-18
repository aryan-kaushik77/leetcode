class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=1;
        int num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(num==nums[i]){
                freq++;
            }
            else{
                freq--;
            }
            if(freq==0){
                num=nums[i];
                freq=1;
            }
        }
    return num;
    }
};


// void merge(int arr[], int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     int L[n1], R[n2];

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];

//     for (int i = 0; i < n2; i++)
//         R[i] = arr[mid + 1 + i];

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j])
//             arr[k++] = L[i++];
//         else
//             arr[k++] = R[j++];
//     }

//     while (i < n1)
//         arr[k++] = L[i++];

//     while (j < n2)
//         arr[k++] = R[j++];
// }

// void mergeSort(int arr[], int left, int right) {
//     if (left >= right)
//         return;

//     int mid = left + (right - left) / 2;

//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid + 1, right);

//     merge(arr, left, mid, right);
// }
// int majorityElement(int* nums, int numsSize) {
//     mergeSort(nums,0,numsSize-1);
//     int count=1;
//     if(numsSize==1){
//         return nums[0];
//     }
//     for(int i=1;i<numsSize;i++){
//         if(nums[i]==nums[i-1]){
//             count++;
//             if(count>numsSize/2){
//                 return nums[i];
//             }
//         }
//         else {
//             count=1;
//         }
        
//     }
//     return -1;
// }