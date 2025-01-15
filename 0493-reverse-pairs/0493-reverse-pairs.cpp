class Solution {
public:
    int ans = 0; // To store reverse pair count.

    void merge(vector<int> &nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> l(n1), r(n2);

        for (int i = 0; i < n1; i++)
            l[i] = nums[left + i];
        for (int i = 0; i < n2; i++)
            r[i] = nums[mid + 1 + i];

        // Count reverse pairs before merging
        int i = 0, j = 0;
        while (i < n1) {
            while (j < n2 && l[i] > 2LL * r[j]) {
                j++;
            }
            ans += j; // Add all elements in `r` satisfying the condition.
            i++;
        }

        // Merge the two sorted arrays
        i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j])
                nums[k++] = l[i++];
            else
                nums[k++] = r[j++];
        }

        while (i < n1)
            nums[k++] = l[i++];

        while (j < n2)
            nums[k++] = r[j++];
    }

    void mergesort(vector<int> &nums, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        mergesort(nums, 0, n - 1);
        return ans;
    }
};
