import java.util.*;

class Letter {
    char c; int nb;
    public Letter(char c) {
        this.c = c; this.nb = 1; }
}
class Word {
    String w; int points; int position;
    public Word(String w, int pos) {
        this.w = w; this.position = pos; }
}

class Solution {
    public static Set<Letter> buildSet(String chars) {
        Set<Letter> set = new HashSet<>();
        for (int i = 0; i < chars.length() ; i++) {
            Boolean exist = false;
            for(Letter l : set) {
                if (l.c == chars.charAt(i)) {
                    l.nb++; exist = true;
                }
            } if (!exist) set.add(new Letter(chars.charAt(i)));
        } return set;
    }
    public static boolean include(Set<Letter> set, char c, boolean dec) {
        for (Letter l : set) {
            if (l.c == c && l.nb > 0) {
                if (dec) l.nb--;
                return true;        
            }
        } return false;
    }
    public static Set<Word> filter(String chars, Set<Word> dico) {
        Set<Word> set = new HashSet<>();
        for (Word s : dico) {
            if (s.w.length() <= chars.length()) {
                Set<Letter> letters = buildSet(chars);
                boolean playable = true; Word word = s;
                for (int i = 0 ; i < s.w.length() && playable ; i ++) {
                    if (!include(letters,s.w.charAt(i),true))  playable = false;
                } if (playable) {
                    word.points = points(word.w); set.add(word);
                } letters.clear();
            }
        } return set;
    }
    public static int points(String word) { 
        String row1 = "1eaionrtlsu";    String row2 = "2dg";
        String row3 = "3bcmp";      String row4 = "4fhvwy";
        String row5 = "5k";         String row6 = "8jw";
        String row7 = "1qz";        int score = 0;
        for (int i = 0; i < word.length() ; i++) {
            if ( row1.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row1.charAt(0)));
            if ( row2.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row2.charAt(0)));
            if ( row3.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row3.charAt(0)));
            if ( row4.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row4.charAt(0)));
            if ( row5.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row5.charAt(0)));
            if ( row6.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row6.charAt(0)));
            if ( row7.indexOf(word.charAt(i)) != -1) score += Integer.parseInt(String.valueOf(row7.charAt(0))) * 10;
        } return score;
    }
    public static int max(Set<Word> set) {
        int max = 0;
        for (Word w : set) {
            if (w.points > max) max = w.points;
        } return max;
    }
    public static Set<Word> pick(Set<Word> set) {
        int max = max(set);
        Set<Word> Best = new HashSet<>();
        for (Word word : set) {
            if (word.points >= max) Best.add(word);
        } return Best;
    }
    public static Word play(Set<Word> set) {
        Word min = new Word("",0);
        if (set.iterator().hasNext()) {
            min = set.iterator().next();
            if (set.size() == 1) return set.iterator().next();
        }
        for (Word word : set) {
            if (word.position <= min.position) min = word;
        } return min;
    }
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        if (in.hasNextLine()) in.nextLine();
        Set<Word> Dico = new HashSet<>();
        for (int i = 0; i < N; i++) {
            Dico.add( new Word(  in.nextLine() , i+1));
        }
        String Chars = in.nextLine(); in.close();
        Set<Word> Words = filter(Chars,Dico); Word output;
        if (Words.size() > 1) output = play(pick(Words));
        else output = Words.iterator().next();
        System.out.println(output.w);
        Words.clear(); Dico.clear();
    }
}
