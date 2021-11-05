import java.util.*;
import java.io.*;
import java.math.*;


class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(); //num values
        int vals[] = new int[n];
        int min, max;
        min = max = 0;
        for (int i = 0; i < n; i++) {
            vals[i] = in.nextInt();
            if (i == 0) {
                min = vals[i];
                max = vals[i];
            }
            else {
                if (vals[i] > max) max = vals[i];
                if (vals[i] < min) min = vals[i];
            }
        }
        int worstLoss = min - max;
        System.out.println(worstLoss);
    }
}
