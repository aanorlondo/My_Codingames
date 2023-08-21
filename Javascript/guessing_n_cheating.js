var answers = {};
const R = parseInt(readline());
for (let i = 1; i <= R; i++) {
    const line = readline();
    const bob = line.split(" ")[0];
    const alice = [line.split(" ")[1], line.split(" ")[2]].join(" ");
    answers[i] = { "bob": bob, "alice": alice };
}

var answer = parseInt(answers[R]["bob"]);
var coherence = true;
var greater_known = Infinity;
var smaller_known = -Infinity;
var i = 0;
for (i = 1; i <= R && coherence; i++) {
    bob = parseInt(answers[i]["bob"]);
    alice = answers[i]["alice"];
    coherence = (bob > answer && alice == "too high")
        || (bob < answer && alice == "too low")
        || (bob == answer && alice == "right on" && bob != greater_known && bob != smaller_known);

    switch (alice) {
        case "too high": {
            greater_known = Math.min(bob, greater_known);
            break;
        }
        case "too low": {
            smaller_known = Math.max(bob, smaller_known);
            break;
        }
    }
    console.error(`in round ${i}, bob proposed ${bob} and alice said ${alice}. final answer being ${answer}, coherence = ${coherence}`);
}

console.error(answers)
console.log(coherence ? "No evidence of cheating" : `Alice cheated in round ${i - 1}`);

