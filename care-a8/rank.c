
void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    float one,two,three,four;
    int idx,idx2,idx3;
    float temp,temp2,temp3,temp4;
    int rep=N-4;
    for (i = 0; i < rep; i+=4) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        idx=i+1;
        idx2=i+2;
        idx3=i+3;
        one = F[i];
        two = F[idx];
        three = F[idx2];
        four = F[idx3];
        for (j = 0; j < rep; j+=4) {
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (one < temp4) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (two < temp4) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;
            (three < temp4) ? rank3++ : rank3;
            (four < temp) ? rank4++ : rank4;
            (four < temp2) ? rank4++ : rank4;
            (four < temp3) ? rank4++ : rank4;
            (four < temp4) ? rank4++ : rank4;
        }
        for(;j<N;j++){
            temp=F[j];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
        }
        R[i] = rank;
        R[idx] = rank2;
        R[idx2] = rank3;
        R[idx3] = rank4;


        temp_avg += (one + two + three +four);

        if (one >= 50.0) {
            temp_passing_avg += one;
            temp_num_passed += 1;
        }
        if (two >= 50.0) {
            temp_passing_avg += two;
            temp_num_passed += 1;
        }
        if (three >= 50.0) {
            temp_passing_avg += three;
            temp_num_passed += 1;
        }
        if (four >= 50.0) {
            temp_passing_avg += four;
            temp_num_passed += 1;
        }
    }


    
    for(;i<N;i++){
        one = F[i];
        temp_avg += one;
        if (one >= 50.0) {
            temp_passing_avg += one;
            temp_num_passed += 1;
        }
        rank=1;
        for(j=0;j<N;j++){
            if (one < F[j]) {
                rank++;
            }
        }
        R[i]=rank;
    }




    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks


