//Fills array with "Empty" to keep track of empty squares
let input = [9];
for(let i = 0; i  < 9; i++){
    input[i] = "empty";
}

var boxes = document.getElementsByClassName("box");
let game = 0;
let win = false;

for(let i = 0; i < boxes.length; i++){
    //If a box is clicked it will fill it with X
    boxes[i].addEventListener("click", function(){
        let temp = parseInt(this.id - 1);
        if(input[temp] == "empty"){
            input[temp] = "X";
            console.log("Input Changed to X");
            this.src = "images/X.png"
            game++;

            checkWin("X", "You");

            let found = false;

        //Will pick a random box to fill with O
        while(!found && game != 9 && win == false){
            let OSpot = Math.floor(Math.random() * 9) + 1;
            temp = OSpot - 1;
            if(input[temp] == "empty"){
                input[temp] = "O";
                console.log("Input Changed to O");
                document.getElementById(OSpot).src = "images/O.png"
                found = true;
                game++;
                checkWin("O", "AI");
            }
        }
        }

        //If there is no winner, show Tie
        if(game == 9 && win == false){
            document.getElementById("Winner").innerHTML = "Tie!";
        }
    });
}

//Will check win conditions
function checkWin(letter, player){
    if(input[0] == letter){
        if((input[1] == letter && input[2] ==letter) || (input[3] == letter && input[6] ==letter) || (input[4] == letter && input[8] ==letter)){
            document.getElementById("Winner").innerHTML = player + " Win!";
            win = true;
            console.log(1);
            return;
        }
    }
    if(input[1] == letter){
        if(input[4] == letter && input[7] == letter){
            document.getElementById("Winner").innerHTML =  player + " Win!";
            win = true;
            console.log(2);
            return;
        }
    }
    if(input[2] == letter){
        if(input[5] == letter && input[8] == letter){
            document.getElementById("Winner").innerHTML =  player + " Win!";
            win = true;
            console.log(3);
            return;
        }
    }
    if(input[3] == letter){
        if(input[4] == letter && input[5] == letter){
            document.getElementById("Winner").innerHTML =  player + " Win!";
            win = true;
            console.log(4);
            return;
        }
    }
    if(input[6] == letter){
        if((input[7] == letter && input[8] == letter) || (input[4] == letter && input[2] == letter)){
            document.getElementById("Winner").innerHTML =  player + " Win!";
            win = true;
            console.log(5);
            return;
        }
    }
}
