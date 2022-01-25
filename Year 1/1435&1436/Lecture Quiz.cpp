int sequentialSearch(a, arraySize, targetValue){
    int position = -1;
    for(int i = 0; i < arraySize; i++){
        if(a[i] == targetValue){
            position = i;
            break;
        }
    }
    return position;
}
