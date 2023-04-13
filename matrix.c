#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **arr, int row,int col);
void addition_matrix(int **arrA,int **arrB, int rowA,int colA, int rowB,int colB);
void subtraction_matrix(int **arrA,int **arrB, int rowA,int colA, int rowB,int colB);
void transpose_matrix(int **arrA, int row,int col);
void multiply_matrix(int **arrA,int **arrB, int rowA,int colA, int rowB,int colB);
void free_matrix(int **arr);

int main(){
    printf("[----- [kang su] [2017015040] -----]\n\n");

    //A행열 변수값
    int rowA=0;
    int colA=0;

    //A 행열 입력
    printf("Matrix_A row : ");
    scanf("%d", &rowA);

    printf("Matrix_A col : ");
    scanf("%d", &colA);

    //입력 결과 확인
    printf("Matrix_A row: %d,col: %d\n", rowA, colA);

    //B행열 변수값
    int rowB=0;
    int colB=0;

    //B 행열 입력
    printf("Matrix_B row : ");
    scanf("%d", &rowB);

    printf("Matrix_B col : ");
    scanf("%d", &colB);

    //입력 결과 확인
    printf("Matrix_B row: %d,col: %d\n", rowB, colB);


    //배열 A 할당 시작

    int **arrA;//사용할 2차원 포인터
    //배열 2차원 포인터로 만들고 
    //포인터 배열에 행을 포인터 형태로 배열을 할당하고 
    //그 배열 안에 열을 배열한다.

    // malloc() 호출로 정수에 대한 포인터(행 주소)를 저장할 배열을 할당
    // 행의 주소만 저장한다
    arrA=(int **) malloc (sizeof(int *) *rowA);//행을 int형 포인터 형식으로 저장할 공간 할당

    //첫번째 행 주소 할당
    //실제 2차원 배열 값을 malloc()으로 저장공간 할당
    arrA[0] =(int*) malloc (sizeof(int)*rowA*colA);//int 형식으로 실제 데이터를 저장할 공간 할당


    //나머지 행주소들을 이전행 주소로부터 다음 행주소를 구해서(이전행+열 크기*열 수)할당
    for (int i=1; i<rowA; i++){
        arrA[i]=arrA[i-1]+colA;//이전 행[i]의 주소+열 갯수=다음 행[i+1]의 주소
    }


    //배열 랜덤초기화
    for (int i = 0; i < rowA; i++)    // 2차원 배열의 행 크기만큼 반복
    {
        for (int j = 0; j < colA; j++)    // 2차원 배열의 열 크기만큼 반복
        {
            arrA[i][j]=rand()%9; // 한자리 난수 생성
        }
    }

    //배열 A 할당 끝


    //배열 B 할당
    int **arrB;//사용할 배열
    arrB=(int **) malloc (sizeof(int *) *rowB);
    arrB[0] =(int*) malloc (sizeof(int)*rowB*colB);
    for (int i=1; i<rowB; i++){
        arrB[i]=arrB[i-1]+colB;
    }
    //배열 랜덤초기화
    for (int i = 0; i < rowB; i++) 
    {
        for (int j = 0; j < colB; j++)   
        {
            arrB[i][j]=rand()%9;
        }
    }
    
    //배열 B 할당 끝

    //A
    printf("\nMatrix_A\n");
    printf(" \nprint_matrix(arrA,rowA,colA)  \n");
    print_matrix(arrA,rowA,colA);
    printf("\n\n");

    //B
    printf("\nMatrix_B\n");
    printf(" \nprint_matrix(arrB,rowB,colB)  \n");
    print_matrix(arrB,rowB,colB);
    printf("\n\n");

    //A+B
    printf("\nMatrix_A+Matrix_B\n");
    printf(" \naddition_matrix(arrA,arrB,rowA,colA)");
    addition_matrix(arrA,arrB,rowA,colA,rowB,colB);
    printf("\n\n");

    //A-B
    printf("\nMatrix_A-Matrix_B\n");
    printf(" \nsubtraction_matrix(arrA,arrB,rowA,colA)");
    subtraction_matrix(arrA,arrB,rowA,colA,rowB,colB);
     printf("\n\n");

    //A전치
    printf("\nMatrix_A_Transpose\n");
    printf(" \ntranspose_matrix(arrA,rowA,colA)");
    transpose_matrix(arrA,rowA,colA);
     printf("\n\n");

    //A*B
    printf("Matrix_A X MatrixB\n");
    printf(" \nsubtraction_matrix(arrA,arrB,rowA,colA,rowB,colB)");
    multiply_matrix(arrA,arrB,rowA,colA,rowB,colB);

    printf("\n");

    //매모리 해제
    free_matrix(arrA);
    free_matrix(arrB);


    return 0;
}



//결과 출력 함수
void print_matrix(int **arr, int row,int col){
   // printf("print_matrix: start \n");
   printf("\n");
    for (int i = 0; i < row; i++)  
    {
        for (int j = 0; j < col; j++)   
        {
            printf("\t %d", arr[i][j]); //2차원 배열출력
        }
        printf("\n");                //행 줄넘김
    }
   // printf("print_matrix: end \n");
}

//A+B 함수
void addition_matrix(int **arrA,int **arrB, int rowA,int colA, int rowB,int colB){
    //printf("addition_matrix: start \n");
    if(rowA==rowB&&colA==colB){

        //합차에 사용할 배열 할당
        int **arrO;//합차에 사용할 배열
        arrO=(int **) malloc (sizeof(int *) *rowA);
        arrO[0] =(int*) malloc (sizeof(int)*rowA*colA);
        for (int i=1; i<rowA; i++){
        arrO[i]=arrO[i-1]+colA;
        }
        

        printf("\n");

        //A+B계산 및 저장
        for (int i = 0; i < rowA; i++)
        {
            for (int j = 0; j < colA; j++)   
            {
                printf("\n arrO[%d][%d]",i,j);
                arrO[i][j]=arrA[i][j]+arrB[i][j];
                printf("\t %d + %d =\t%d \n", arrA[i][j], arrB[i][j],arrO[i][j]);
            }

        }


        //결과출력
        printf(" \nprint_matrix(arrO,rowA,colA)  \n");
        print_matrix(arrO,rowA,colA);

        
        //매모리 해제
        free_matrix(arrO);

    }else{//오류처리
        printf(" \naddition_matrix_ERR: rowA!=rowB or colA!=colB  \n");
    }
   // printf("\naddition_matrix: end \n");
}

//A-B 함수
void subtraction_matrix(int **arrA,int **arrB, int rowA,int colA, int rowB,int colB){
    //printf("subtraction_matrix: start \n");
    if(rowA==rowB&&colA==colB){

        //합차에 사용할 배열 할당
        int **arrO;//합차에 사용할 배열
        arrO=(int **) malloc (sizeof(int *) *rowA);
        arrO[0] =(int*) malloc (sizeof(int)*rowA*colA);
        for (int i=1; i<rowA; i++){
            arrO[i]=arrO[i-1]+colA;
        }

        printf("\n");

        //A-B 계산 및 저장
        for (int i = 0; i < rowA; i++)   
        {
            for (int j = 0; j < colA; j++)    
            {
                printf("\n arrO[%d][%d]",i,j);
                arrO[i][j]=arrA[i][j]-arrB[i][j];
                printf("\t %d - %d =\t%d \n", arrA[i][j], arrB[i][j],arrO[i][j]);
            }

        }
        
        //결과출력
        printf(" \nprint_matrix(arrO,rowA,colA)  \n");
        print_matrix(arrO,rowA,colA);

        
        //매모리 해제
        free_matrix(arrO);

    }else{//오류처리
        printf(" \nsubtraction_matrix_ERR: rowA!=rowB or colA!=colB  \n");
    }
   // printf("\n subtraction_matrix: end \n");
}

//A의 전치행렬 구하는 함수
void transpose_matrix(int **arrA, int row,int col){
    //printf("transpose_matrix: start \n");

    //전치에 사용할 배열 할당
    int **arrT;//전치에 사용할 배열, 전치는 행과열이 반대
    arrT=(int **) malloc (sizeof(int *) *col);
    arrT[0] =(int*) malloc (sizeof(int)*col*row);
    for (int i=1; i<col; i++){
        arrT[i]=arrT[i-1]+row;
    }

    //전치 계산 및 저장
    for (int i = 0; i < row; i++)  
    {
        for (int j = 0; j < col; j++)  
        {
         
            arrT[j][i]=arrA[i][j];
         
        }

    }

    //결과출력
    printf(" \nprint_matrix(arrT,row,col)  \n");
    print_matrix(arrT,row,col);
    
    //매모리 해제
    free_matrix(arrT);
   // printf("\n transpose_matrix: end \n");
}

//A*B 행렬곱 함수
void multiply_matrix(int **arrA,int **arrB, int rowA,int colA,int rowB,int colB){
    //printf("multiply_matrix: start \n");
    if(colA==rowB){

        //행열곱에 사용할 배열 할당
        int **arrM;//행열곱에 사용할 배열 

        //A행열 곱 B행열 결과 M 행열
        //M행열의 행수 = A의 행수, M행열의 열수 = B행열의 열수 
        arrM=(int **) malloc (sizeof(int *) *rowA);
        arrM[0] =(int*) malloc (sizeof(int)*rowA*colB);
        for (int i=1; i<rowA; i++){
            arrM[i]=arrM[i-1]+colB;
        }
        printf("\n");

        //행열 곱계산 및 저장
        for (int i = 0; i < rowA; i++)  
        {
            for (int j = 0; j < colB; j++)  
            {
                printf("\n arrM[%d][%d]",i,j);
                arrM[i][j]=0;
                //행열곱[i][j]=각각의 A의 i행과 B의 J열의 곱의 합
                
                for (int k = 0; k < colA; k++){
                    arrM[i][j]+=arrA[i][k]*arrB[k][j];
                    printf("\t [%d * %d =%d : %d] ", arrA[i][k], arrB[k][j],(arrA[i][k]*arrB[k][j]),arrM[i][j]);
                }  
                  printf("\t <%d> \n",arrM[i][j]);
            }
        }

        //결과출력
        printf(" \nprint_matrix(arrT,rowA,colB)  \n");
        print_matrix(arrM,rowA,colB);

        
        //매모리 해제
        free_matrix(arrM);
        }

    else{//오류처리
        printf(" \nmultiply_matrix_ERR: colA!=rowB  \n");
    }
    // printf("\n multiply_matrix: end \n");
}

//메모리 해제 함수
void free_matrix(int **arr){
    //printf("free_matrix: start \n");
    free(arr[0]);
    free(arr);
    //printf("\n free_matrix: end \n");
}