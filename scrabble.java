import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static int score(String word) { //calculating points for a word
        String row1 = "1eaionrtlsu";
        String row2 = "2dg";
        String row3 = "3bcmp";
        String row4 = "4fhvwy";
        String row5 = "5k";
        String row6 = "8jw";
        String row7 = "1qz";
        int score = 0;
        for (int i = 0; i < word.length() ; i++)
        {
            if ( row1.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row1.charAt(0)));
            if ( row2.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row2.charAt(0)));
            if ( row3.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row3.charAt(0)));
            if ( row4.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row4.charAt(0)));
            if ( row5.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row5.charAt(0)));
            if ( row6.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row6.charAt(0)));
            if ( row7.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row7.charAt(0))) * 10;
        }
        return score;
    } 

    public static Set<String> permute(String chars) {
    /*SOURCE: https://stackoverflow.com/questions/9666903/every-combination-of-character-array*/
        Set<String> set = new HashSet<>();
        // Termination condition: only 1 permutation for a string of length 1
        if (chars.length() == 1)
        {
            set.add(chars);
        }
        else
        {
            // Give each character a chance to be the first in the permuted string
            for (int i=0; i<chars.length(); i++)
            {
                // Remove the character at index i from the string
                String pre = chars.substring(0, i);
                String post = chars.substring(i+1);
                String remaining = pre+post;

                // Recurse to find all the permutations of the remaining chars
                for (String permutation : permute(remaining))
                {
                    // Concatenate the first character with the permutations of the remaining chars
                    set.add(chars.charAt(i) + permutation);
                }
            }
        }
        return set;
    }

    public static void main(String args[]) {
        
        /*The inputs*/
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        if (in.hasNextLine()) {
            in.nextLine();
        }
        Set<String> Dico = new HashSet<>();
        for (int i = 0; i < N; i++) {
            String w = (in.nextLine());
            Dico.add (w); //add words to dico
        }
        String chars = in.nextLine(); //getting the letters to play

        
        /*Print Dictionnary*/
        System.err.println("Dico : ");
        for (String s : Dico) {
            System.err.println("\t"+s); 
        }

        /*Print letters to play*/
        System.err.println("Letters : ");
        System.err.println("\t"+chars); 

        /*Generating all possible words from these letters*/
        Set<String> Words = permute(chars); //
        Set<String> Clean = new HashSet<>();

        /*clean words to keep only the ones matched in the dictionary*/
        for (String s : Words) {
            if (Dico.contains(s)) {
                Clean.add(s);
            }                                                
        }

        /*choosing the word to play*/
        int points = 0;
        String output= "";
        for (String s : Clean) { 
            if (score(s) > points) {
                points = score(s); 
                output = s;
            }
        }
        System.out.println(output);
    }
}
