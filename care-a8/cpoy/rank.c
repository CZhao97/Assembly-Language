
// #include <stdlib.h>
// typedef struct{
//     int index;
//     int value;
// }nodearr;


// void merge(nodearr* ALR, nodearr* L, int left_length, nodearr* R, int right_length) {
//     int l = 0;
//     int r = 0;
//     for (int i = 0; i < left_length + right_length;) {

//         if (l == left_length){
//             ALR[i++].value = R[r++].value;
//             ALR[i++].index = R[r++].index;
//         }
//         else if (r == right_length){
//             ALR[i++].value = L[l++].value;
//             ALR[i++].index = L[l++].index;
//         }
//         else if(R[r].value > L[l].value){
//             ALR[i++].value=L[l++].value;
//             ALR[i++].index=L[l++].index;
//         }
//         else{
//             ALR[i++].value=R[r++].value;
//             ALR[i++].index=R[r++].index;
//         }

//     }
// }

// void merge_sort(nodearr* ALR, int length) {

//     if (length == 1)return;

//     int mid = length / 2;

//     nodearr* L = malloc(length*sizeof(nodearr));
//     nodearr* R = malloc(length*sizeof(nodearr));

//     int k = 0;

//     for (size_t i = 0; k < mid; i++){
//         L[i].value = ALR[k++].value;
//         L[i].index = ALR[k++].index;
//     }
//     for (size_t i = 0; k < length; i++){
//         R[i].value = ALR[k++].value;
//         R[i].index = ALR[k++].index;
//     }

//     merge_sort(L, mid);
//     merge_sort(R, length - mid);

//     merge(ALR, L, mid, R, length - mid);
//     free(L);
//     free(R);
// }



void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    float temp_arr[4]={0,0,0,0};
    float one;
    float two;
    float three;
    float four;



    // // init ranks
    // for (i = 0; i < N; i++) {
    //     R[i] = 1;
    // }

    // // compute ranks
    // for (i = 0; i < N; i++) {
    //     for (j = 0; j < N; j++) {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //     }
    // }

    // for (i = 0; i < N; i++) {
    //     rank = 1;
    //     for (j = 0; j < N-4; j+=4) {
    //         if (F[i] < F[j]) {
    //             rank++;
    //         }
    //         if (F[i] < F[j+1]) {
    //             rank++;
    //         }
    //         if (F[i] < F[j+2]) {
    //             rank++;
    //         }
    //         if (F[i] < F[j+3]) {
    //             rank++;
    //         }
    //     }
    //     for(;j<N;j++){
    //         if (F[i] < F[j]) {
    //             rank++;
    //         }
    //     }
    //     R[i] = rank;
    // }

    	
	// for (i = 0; i < N; i++) {
	//     // tmp_f = F[i];
	//     rank = 1;
	//     for (j = 0; j < N; j++) {
	//         if (F[i]< F[j]) {
	//             rank += 1;
	//         }
	//     }
    // 	R[i] = rank;
	// }

    // nodearr* node_arr = malloc(N*sizeof(nodearr));
    // for(i=0;i<N;i++){
    //     node_arr[i].value=F[i];
    //     node_arr[i].index=i;
    // }
    // merge_sort(node_arr,N);
    // for(i=0;i<N;i++){
    //     R[node_arr[i].index]=(31-i);
    // }

    // compute averages

    // float aaa=0;
    // float bbb=0;
    // float ccc=0;
    // float ddd=0;
    for (i = 0; i < N-4; i+=4) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        one = F[i];
        two = F[i+1];
        three = F[i+2];
        four = F[i+3];
        for (j = 0; j < N; j++) {
            if (one < F[j]) {
                rank++;
            }
            if (two < F[j]) {
                rank2++;
            }
            if (three < F[j]) {
                rank3++;
            }
            if (four < F[j]) {
                rank4++;
            }
        }
        for(;j<N;j++){
            if (one < F[j]) {
                rank++;
            }
            if (one < F[j]) {
                rank2++;
            }
            if (one < F[j]) {
                rank3++;
            }
            if (one < F[j]) {
                rank4++;
            }
        }
        R[i] = rank;
        R[i+1] = rank2;
        R[i+2] = rank3;
        R[i+3] = rank4;


        temp_arr[0]+=one;
        temp_arr[1]+=two;
        temp_arr[2]+=three;
        temp_arr[3]+=four;
        // aaa+=one;
        // bbb+=two;
        // ccc+=three;
        // ddd+=four;
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
    temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);
    // temp_avg += (aaa + bbb + ccc + ddd);
    
    for(;i<N;i++){
        one = F[i];
        temp_avg += one;
        if (one >= 50.0) {
            temp_passing_avg += one;
            temp_num_passed += 1;
        }
    }


    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks



























void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4,rank5,rank6,rank7,rank8;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four,five,six,seven,eight;
    float aaa=0;
    float bbb=0;
    float ccc=0;
    float ddd=0;
    float eee=0;
    float fff=0;
    float ggg=0;
    float hhh=0;
    float temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

    for (i = 0; i < N-8; i+=8) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        rank5 = 1;
        rank6 = 1;
        rank7 = 1;
        rank8 = 1;
        one = F[i];
        two = F[i+1];
        three = F[i+2];
        four = F[i+3];
        five = F[i+4];
        six = F[i+5];
        seven = F[i+6];
        eight = F[i+7];
        for (j = 0; j < N-8; j+=8) {
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            temp5=F[j+4];
            temp6=F[j+5];
            temp7=F[j+6];
            temp8=F[j+7];
            if (one < temp) {
                rank++;
            }
            if (one < temp2) {
                rank++;
            }
            if (one < temp3) {
                rank++;
            }
            if (one < temp4) {
                rank++;
            }
            if (one < temp5) {
                rank++;
            }
            if (one < temp6) {
                rank++;
            }
            if (one < temp7) {
                rank++;
            }
            if (one < temp8) {
                rank++;
            }


            if (two < temp) {
                rank2++;
            }
            if (two < temp2) {
                rank2++;
            }
            if (two < temp3) {
                rank2++;
            }
            if (two < temp4) {
                rank2++;
            }
            if (two < temp5) {
                rank2++;
            }
            if (two < temp6) {
                rank2++;
            }
            if (two < temp7) {
                rank2++;
            }
            if (two < temp8) {
                rank2++;
            }


            if (three < temp) {
                rank3++;
            }
            if (three < temp2) {
                rank3++;
            }
            if (three < temp3) {
                rank3++;
            }
            if (three < temp4) {
                rank3++;
            }
            if (three < temp5) {
                rank3++;
            }
            if (three < temp6) {
                rank3++;
            }
            if (three < temp7) {
                rank3++;
            }
            if (three < temp8) {
                rank3++;
            }


            if (four < temp) {
                rank4++;
            }
            if (four < temp2) {
                rank4++;
            }
            if (four < temp3) {
                rank4++;
            }
            if (four < temp4) {
                rank4++;
            }
            if (four < temp5) {
                rank4++;
            }
            if (four < temp6) {
                rank4++;
            }
            if (four < temp7) {
                rank4++;
            }
            if (four < temp8) {
                rank4++;
            }


            if (five < temp) {
                rank5++;
            }
            if (five < temp2) {
                rank5++;
            }
            if (five < temp3) {
                rank5++;
            }
            if (five < temp4) {
                rank5++;
            }
            if (five < temp5) {
                rank5++;
            }
            if (five < temp6) {
                rank5++;
            }
            if (five < temp7) {
                rank5++;
            }
            if (five < temp8) {
                rank5++;
            }


            if (six < temp) {
                rank6++;
            }
            if (six < temp2) {
                rank6++;
            }
            if (six < temp3) {
                rank6++;
            }
            if (six < temp4) {
                rank6++;
            }
            if (six < temp5) {
                rank6++;
            }
            if (six < temp6) {
                rank6++;
            }
            if (six < temp7) {
                rank6++;
            }
            if (six < temp8) {
                rank6++;
            }

            if (seven < temp) {
                rank7++;
            }
            if (seven < temp2) {
                rank7++;
            }
            if (seven < temp3) {
                rank7++;
            }
            if (seven < temp4) {
                rank7++;
            }
            if (seven < temp5) {
                rank7++;
            }
            if (seven < temp6) {
                rank7++;
            }
            if (seven < temp7) {
                rank7++;
            }
            if (seven < temp8) {
                rank7++;
            }


            if (eight < temp) {
                rank8++;
            }
            if (eight < temp2) {
                rank8++;
            }
            if (eight < temp3) {
                rank8++;
            }
            if (eight < temp4) {
                rank8++;
            }
            if (eight < temp5) {
                rank8++;
            }
            if (eight < temp6) {
                rank8++;
            }
            if (eight < temp7) {
                rank8++;
            }
            if (eight < temp8) {
                rank8++;
            }
        }
        for(;j<N;j++){
            temp=F[j];
            if (one < temp) {
                rank++;
            }
            if (two < temp) {
                rank2++;
            }
            if (three < temp) {
                rank3++;
            }
            if (four < temp) {
                rank4++;
            }
            if (five < temp) {
                rank5++;
            }
            if (six < temp) {
                rank6++;
            }
            if (seven < temp) {
                rank7++;
            }
            if (eight < temp) {
                rank8++;
            }
        }
        R[i] = rank;
        R[i+1] = rank2;
        R[i+2] = rank3;
        R[i+3] = rank4;
        R[i+4] = rank5;
        R[i+5] = rank6;
        R[i+6] = rank7;
        R[i+7] = rank8;


        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;
        aaa+=one;
        bbb+=two;
        ccc+=three;
        ddd+=four;
        eee+=five;
        fff+=six;
        ggg+=seven;
        hhh+=eight;

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
        if (five >= 50.0) {
            temp_passing_avg += five;
            temp_num_passed += 1;
        }
        if (six >= 50.0) {
            temp_passing_avg += six;
            temp_num_passed += 1;
        }
        if (seven >= 50.0) {
            temp_passing_avg += seven;
            temp_num_passed += 1;
        }
        if (eight >= 50.0) {
            temp_passing_avg += eight;
            temp_num_passed += 1;
        }
    }
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);
    temp_avg += (aaa + bbb + ccc + ddd + eee + fff + ggg + hhh );
    
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












































void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four;
    float aaa=0;
    float bbb=0;
    float ccc=0;
    float ddd=0;
    float temp,temp2,temp3,temp4;

    for (i = 0; i < N-4; i+=4) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        one = F[i];
        two = F[i+1];
        three = F[i+2];
        four = F[i+3];
        for (j = 0; j < N-4; j+=4) {
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            if (one < temp) {
                rank++;
            }
            if (one < temp2) {
                rank++;
            }
            if (one < temp3) {
                rank++;
            }
            if (one < temp4) {
                rank++;
            }
            if (two < temp) {
                rank2++;
            }
            if (two < temp2) {
                rank2++;
            }
            if (two < temp3) {
                rank2++;
            }
            if (two < temp4) {
                rank2++;
            }
            if (three < temp) {
                rank3++;
            }
            if (three < temp2) {
                rank3++;
            }
            if (three < temp3) {
                rank3++;
            }
            if (three < temp4) {
                rank3++;
            }
            if (four < temp) {
                rank4++;
            }
            if (four < temp2) {
                rank4++;
            }
            if (four < temp3) {
                rank4++;
            }
            if (four < temp4) {
                rank4++;
            }
        }
        for(;j<N;j++){
            temp=F[j];
            if (one < temp) {
                rank++;
            }
            if (two < temp) {
                rank2++;
            }
            if (three < temp) {
                rank3++;
            }
            if (four < temp) {
                rank4++;
            }
        }
        R[i] = rank;
        R[i+1] = rank2;
        R[i+2] = rank3;
        R[i+3] = rank4;

        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;
        aaa+=one;
        bbb+=two;
        ccc+=three;
        ddd+=four;

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
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);
    temp_avg += (aaa + bbb + ccc + ddd);
    
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























void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four;
    float aaa=0;
    float bbb=0;
    float ccc=0;
    float ddd=0;
    float temp,temp2,temp3,temp4;

    for (i = 0; i < N-4; i+=4) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        one = F[i];
        two = F[i+1];
        three = F[i+2];
        four = F[i+3];
        for (j = 0; j < N-4; j+=4) {
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
 
        }
        R[i] = rank;
        R[i+1] = rank2;
        R[i+2] = rank3;
        R[i+3] = rank4;

        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;
        aaa+=one;
        bbb+=two;
        ccc+=three;
        ddd+=four;

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
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);
    temp_avg += (aaa + bbb + ccc + ddd);
    
    for(;i<N;i++){
        one = F[i];
        temp_avg += one;
        if (one >= 50.0) {
            temp_passing_avg += one;
            temp_num_passed += 1;
        }
        rank=1;
        for(j=0;j<N;j++){
            (one < F[j]) ? rank++ : rank;
        }
        R[i]=rank;
    }




    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks

















void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4,rank5,rank6,rank7,rank8;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four,five,six,seven,eight;
    float aaa=0;
    float bbb=0;
    float ccc=0;
    float ddd=0;
    float eee=0;
    float fff=0;
    float ggg=0;
    float hhh=0;
    float temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8;

    for (i = 0; i < N-8; i+=8) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        rank5 = 1;
        rank6 = 1;
        rank7 = 1;
        rank8 = 1;
        one = F[i];
        two = F[i+1];
        three = F[i+2];
        four = F[i+3];
        five = F[i+4];
        six = F[i+5];
        seven = F[i+6];
        eight = F[i+7];
        for (j = 0; j < N-8; j+=8) {
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            temp5=F[j+4];
            temp6=F[j+5];
            temp7=F[j+6];
            temp8=F[j+7];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (one < temp4) ? rank++ : rank;
            (one < temp5) ? rank++ : rank;
            (one < temp6) ? rank++ : rank;
            (one < temp7) ? rank++ : rank;
            (one < temp8) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (two < temp4) ? rank2++ : rank2;
            (two < temp5) ? rank2++ : rank2;
            (two < temp6) ? rank2++ : rank2;
            (two < temp7) ? rank2++ : rank2;
            (two < temp8) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;
            (three < temp4) ? rank3++ : rank3;
            (three < temp5) ? rank3++ : rank3;
            (three < temp6) ? rank3++ : rank3;
            (three < temp7) ? rank3++ : rank3;
            (three < temp8) ? rank3++ : rank3;
            (four < temp) ? rank4++ : rank4;
            (four < temp2) ? rank4++ : rank4;
            (four < temp3) ? rank4++ : rank4;
            (four < temp4) ? rank4++ : rank4;
            (four < temp5) ? rank4++ : rank4;
            (four < temp6) ? rank4++ : rank4;
            (four < temp7) ? rank4++ : rank4;
            (four < temp8) ? rank4++ : rank4;
            (five < temp) ? rank5++ : rank5;
            (five < temp2) ? rank5++ : rank5;
            (five < temp3) ? rank5++ : rank5;
            (five < temp4) ? rank5++ : rank5;
            (five < temp5) ? rank5++ : rank5;
            (five < temp6) ? rank5++ : rank5;
            (five < temp7) ? rank5++ : rank5;
            (five < temp8) ? rank5++ : rank5;
            (six < temp) ? rank6++ : rank6;
            (six < temp2) ? rank6++ : rank6;
            (six < temp3) ? rank6++ : rank6;
            (six < temp4) ? rank6++ : rank6;
            (six < temp5) ? rank6++ : rank6;
            (six < temp6) ? rank6++ : rank6;
            (six < temp7) ? rank6++ : rank6;
            (six < temp8) ? rank6++ : rank6;
            (seven < temp) ? rank7++ : rank7;
            (seven < temp2) ? rank7++ : rank7;
            (seven < temp3) ? rank7++ : rank7;
            (seven < temp4) ? rank7++ : rank7;
            (seven < temp5) ? rank7++ : rank7;
            (seven < temp6) ? rank7++ : rank7;
            (seven < temp7) ? rank7++ : rank7;
            (seven < temp8) ? rank7++ : rank7;
            (eight < temp) ? rank8++ : rank8;
            (eight < temp2) ? rank8++ : rank8;
            (eight < temp3) ? rank8++ : rank8;
            (eight < temp4) ? rank8++ : rank8;
            (eight < temp5) ? rank8++ : rank8;
            (eight < temp6) ? rank8++ : rank8;
            (eight < temp7) ? rank8++ : rank8;
            (eight < temp8) ? rank8++ : rank8;
        }
        for(;j<N-2;j+=2){
            temp=F[j];
            temp2=F[j+1];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;

            (one < temp2) ?  rank++ : rank;
            (two < temp2) ?  rank2++ : rank2;
            (three < temp2) ?  rank3++ : rank3;
            (four < temp2) ?  rank4++ : rank4;
            (five < temp2) ?  rank5++ : rank5;
            (six < temp2) ?  rank6++ : rank6;
            (seven < temp2) ?  rank7++ : rank7;
            (eight < temp2) ?  rank8++ : rank8;

        }
        for(;j<N;j++){
            temp=F[j];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;

        }
        R[i] = rank;
        R[i+1] = rank2;
        R[i+2] = rank3;
        R[i+3] = rank4;
        R[i+4] = rank5;
        R[i+5] = rank6;
        R[i+6] = rank7;
        R[i+7] = rank8;

        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;
        aaa+=one;
        bbb+=two;
        ccc+=three;
        ddd+=four;
        eee+=five;
        fff+=six;
        ggg+=seven;
        hhh+=eight;

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
        if (five >= 50.0) {
            temp_passing_avg += five;
            temp_num_passed += 1;
        }
        if (six >= 50.0) {
            temp_passing_avg += six;
            temp_num_passed += 1;
        }
        if (seven >= 50.0) {
            temp_passing_avg += seven;
            temp_num_passed += 1;
        }
        if (eight >= 50.0) {
            temp_passing_avg += eight;
            temp_num_passed += 1;
        }
    }
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);
    temp_avg += (aaa + bbb + ccc + ddd + eee + fff + ggg + hhh);

    for(;i<N-2;i+=2){
        one = F[i];
        two = F[i+1];
        temp_avg += (one+two);
        if (one >= 50.0) {
            temp_passing_avg += one;
            temp_num_passed += 1;
        }
        if (two >= 50.0) {
            temp_passing_avg += two;
            temp_num_passed += 1;
        }
        rank=1;
        rank2=1;
        for(j=0;j<N-4;j+=4){
            temp = F[j];
            temp2 = F[j+1];
            temp3 = F[j+2];
            temp4 = F[j+3];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (one < temp4) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (two < temp4) ? rank2++ : rank2;
        }
        for(;j<N;j++){
            temp=F[j];
            (one < F[j]) ? rank++ : rank;
            (two < F[j]) ? rank2++ : rank2;
        }
        R[i]=rank;
        R[i+1]=rank2;
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
            (one < F[j]) ? rank++ : rank;
        }
        R[i]=rank;
    }




    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks































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































void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4,rank5,rank6,rank7,rank8,rank9,rank10;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four,five,six,seven,eight,nine,ten;

    float temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
    int idx,idx2,idx3,idx4,idx5,idx6,idx7,idx8,idx9;
    int rep10=N-10;
    int rep3=N-3;
    for (i = 0; i < rep10; i+=10) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        rank5 = 1;
        rank6 = 1;
        rank7 = 1;
        rank8 = 1;
        rank9 = 1;
        rank10 = 1;
        idx=i+1;
        idx2=i+2;
        idx3=i+3;
        idx4=i+4;
        idx5=i+5;
        idx6=i+6;
        idx7=i+7;
        idx8=i+8;
        idx9=i+9;

        one = F[i];
        two = F[idx];
        three = F[idx2];
        four = F[idx3];
        five = F[idx4];
        six = F[idx5];
        seven = F[idx6];
        eight = F[idx7];
        nine = F[idx8];
        ten = F[idx9];
        for (j = 0; j < rep10; j+=10) {

            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            temp5=F[j+4];
            temp6=F[j+5];
            temp7=F[j+6];
            temp8=F[j+7];
            temp9=F[j+8];
            temp10=F[j+9];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (one < temp4) ? rank++ : rank;
            (one < temp5) ? rank++ : rank;
            (one < temp6) ? rank++ : rank;
            (one < temp7) ? rank++ : rank;
            (one < temp8) ? rank++ : rank;
            (one < temp9) ? rank++ : rank;
            (one < temp10) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (two < temp4) ? rank2++ : rank2;
            (two < temp5) ? rank2++ : rank2;
            (two < temp6) ? rank2++ : rank2;
            (two < temp7) ? rank2++ : rank2;
            (two < temp8) ? rank2++ : rank2;
            (two < temp9) ? rank2++ : rank2;
            (two < temp10) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;
            (three < temp4) ? rank3++ : rank3;
            (three < temp5) ? rank3++ : rank3;
            (three < temp6) ? rank3++ : rank3;
            (three < temp7) ? rank3++ : rank3;
            (three < temp8) ? rank3++ : rank3;
            (three < temp9) ? rank3++ : rank3;
            (three < temp10) ? rank3++ : rank3;
            (four < temp) ? rank4++ : rank4;
            (four < temp2) ? rank4++ : rank4;
            (four < temp3) ? rank4++ : rank4;
            (four < temp4) ? rank4++ : rank4;
            (four < temp5) ? rank4++ : rank4;
            (four < temp6) ? rank4++ : rank4;
            (four < temp7) ? rank4++ : rank4;
            (four < temp8) ? rank4++ : rank4;
            (four < temp9) ? rank4++ : rank4;
            (four < temp10) ? rank4++ : rank4;
            (five < temp) ? rank5++ : rank5;
            (five < temp2) ? rank5++ : rank5;
            (five < temp3) ? rank5++ : rank5;
            (five < temp4) ? rank5++ : rank5;
            (five < temp5) ? rank5++ : rank5;
            (five < temp6) ? rank5++ : rank5;
            (five < temp7) ? rank5++ : rank5;
            (five < temp8) ? rank5++ : rank5;
            (five < temp9) ? rank5++ : rank5;
            (five < temp10) ? rank5++ : rank5;
            (six < temp) ? rank6++ : rank6;
            (six < temp2) ? rank6++ : rank6;
            (six < temp3) ? rank6++ : rank6;
            (six < temp4) ? rank6++ : rank6;
            (six < temp5) ? rank6++ : rank6;
            (six < temp6) ? rank6++ : rank6;
            (six < temp7) ? rank6++ : rank6;
            (six < temp8) ? rank6++ : rank6;
            (six < temp9) ? rank6++ : rank6;
            (six < temp10) ? rank6++ : rank6;
            (seven < temp) ? rank7++ : rank7;
            (seven < temp2) ? rank7++ : rank7;
            (seven < temp3) ? rank7++ : rank7;
            (seven < temp4) ? rank7++ : rank7;
            (seven < temp5) ? rank7++ : rank7;
            (seven < temp6) ? rank7++ : rank7;
            (seven < temp7) ? rank7++ : rank7;
            (seven < temp8) ? rank7++ : rank7;
            (seven < temp9) ? rank7++ : rank7;
            (seven < temp10) ? rank7++ : rank7;
            (eight < temp) ? rank8++ : rank8;
            (eight < temp2) ? rank8++ : rank8;
            (eight < temp3) ? rank8++ : rank8;
            (eight < temp4) ? rank8++ : rank8;
            (eight < temp5) ? rank8++ : rank8;
            (eight < temp6) ? rank8++ : rank8;
            (eight < temp7) ? rank8++ : rank8;
            (eight < temp8) ? rank8++ : rank8;
            (eight < temp9) ? rank8++ : rank8;
            (eight < temp10) ? rank8++ : rank8;
            (nine < temp) ? rank9++ : rank9;
            (nine < temp2) ? rank9++ : rank9;
            (nine < temp3) ? rank9++ : rank9;
            (nine < temp4) ? rank9++ : rank9;
            (nine < temp5) ? rank9++ : rank9;
            (nine < temp6) ? rank9++ : rank9;
            (nine < temp7) ? rank9++ : rank9;
            (nine < temp8) ? rank9++ : rank9;
            (nine < temp9) ? rank9++ : rank9;
            (nine < temp10) ? rank9++ : rank9;
            (ten < temp) ? rank10++ : rank10;
            (ten < temp2) ? rank10++ : rank10;
            (ten < temp3) ? rank10++ : rank10;
            (ten < temp4) ? rank10++ : rank10;
            (ten < temp5) ? rank10++ : rank10;
            (ten < temp6) ? rank10++ : rank10;
            (ten < temp7) ? rank10++ : rank10;
            (ten < temp8) ? rank10++ : rank10;
            (ten < temp9) ? rank10++ : rank10;
            (ten < temp10) ? rank10++ : rank10;
        }
        for(;j<rep3;j+=3){
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;
            (nine < temp) ?  rank9++ : rank9;
            (ten < temp) ?  rank10++ : rank10;

            (one < temp2) ?  rank++ : rank;
            (two < temp2) ?  rank2++ : rank2;
            (three < temp2) ?  rank3++ : rank3;
            (four < temp2) ?  rank4++ : rank4;
            (five < temp2) ?  rank5++ : rank5;
            (six < temp2) ?  rank6++ : rank6;
            (seven < temp2) ?  rank7++ : rank7;
            (eight < temp2) ?  rank8++ : rank8;
            (nine < temp2) ?  rank9++ : rank9;
            (ten < temp2) ?  rank10++ : rank10;

            (one < temp3) ?  rank++ : rank;
            (two < temp3) ?  rank2++ : rank2;
            (three < temp3) ?  rank3++ : rank3;
            (four < temp3) ?  rank4++ : rank4;
            (five < temp3) ?  rank5++ : rank5;
            (six < temp3) ?  rank6++ : rank6;
            (seven < temp3) ?  rank7++ : rank7;
            (eight < temp3) ?  rank8++ : rank8;
            (nine < temp3) ?  rank9++ : rank9;
            (ten < temp3) ?  rank10++ : rank10;

        }
        for(;j<N;j++){
            temp=F[j];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;
            (nine < temp) ?  rank9++ : rank9;
            (ten < temp) ?  rank10++ : rank10;

        }
        R[i] = rank;
        R[idx] = rank2;
        R[idx2] = rank3;
        R[idx3] = rank4;
        R[idx4] = rank5;
        R[idx5] = rank6;
        R[idx6] = rank7;
        R[idx7] = rank8;
        R[idx8] = rank9;
        R[idx9] = rank10;

        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;

        temp_avg += (one + two + three + four + five + six + seven + eight + nine +ten);

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
        if (five >= 50.0) {
            temp_passing_avg += five;
            temp_num_passed += 1;
        }
        if (six >= 50.0) {
            temp_passing_avg += six;
            temp_num_passed += 1;
        }
        if (seven >= 50.0) {
            temp_passing_avg += seven;
            temp_num_passed += 1;
        }
        if (eight >= 50.0) {
            temp_passing_avg += eight;
            temp_num_passed += 1;
        }
        if (nine >= 50.0) {
            temp_passing_avg += nine;
            temp_num_passed += 1;
        }
        if (ten >= 50.0) {
            temp_passing_avg += ten;
            temp_num_passed += 1;
        }
    }
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);


    for(;i<rep3;i+=3){
        idx=i+1;
        idx2=i+2;
        one = F[i];
        two = F[idx];
        three = F[idx2];
        temp_avg += (one+two+three);
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
        rank=1;
        rank2=1;
        rank3=1;


        for(j=0;j<rep3;j+=3){
            temp = F[j];
            temp2 = F[j+1];
            temp3 = F[j+2];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;

        }
        for(;j<N;j++){
            temp=F[j];
            (one < F[j]) ? rank++ : rank;
            (two < F[j]) ? rank2++ : rank2;
            (three < F[j]) ? rank3++ : rank3;

        }
        R[i]=rank;
        R[idx]=rank2;
        R[idx2]=rank3;

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
            (one < F[j]) ? rank++ : rank;
        }
        R[i]=rank;
    }




    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks


























void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int rank,rank2,rank3,rank4,rank5,rank6,rank7,rank8,rank9,rank10;
    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;
    // float temp_arr[4]={0,0,0,0};
    float one,two,three,four,five,six,seven,eight,nine,ten;

    float temp,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
    int idx,idx2,idx3,idx4,idx5,idx6,idx7,idx8,idx9;
    int rep10=N-10;
    int rep3=N-3;
    for (i = 0; i < rep10; i+=10) {
        rank = 1;
        rank2 = 1;
        rank3 = 1;
        rank4 = 1;
        rank5 = 1;
        rank6 = 1;
        rank7 = 1;
        rank8 = 1;
        rank9 = 1;
        rank10 = 1;
        idx=i+1;
        idx2=i+2;
        idx3=i+3;
        idx4=i+4;
        idx5=i+5;
        idx6=i+6;
        idx7=i+7;
        idx8=i+8;
        idx9=i+9;

        one = F[i];
        two = F[idx];
        three = F[idx2];
        four = F[idx3];
        five = F[idx4];
        six = F[idx5];
        seven = F[idx6];
        eight = F[idx7];
        nine = F[idx8];
        ten = F[idx9];
        for (j = 0; j < rep10; j+=10) {

            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            temp4=F[j+3];
            temp5=F[j+4];
            temp6=F[j+5];
            temp7=F[j+6];
            temp8=F[j+7];
            temp9=F[j+8];
            temp10=F[j+9];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (one < temp4) ? rank++ : rank;
            (one < temp5) ? rank++ : rank;
            (one < temp6) ? rank++ : rank;
            (one < temp7) ? rank++ : rank;
            (one < temp8) ? rank++ : rank;
            (one < temp9) ? rank++ : rank;
            (one < temp10) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (two < temp4) ? rank2++ : rank2;
            (two < temp5) ? rank2++ : rank2;
            (two < temp6) ? rank2++ : rank2;
            (two < temp7) ? rank2++ : rank2;
            (two < temp8) ? rank2++ : rank2;
            (two < temp9) ? rank2++ : rank2;
            (two < temp10) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;
            (three < temp4) ? rank3++ : rank3;
            (three < temp5) ? rank3++ : rank3;
            (three < temp6) ? rank3++ : rank3;
            (three < temp7) ? rank3++ : rank3;
            (three < temp8) ? rank3++ : rank3;
            (three < temp9) ? rank3++ : rank3;
            (three < temp10) ? rank3++ : rank3;
            (four < temp) ? rank4++ : rank4;
            (four < temp2) ? rank4++ : rank4;
            (four < temp3) ? rank4++ : rank4;
            (four < temp4) ? rank4++ : rank4;
            (four < temp5) ? rank4++ : rank4;
            (four < temp6) ? rank4++ : rank4;
            (four < temp7) ? rank4++ : rank4;
            (four < temp8) ? rank4++ : rank4;
            (four < temp9) ? rank4++ : rank4;
            (four < temp10) ? rank4++ : rank4;
            (five < temp) ? rank5++ : rank5;
            (five < temp2) ? rank5++ : rank5;
            (five < temp3) ? rank5++ : rank5;
            (five < temp4) ? rank5++ : rank5;
            (five < temp5) ? rank5++ : rank5;
            (five < temp6) ? rank5++ : rank5;
            (five < temp7) ? rank5++ : rank5;
            (five < temp8) ? rank5++ : rank5;
            (five < temp9) ? rank5++ : rank5;
            (five < temp10) ? rank5++ : rank5;
            (six < temp) ? rank6++ : rank6;
            (six < temp2) ? rank6++ : rank6;
            (six < temp3) ? rank6++ : rank6;
            (six < temp4) ? rank6++ : rank6;
            (six < temp5) ? rank6++ : rank6;
            (six < temp6) ? rank6++ : rank6;
            (six < temp7) ? rank6++ : rank6;
            (six < temp8) ? rank6++ : rank6;
            (six < temp9) ? rank6++ : rank6;
            (six < temp10) ? rank6++ : rank6;
            (seven < temp) ? rank7++ : rank7;
            (seven < temp2) ? rank7++ : rank7;
            (seven < temp3) ? rank7++ : rank7;
            (seven < temp4) ? rank7++ : rank7;
            (seven < temp5) ? rank7++ : rank7;
            (seven < temp6) ? rank7++ : rank7;
            (seven < temp7) ? rank7++ : rank7;
            (seven < temp8) ? rank7++ : rank7;
            (seven < temp9) ? rank7++ : rank7;
            (seven < temp10) ? rank7++ : rank7;
            (eight < temp) ? rank8++ : rank8;
            (eight < temp2) ? rank8++ : rank8;
            (eight < temp3) ? rank8++ : rank8;
            (eight < temp4) ? rank8++ : rank8;
            (eight < temp5) ? rank8++ : rank8;
            (eight < temp6) ? rank8++ : rank8;
            (eight < temp7) ? rank8++ : rank8;
            (eight < temp8) ? rank8++ : rank8;
            (eight < temp9) ? rank8++ : rank8;
            (eight < temp10) ? rank8++ : rank8;
            (nine < temp) ? rank9++ : rank9;
            (nine < temp2) ? rank9++ : rank9;
            (nine < temp3) ? rank9++ : rank9;
            (nine < temp4) ? rank9++ : rank9;
            (nine < temp5) ? rank9++ : rank9;
            (nine < temp6) ? rank9++ : rank9;
            (nine < temp7) ? rank9++ : rank9;
            (nine < temp8) ? rank9++ : rank9;
            (nine < temp9) ? rank9++ : rank9;
            (nine < temp10) ? rank9++ : rank9;
            (ten < temp) ? rank10++ : rank10;
            (ten < temp2) ? rank10++ : rank10;
            (ten < temp3) ? rank10++ : rank10;
            (ten < temp4) ? rank10++ : rank10;
            (ten < temp5) ? rank10++ : rank10;
            (ten < temp6) ? rank10++ : rank10;
            (ten < temp7) ? rank10++ : rank10;
            (ten < temp8) ? rank10++ : rank10;
            (ten < temp9) ? rank10++ : rank10;
            (ten < temp10) ? rank10++ : rank10;
        }
        for(;j<rep3;j+=3){
            temp=F[j];
            temp2=F[j+1];
            temp3=F[j+2];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;
            (nine < temp) ?  rank9++ : rank9;
            (ten < temp) ?  rank10++ : rank10;

            (one < temp2) ?  rank++ : rank;
            (two < temp2) ?  rank2++ : rank2;
            (three < temp2) ?  rank3++ : rank3;
            (four < temp2) ?  rank4++ : rank4;
            (five < temp2) ?  rank5++ : rank5;
            (six < temp2) ?  rank6++ : rank6;
            (seven < temp2) ?  rank7++ : rank7;
            (eight < temp2) ?  rank8++ : rank8;
            (nine < temp2) ?  rank9++ : rank9;
            (ten < temp2) ?  rank10++ : rank10;

            (one < temp3) ?  rank++ : rank;
            (two < temp3) ?  rank2++ : rank2;
            (three < temp3) ?  rank3++ : rank3;
            (four < temp3) ?  rank4++ : rank4;
            (five < temp3) ?  rank5++ : rank5;
            (six < temp3) ?  rank6++ : rank6;
            (seven < temp3) ?  rank7++ : rank7;
            (eight < temp3) ?  rank8++ : rank8;
            (nine < temp3) ?  rank9++ : rank9;
            (ten < temp3) ?  rank10++ : rank10;

        }
        for(;j<N;j++){
            temp=F[j];
            (one < temp) ?  rank++ : rank;
            (two < temp) ?  rank2++ : rank2;
            (three < temp) ?  rank3++ : rank3;
            (four < temp) ?  rank4++ : rank4;
            (five < temp) ?  rank5++ : rank5;
            (six < temp) ?  rank6++ : rank6;
            (seven < temp) ?  rank7++ : rank7;
            (eight < temp) ?  rank8++ : rank8;
            (nine < temp) ?  rank9++ : rank9;
            (ten < temp) ?  rank10++ : rank10;

        }
        R[i] = rank;
        R[idx] = rank2;
        R[idx2] = rank3;
        R[idx3] = rank4;
        R[idx4] = rank5;
        R[idx5] = rank6;
        R[idx6] = rank7;
        R[idx7] = rank8;
        R[idx8] = rank9;
        R[idx9] = rank10;

        // temp_arr[0]+=one;
        // temp_arr[1]+=two;
        // temp_arr[2]+=three;
        // temp_arr[3]+=four;

        temp_avg += (one + two + three + four + five + six + seven + eight + nine +ten);

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
        if (five >= 50.0) {
            temp_passing_avg += five;
            temp_num_passed += 1;
        }
        if (six >= 50.0) {
            temp_passing_avg += six;
            temp_num_passed += 1;
        }
        if (seven >= 50.0) {
            temp_passing_avg += seven;
            temp_num_passed += 1;
        }
        if (eight >= 50.0) {
            temp_passing_avg += eight;
            temp_num_passed += 1;
        }
        if (nine >= 50.0) {
            temp_passing_avg += nine;
            temp_num_passed += 1;
        }
        if (ten >= 50.0) {
            temp_passing_avg += ten;
            temp_num_passed += 1;
        }
    }
    // temp_avg += (temp_arr[0] + temp_arr[1] + temp_arr[2] + temp_arr[3]);


    for(;i<rep3;i+=3){
        idx=i+1;
        idx2=i+2;
        one = F[i];
        two = F[idx];
        three = F[idx2];
        temp_avg += (one+two+three);
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
        rank=1;
        rank2=1;
        rank3=1;


        for(j=0;j<rep3;j+=3){
            temp = F[j];
            temp2 = F[j+1];
            temp3 = F[j+2];
            (one < temp) ? rank++ : rank;
            (one < temp2) ? rank++ : rank;
            (one < temp3) ? rank++ : rank;
            (two < temp) ? rank2++ : rank2;
            (two < temp2) ? rank2++ : rank2;
            (two < temp3) ? rank2++ : rank2;
            (three < temp) ? rank3++ : rank3;
            (three < temp2) ? rank3++ : rank3;
            (three < temp3) ? rank3++ : rank3;

        }
        for(;j<N;j++){
            temp=F[j];
            (one < F[j]) ? rank++ : rank;
            (two < F[j]) ? rank2++ : rank2;
            (three < F[j]) ? rank3++ : rank3;

        }
        R[i]=rank;
        R[idx]=rank2;
        R[idx2]=rank3;

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
            (one < F[j]) ? rank++ : rank;
        }
        R[i]=rank;
    }




    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks

























Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
1 of 684
Re: cmpt 295 mid2 - Invitation to collaborate
Duo Lu
    
Attachments19:13 (25 minutes ago)
    
to me
   
Translate message
Turn off for: English


On Wed, 20 Mar 2019 at 14:16, Chen Zhao (via Google Drive) <czhao1028@gmail.com> wrote:

    Chen Zhao has invited you to contribute to the following shared folder:
    cmpt 295 mid2
    Open
            
            
            
        
        
            
            
            
    Google Drive: Have all your files within reach from any device.
    Google LLC, 1600 Amphitheatre Parkway, Mountain View, CA 94043, USA Logo for Google Drive

2 Attachments
    
    
    

void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {
    int i, j;
    //num_passed = 0;
    //avg = 0.0;
    //passing_avg = 0.0;

    int copy_number_passed = 0;
    float copy_avg = 0.0;
    float copy_passing_avg = 0.0;
    
    // init ranks
    // for (i = 0; i < N - 4; i += 4)
    // {
    //     R[i] = 1;
    //     R[i+1] = 1;
    //     R[i+2] = 1;
    //     R[i+3] = 1;
    // }
    //  for (; i < N; i++)
    //     R[i] = 1;
    

    for (i = 0; i < N; i++)
       R[i] = 1;

    // compute ranks
    // for (i = 0; i < N; ++i) {
    //     R[i] = 1;
    //     for (j = 0; j < N - 4; j += 4) {
    //         if (F[i] < F[j]) {
    //             R[i]++;
    //         }
    //         if (F[i] < F[j+1]){
    //             R[i]++;
    //         }
    //         if (F[i] < F[j+2]) {
    //             R[i]++;
    //         }
    //         if (F[i] < F[j+3]){
    //             R[i]++;
    //         }
    //     }
    //     for (; j < N; j++)
    //     {
    //         if (F[i] < F[j])
    //         {
    //             R[i]++;
    //         }
    //     }
    // }
    

    // for (i = 0; i < N; i++) {
    //     R[i] = 1;
    //     for (j = 0; j < N - 8; j += 8) {
    //          R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+1] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+2] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+3] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+4] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+5] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+6] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+7] ? R[i] + 1 : R[i];
    //     }
    //     for (; j < N; j++)
    //     {
    //         R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];
    //     }
    // }



    //compute ranks
    // for (i = 0; i < N; i++) {
        
    //     for (j = i + 1; j < N - 4; j += 4) {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //         if (F[i] < F[j+1]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+1]){
    //             R[j+1] += 1;
    //         }
    //         if (F[i] < F[j+2]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+2]){
    //             R[j+2] += 1;
    //         }
    //         if (F[i] < F[j+3]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+3]){
    //             R[j+3] += 1;
    //         }
    //     }
    //     for (; j < N; j++)
    //     {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //     }
    // }


    // for (i = 0; i < N; i++) {
        
    //     for (j = i + 1 ; j < N - 4; j += 4) {

    //          R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+1] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+2] ? R[i] + 1 : R[i];
    //          R[i] =  F[i] < F[j+3] ? R[i] + 1 : R[i];

    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //         if (F[i] > F[j+1]){
    //             R[j+1] += 1;
    //         }
        
    //         if (F[i] > F[j+2]){
    //             R[j+2] += 1;
    //         }

    //         if (F[i] > F[j+3]){
    //             R[j+3] += 1;
    //         }
    //     }
    //     for (; j < N; j++)
    //     {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //     }
    // }
      for (i = 0; i < N-2; i+=2) {
        
        for (j = i + 1 ; j < N - 4; j += 4) {

             R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] =  F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] =  F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] =  F[i] < F[j+3] ? R[i] + 1 : R[i];

            if (F[i] > F[j]){
                R[j] += 1;
            }
            if (F[i] > F[j+1]){
                R[j+1] += 1;
            }
        
            if (F[i] > F[j+2]){
                R[j+2] += 1;
            }

            if (F[i] > F[j+3]){
                R[j+3] += 1;
            }

            i++;
            R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];
            R[i] =  F[i] < F[j+1] ? R[i] + 1 : R[i];
            R[i] =  F[i] < F[j+2] ? R[i] + 1 : R[i];
            R[i] =  F[i] < F[j+3] ? R[i] + 1 : R[i];

            if (F[i] > F[j]){
                R[j] += 1;
            }
            if (F[i] > F[j+1]){
                R[j+1] += 1;
            }
        
            if (F[i] > F[j+2]){
                R[j+2] += 1;
            }

            if (F[i] > F[j+3]){
                R[j+3] += 1;
            }
            i--;
        }
        for (; j < N; j++)
        {
            if (F[i] < F[j]) {
                R[i] += 1;
            }
            if (F[i] > F[j]){
                R[j] += 1;
            }
            i++;
            if (F[i] < F[j]) {
                R[i] += 1;
            }
            if (F[i] > F[j]){
                R[j] += 1;
            }
            i--;
        }
    }
    for(;i<N;i++){
        for (j = i ; j < N ; j += 1 ) {

             R[i] =  F[i] < F[j] ? R[i] + 1 : R[i];


            if (F[i] > F[j]){
                R[j] += 1;
            }

        }

    }



    // int k = 0;
    // float sum[4] = {0.0 , 0.0 , 0.0 , 0.0};
    //   for (i = 0; i < N; i += 1) {
        
    //     for (j = i + 1; j < N - 4; j += 4) {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //         if (F[i] < F[j+1]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+1]){
    //             R[j+1] += 1;
    //         }
    //         if (F[i] < F[j+2]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+2]){
    //             R[j+2] += 1;
    //         }
    //         if (F[i] < F[j+3]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j+3]){
    //             R[j+3] += 1;
    //         }
    //     }
    //     for (; j < N; j++)
    //     {
    //         if (F[i] < F[j]) {
    //             R[i] += 1;
    //         }
    //         if (F[i] > F[j]){
    //             R[j] += 1;
    //         }
    //     }

    //     if (k < N)
    //     {
    //         sum[0] += F[k];
    //         sum[1] += F[k+1];
    //         sum[2] += F[k+2];
    //         sum[3] += F[k+3];
    //         if (F[k] >= 50.0) {
    //             copy_passing_avg += F[k];
    //             copy_number_passed += 1;
    //         }
    //         if (F[k+1] >= 50.0){
    //             copy_passing_avg += F[k+1];
    //             copy_number_passed += 1;
    //         }
    //         if (F[k+2] >= 50.0) {
    //             copy_passing_avg += F[k+2];
    //             copy_number_passed += 1;
    //         }
    //         if (F[k+3] >= 50.0){
    //             copy_passing_avg += F[k+3];
    //             copy_number_passed += 1;
    //         }
    //     }
    //     k += 4;
        
    // }
    // copy_avg = sum[0] + sum[1] + sum[2] + sum[3];
    // for (; k < N; k++){
    //     copy_avg += F[k];
    //     if (F[k] >= 50.0) {
    //         copy_passing_avg += F[k];
    //         copy_number_passed += 1;
    //     }

    // }


    // compute averages
    float sum[4] = {0.0 , 0.0 , 0.0 , 0.0};
    for (i = 0; i < N - 4 ; i = i + 4) {
        //copy_avg += F[i];
        sum[0] += F[i];
        sum[1] += F[i+1];
        sum[2] += F[i+2];
        sum[3] += F[i+3];
        if (F[i] >= 50.0) {
            copy_passing_avg += F[i];
            copy_number_passed += 1;
        }
        if (F[i+1] >= 50.0){
            copy_passing_avg += F[i+1];
            copy_number_passed += 1;
        }
        if (F[i+2] >= 50.0) {
            copy_passing_avg += F[i+2];
            copy_number_passed += 1;
        }
        if (F[i+3] >= 50.0){
            copy_passing_avg += F[i+3];
            copy_number_passed += 1;
        }
    }
    copy_avg = sum[0] + sum[1] + sum[2] + sum[3];
    for (; i < N; i++){
        copy_avg += F[i];
        if (F[i] >= 50.0) {
            copy_passing_avg += F[i];
            copy_number_passed += 1;
        }
    } 
    
    // compute averages
    // for (i = 0; i < N; i++) {
    //     copy_avg += F[i];
    //     if (F[i] >= 50.0) {
    //         copy_passing_avg += F[i];
    //         copy_number_passed += 1;
    //     }
    // }



    // check for div by 0
    if (N > 0)
        copy_avg /= N;
    if (copy_number_passed) 
        copy_passing_avg /= copy_number_passed;

    *avg = copy_avg;
    *num_passed = copy_number_passed;
    *passing_avg = copy_passing_avg;

} // compute_ranks

rank.c
Displaying rank.c.


























void compute_ranks(float *F, int N, int *R, float *avg, float *passing_avg, int *num_passed) {

    int i, j;
    int temp_num_passed = 0;
    float temp_avg = 0.0;
    float temp_passing_avg = 0.0;

    for(i=0;i<N;i++){R[i]=1;}



      for (i = 0; i < N-4; i+=4) {
        
        for (j = i + 1 ; j < N - 4; j += 4) {
            if(j==i+1){
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];

            i++;
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];

             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];


             i++;

            R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];

             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];

             i++;
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+3] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];
             R[j+3] = F[i] > F[j+3] ? R[j+3] + 1 : R[j+3];

             i-=3;

            }
            else{
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+3] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];
             R[j+3] = F[i] > F[j+3] ? R[j+3] + 1 : R[j+3];


            i++;
            R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+3] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];
             R[j+3] = F[i] > F[j+3] ? R[j+3] + 1 : R[j+3];


            i++;
            R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+3] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];
             R[j+3] = F[i] > F[j+3] ? R[j+3] + 1 : R[j+3];


            i++;
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+1] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+2] ? R[i] + 1 : R[i];
             R[i] = F[i] < F[j+3] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
             R[j+1] = F[i] > F[j+1] ? R[j+1] + 1 : R[j+1];
             R[j+2] = F[i] > F[j+2] ? R[j+2] + 1 : R[j+2];
             R[j+3] = F[i] > F[j+3] ? R[j+3] + 1 : R[j+3];
            i-=3;
            }
        }
        for (; j < N; j++)
        {
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
            i++;
            R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
            i++;
                       R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
            i++;
             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];
            i-=3;
        }
        if (F[i] >= 50.0) {
            temp_passing_avg += F[i];
            temp_num_passed += 1;
        }
        temp_avg += F[i];
        if (F[i+1] >= 50.0) {
            temp_passing_avg += F[i+1];
            temp_num_passed += 1;
        }
        temp_avg += F[i+1];
                if (F[i+2] >= 50.0) {
            temp_passing_avg += F[i+2];
            temp_num_passed += 1;
        }
        temp_avg += F[i+2];
                if (F[i+3] >= 50.0) {
            temp_passing_avg += F[i+3];
            temp_num_passed += 1;
        }
        temp_avg += F[i+3];
    }
    for(;i<N;i++){
        for (j = i ; j < N ; j += 1 ) {

             R[i] = F[i] < F[j] ? R[i] + 1 : R[i];
             R[j] = F[i] > F[j] ? R[j] + 1 : R[j];

        }
        if (F[i] >= 50.0) {
            temp_passing_avg += F[i];
            temp_num_passed += 1;
        }
        temp_avg += F[i];

    }

    // for(;i<N;i++){
    //     temp=F[i];
    //     for(j=i+1;j<N;j++){
    //         tempj=F[j];


    //         R[i]=temp<tempj ? R[i]+1 : R[i];
    //         R[j]=temp>tempj ? R[j]+1 : R[j];
    //     }
        // if (F[i] >= 50.0) {
        //     temp_passing_avg += F[i];
        //     temp_num_passed += 1;
        // }
        // temp_avg += F[i];
    // }


    if (N > 0) temp_avg /= N;
    if (temp_num_passed) temp_passing_avg /= temp_num_passed;

    *num_passed = temp_num_passed;
    *avg = temp_avg;
    *passing_avg = temp_passing_avg;    

} // compute_ranks


