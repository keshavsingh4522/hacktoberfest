import java.util.LinkedList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        /**
         * Iterative Combination Algorithm solution for finding all possible combination of k
         * sized sublist of elements for a given array or list of size n ===> 2<=k<=n
         */
        int n = 7;
        int k = 4;

        iterativeCombinationAlgorithm(n, k);
    }

    private static void iterativeCombinationAlgorithm(int n, int k) {
        if (n >= k && k >= 2) {
            /** taking index 0 for "for loop that iterates n-k times" to be implemented as current starting index
             * as index 0 thereby populating possible combinations in otherIndexesOfUnitList array.
             */
            for (int currentStartingIndex = 0; currentStartingIndex <= n - k; ++currentStartingIndex) {

                /** dummy array of indexes of smallest pair of k-1 elements where the first index of the list is
                 *  currentStartingIndex
                 */
                int[] otherIndexesOfUnitList = new int[k - 1];

                /**populating the first pair of k-1 elements setting index 0 which is position 1 of
                 * starting pair of k pair integers
                 */
                for (int index = 0; index < otherIndexesOfUnitList.length; ++index) {
                    if (index == 0)
                        otherIndexesOfUnitList[index] = currentStartingIndex + 1;
                    else
                        otherIndexesOfUnitList[index] = otherIndexesOfUnitList[index - 1] + 1;
                }

                /** list of all pairs of possible combination k integer pairs from 0 to n-1
                 * for currentStartingIndex iteration
                 */
                List<List<Integer>> listOfPairs = new LinkedList<>();

                /**
                 * Brute force while loop to find all k integer pairs and store in nested list
                 */
                while (true) {

                    /**
                     * list that stores integer of current k pairs of integers consisting
                     * of the starting index and @otherIndexesUnitList array of size k-1
                     */
                    List<Integer> currentPair = new LinkedList<>();

                    /**
                     * adding currentStartingIndex to current pair
                     */
                    currentPair.add(currentStartingIndex);

                    /**
                     * adding index position 1 to k - 2 to current pair list from otherIndexesUnitList array
                     */
                    for (int middleIndex = 0; middleIndex < otherIndexesOfUnitList.length - 1; ++middleIndex)
                        currentPair.add(otherIndexesOfUnitList[middleIndex]);

                    /**
                     * for loop that add increasing values of currentLastIndexes up to n-1
                     */
                    for (int currentLastIndex = otherIndexesOfUnitList[k - 2]; currentLastIndex < n; ++currentLastIndex) {
                        /**
                         * adding last of element otherIndexesOfUnitList
                         */
                        currentPair.add(currentLastIndex);
                        /**
                         * adding generated pair of k integers to list
                         */
                        listOfPairs.add(new LinkedList<>(currentPair));
                        /**
                         * removing last index of current to add incremented value of currentLastIndex
                         * in the kth position
                         */
                        currentPair.remove(currentPair.size() - 1);
                        /**
                         * condition checking if currentLastIndex has reached the last index of for loop and updating
                         * last element otherIndexesOfUnitList array
                         */
                        if (currentLastIndex == n - 1)
                            otherIndexesOfUnitList[k - 2] = currentLastIndex;
                    }
                    System.out.println(listOfPairs); // line that prints listOfPairs
                    /**
                     * offset variable for checking if an index of an array has attained
                     * its maximum possible value for k pair of integers
                     */
                    int j = 0;

                    /**
                     * this variable is used to track the index of the array element that has not
                     * attained its maximum possible value
                     */
                    int targetIndex = -1;

                    /**
                     * for loop that iterates through the array backwards to find first element's index that has not
                     * attained its maximum value
                     */
                    for (int index = otherIndexesOfUnitList.length - 1; index >= 0; --index) {
                        /**
                         * condition that checks if current
                         * element of array has has attained its possible max
                         */
                        if (otherIndexesOfUnitList[index] != n - j - 1) {
                            targetIndex = index;
                            break;
                        }
                        ++j;
                    }
                    /** condition checking if there was an element in the array that
                     * has not attained its possible max
                     * for loop increases all elements of the array by 1 starting from the element at target index
                     */
                    if (targetIndex != -1) {
                        for (int currentIndex = targetIndex; currentIndex < otherIndexesOfUnitList.length; ++currentIndex) {
                            if (currentIndex == targetIndex)
                                ++otherIndexesOfUnitList[currentIndex];
                            else
                                otherIndexesOfUnitList[currentIndex] = otherIndexesOfUnitList[currentIndex - 1] + 1;
                        }
                    }
                    /**
                     * if condition is false all possible k integer pairs for that currentStartingIndex
                     * value have been found and stored to list
                     */
                    else
                        break;
                }
                /**
                 * program continues for next currentStartingIndex
                 */
            }
        }
    }
}
