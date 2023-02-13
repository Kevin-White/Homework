function Order(){
    //This for loop allows user to input 5 items, into the input array.
let input = [5];
for(let i = 0; i < 5; i++){
    input[i] = parseInt(
        prompt("Enter your Input " + (i+1) + "/5"));
}
    //This for loop will order the array from smallest to largest using bubble sort.
for(let i = 4; i >= 0; i--){
    let hold = i;
    while(input[hold] > input[hold + 1] && hold < 5){
        let temp = input[hold + 1];
        input[hold + 1] = input[hold];
        input[hold] = temp;
        hold++;
    }
}

//Displays 5 inputs in order inside of the "output" HTML element
document.getElementById("output").innerHTML = `<label>Numbers in Order: </label>${input[0]} ${input[1]} ${input[2]} ${input[3]} ${input[4]}`;
}