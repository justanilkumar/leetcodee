class Solution {

    boolean isValidSpeed(int[] piles, int mid, int h) {

        int time = 0;

        for (int num : piles) {

            time = time + num / mid;

            // if not perfectly divisible, add 1 extra hour
            if (num % mid != 0) {
                time++;
            }
        }

        return time <= h;
    }

    public int minEatingSpeed(int[] arr, int h) {

        int low = 1;
        int high = arr[0];

        // find maximum pile
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > high) {
                high = arr[i];
            }
        }

        // binary search
        while (low < high) {

            int mid = low + (high - low) / 2;

            if (isValidSpeed(arr, mid, h) == true) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}