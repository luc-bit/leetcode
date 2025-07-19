class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // Đảm bảo nums1 là mảng ngắn hơn
 if (nums1.size() > nums2.size()) {
     return findMedianSortedArrays(nums2, nums1);
 }

 int m = nums1.size();
 int n = nums2.size();
 int low = 0, high = m;

 while (low <= high) {
     int i = (low + high) / 2;
     int j = (m + n + 1) / 2 - i;

     int maxLeftA = (i == 0) ? INT_MIN : nums1[i - 1];
     int minRightA = (i == m) ? INT_MAX : nums1[i];

     int maxLeftB = (j == 0) ? INT_MIN : nums2[j - 1];
     int minRightB = (j == n) ? INT_MAX : nums2[j];

     if (maxLeftA <= minRightB && maxLeftB <= minRightA) { // đây chính là bước áp dụng binary seach vào bài toán
                                                           // chúng ta tìm thấy điểm chia hợp lý sao cho tất cả left bé hơn right 
         if ((m + n) % 2 == 0) {
             return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
         }
         else {
             return max(maxLeftA, maxLeftB);
         }
     }
     else if (maxLeftA > minRightB) {
         high = i - 1; // Giảm i dịch về bên phải
     }
     else {
         low = i + 1;  // Tăng i dịch về bên trái
     }
 }

 return 0.0; // Trường hợp không bao giờ xảy ra
    }
};