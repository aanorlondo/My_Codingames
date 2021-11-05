package main

import "fmt"
import "os"
import "bufio"

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 func printAnswer(answer []string, N int, players []string) { //print the answer
    for i:=0; i<N ; i++ {
        fmt.Fprintln(os.Stderr, "Player", i+1,"(", players[i],")")
        fmt.Println(answer[i])
    }
 }

func Min(x int, y int) int { //return the minimum between two integers
    if x <= y {
        return x
    }
    return y
}

func Abs(x int) int { //absolute value for an integer (only for float is native in go)
    if x < 0 {
        return -x
    }
    return x
}

func pos(p byte, L int, layout string) int { //get position in the layout
    for i := 0 ; i < L ; i++ {
        if p == layout[i] {
            return i+1 //found
        }
    }
    return 0 //not found
}

func len(i int, j int, L int, layout string) int { //get distance between two positions in the layout
    return Min ( L - (Abs(i-j) % L) , (Abs(i-j) % L) ) //minimum distance regarding the circular shape
 }

 func calculate(current byte, next byte, L int, layout string) int { 
     //to avoid stack of calls in the main
    return len ( pos(current,L,layout), pos(next,L,layout), L, layout )
 }

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Buffer(make([]byte, 1000000), 1000000)

    var L int //layout length
    scanner.Scan()
    fmt.Sscan(scanner.Text(),&L)
    
    scanner.Scan()
    F := scanner.Text() //layout pattern
    var N, K int // N : players / K : time
    scanner.Scan()
    fmt.Sscan(scanner.Text(),&N, &K)
    
    players := [] string{}; //all the mates' paths
    answer := [] string{}; //to answer for each path
    var unknown byte = '#'; //wasn't sure, the text said '#' but the example showed '?'

    for i := 0; i < N; i++ {
        scanner.Scan()
        crewmate := scanner.Text()
        players = append(players, crewmate) //putting all paths in a slice
    }
    //some prints to make it clear
    fmt.Fprintln(os.Stderr, "Layout = ", F)
    fmt.Fprintln(os.Stderr, "Length = ", L)
    fmt.Fprintln(os.Stderr, "Time = ", K)

    for i := 0; i < N; i++ { //to scroll all players
        var sus bool = false
        
        for j := 0; j < K-1 ; j++ { //to scroll each player's path (crewmate string)

            if players[i][j] != unknown { //current position is known
                if players[i][j+1] != unknown { //next position is also known
                            //regular case, a valid distance is 1
                            if calculate(players[i][j], players[i][j+1], L, F) > 1 {
                                sus = true;
                                break
                            }
                } else { //next position in trace is unknown (#)
                            var u int = 0 
                            for players[i][j+u+1] == unknown && j+u+1 < K {
                                u++ //count number of unknown positions
                            }
                            if calculate(players[i][j], players[i][j+u+1], L, F) > u+1 {
                                sus = true; //next know position shouldnt be further than u + 1
                                break;
                            }
                        }
            }
        } //end j for
        if sus {
            answer = append(answer, "SUS")
        } else {
            answer = append(answer, "NOT SUS")
        }
        
    } //end i for
    printAnswer(answer, N, players)// Write answer to stdout
}
