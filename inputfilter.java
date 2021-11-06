import java.util.*;
class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in); String S = in.nextLine();
        String[] words = S.split(" ");
        for(int i = 0 ; i < words.length ; i++)
        {   for(int j = 2; j < words[i].length(); j = j+3 ) {
                System.out.print(words[i].charAt(j)); } 
            if (i+1 < words.length) System.out.print(" ");
}}}
