import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int S = in.nextInt();
        int M = in.nextInt();
        int Smax[] = new int[S]; //max clients per service
        int Sinstances[] = new int[S]; //number of running instances per service (0 init)

        for (int i = 0; i < S; i++) { 
            Smax[i] = in.nextInt(); //saving values in table
        }
        int ClientsPerService[][] = new int[M][S]; //matrix of clients and time

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < S; j++) {
                ClientsPerService[i][j] = in.nextInt(); //saving new connected clients for each service
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < S; j++) {
                //how much do we need now
                int scale = (int) Math.ceil( (double) ClientsPerService[i][j] / Smax[j]);
                //print the difference with what we had before
                System.out.print(scale - Sinstances[j]);
                //update the current instances after scaling
                Sinstances[j] = scale;
                if (j+1 < S)
                {
                    System.out.print(" ");
                }
            }
            System.out.print("\n");
        }
    }
}
