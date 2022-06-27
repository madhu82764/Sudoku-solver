
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t lock;



#define N 36
int grida[N][N];
int flag = 0 ; 

typedef struct {
            int row;
            int col;    
            int size; 
            int num ;
            int final; 
            int runner ; 
            int grid[N][N];    
}mystruct;

void read_grid_from_file(int size, char *ip_file, int grid[N][N]) {
	FILE *fp;
	int i, j;
	fp = fopen(ip_file, "r");
	for (i=0; i<size; i++) 
		for (j=0; j<size; j++) {
			fscanf(fp, "%d", &grid[i][j]);
	}
} 

void print_grid(int size, int grid[N][N]) {
	int i, j;
	/* The segment below prints the grid in a standard format. Do not change */
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++)
			printf("%d\t", grid[i][j]);
		printf("\n");
	}
}

int check(int grid[N][N],int size){
    int check = 0;
    for(int i = 0 ; i < size ; i++)
    for(int j = 0 ; j < size; j++)
    if(grid[i][j] == 0)
    check++; 
    return check ; 

}

/*
int validr[36][36] = {0};
int validc[36][36] = {0};
int validb[36][36] = {0};


void *isColumnValid(void* val) {

    mystruct *sc= (mystruct*) val;
    int row = sc->row; 
    int col = sc->col; 
    int size = sc->size;
    int num = sc->num;
    int final = sc->final; 
    int runner = sc->runner; 
    int grid[N][N];
    for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        grid[k][j] =  sc->grid[k][j] ;
    pthread_mutex_unlock(&lock);

        validc[row][col] == 0;
        
        for (int x = 0; x < size; x++)
        if (grid[x][col] == num)
            pthread_exit(NULL);
            
        validc[row][col]= 1; 
        pthread_exit(NULL);
    pthread_mutex_destroy(&lock);

    
}
void *isRowValid(void* val) {
    
    mystruct *sr= (mystruct*) val;
    int row = sr->row; 
    int col = sr->col; 
    int size = sr->size;
    int num = sr->num;
    int final = sr->final; 
    int runner = sr->runner; 
    int grid[N][N];
     for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        grid[k][j] =  sr->grid[k][j] ;
    
    pthread_mutex_unlock(&lock);
        validr[row][col] == 0;
        for (int x = 0; x < size; x++)
        if (grid[row][x] == num)
            pthread_exit(NULL);

        validr[row][col]= 1; 
        pthread_exit(NULL);

        pthread_mutex_destroy(&lock);
}
void *isValidB(void* val) {
    
    mystruct *sb= (mystruct*) val;
    int row = sb->row; 
    int col = sb->col; 
    int size =sb->size;
    int num = sb->num;
    int final = sb->final; 
    int runner = sb->runner; 
    int grid[N][N];
    for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        grid[k][j] =  sb->grid[k][j] ;
    pthread_mutex_unlock(&lock);
        validb[row][col] == 0;
        int n = sqrt(size);
        int startRow = row - row % n, startCol = col - col % n ;  
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i + startRow][j + startCol] == num){
                pthread_exit(NULL);
                }
        
        pthread_mutex_destroy(&lock);
       validb[row][col] = 1; 
        pthread_exit(NULL);
        
}


int isValid2(int grid[N][N],int row ,int  col ,int  num, int size){
                                 
                                pthread_t threads[3];

                               validr[row][col] = 0 ;validc[row][col] = 0; validb[row][col] = 0 ;
                                mystruct data2 ;   
                                data2.row = row; 
                                data2.col = col; 
                                data2.size = size;
                                data2.num = num ;
                                data2.grid;
                                for( int k = 0 ; k < size; k++)
                                for(int j = 0 ; j < size; j++)
                                data2.grid[k][j] = grid[k][j] ;

                                pthread_create(&threads[1], NULL, isValidB, &data2);
                                sleep(0.5);
                                pthread_create(&threads[2], NULL, isColumnValid, &data2); 
                                sleep(0.5);
                                pthread_create(&threads[3], NULL, isRowValid, &data2);
                                sleep(0.5);
                                
                                pthread_join(threads[1],NULL);
                                pthread_join(threads[2],NULL);
                                pthread_join(threads[3],NULL);

                               
                                 /*   
                                if(isValidBThread( grid,  row, col,  num, size)) 
                                //{printf("validedbox[row][col] updated %d\n", validb[row][col]);
                                //sleep(0.5);}
                                if(isColumnThread(grid,  row, col,  num, size))  // column threads
                                //{printf("validedcol[row][col] updated %d\n", validc[row][col]);
                                //sleep(0.5);}
                                if(isRowThread(grid,  row, col,  num, size))
                                //{printf("validedrow[row][col] updated %d\n", validr[row][col]);
                                 //sleep(0.5);} 

                                
                                pthread_join(threads[0],NULL);
                                pthread_join(threads[1],NULL);
                                pthread_join(threads[2],NULL);
*/
/*
                               
        if((validr[row][col] == 1) && (validc[row][col] == 1) && (validb[row][col]== 1)){
validr[row][col] = 0 ;validc[row][col] = 0; validb[row][col] = 0 ;
                                    return 1;
                                }
                                  validr[row][col] = 0 ;validc[row][col] = 0; validb[row][col] = 0 ; 
                               

                                return 0; 

}
*/



/*
int valid[N] = {0} ; 

void *isValide(void* val) {
        
    
    mystruct *sk= (mystruct*) val;
    int row = sk->row; 
    int col = sk->col; 
    int size =sk->size;
    int num = sk->num;
    int final = sk->final; 
    int runner = sk->runner; 
    int grid[N][N];
    for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        grid[k][j] =  sk->grid[k][j] ;
    pthread_mutex_unlock(&lock);
        valid[num] = 0;
        int n = sqrt(size);
        int startRow = row - row % n, startCol = col - col % n ;  
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i + startRow][j + startCol] == num){
                pthread_exit(NULL);
                }
        
      


        for (int x = 0; x < size; x++)
        if (grid[row][x] == num)
            pthread_exit(NULL);



        
        for (int x = 0; x < size; x++)
        if (grid[x][col] == num)
            pthread_exit(NULL);
            
        valid[num]= 1; 
        
}
*/


int isValid(int grid[N][N], int row,int col, int num,int size)
{
    for (int x = 0; x <= size-1; x++)
        if (grid[row][x] == num)
            return 0;
 
   
    for (int x = 0; x <= size-1; x++)
        if (grid[x][col] == num)
            return 0;
    int s = sqrt(size);
   
    int startRow = row - row %s ,
                 startCol = col - col % s ; 
   
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            if (grid[i + startRow][j +
                          startCol] == num)
                return 0;
 
    return 1;
}


void *solvei(void* val)
{   
    mystruct *sx= (mystruct*) val;
    int row = sx->row; 
    int col = sx->col; 
    int size = sx->size;
    int num = sx->num;
    int final = sx->final; 
    int runner = sx->runner; 
    int grid[N][N];
    for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        grid[k][j] =  sx->grid[k][j] ;


    table:
    
     if(check(grid,size) == 0)
        {   for(int i = 0 ; i < size ; i++)
            for(int j = 0 ; j < size ; j++)
            grida[i][j] = grid[i][j]; 
            //print_grid(size,grid);
             //printf("\n");
            //printf(".........................completed\n");
            flag = 1;
            pthread_exit(NULL);

        }

    if(row >= size)
        {//printf(".......................completed\n");
        flag = 1;
        }

    if (col >= size)
        {
         row++;
         col = 0;
        // printf("%d%d Row Incimented\n",row,col);
        }
     

     if(grid[row][col] != 0){
        col = col+1;
        //printf("%d%d Occupied Col Updated\n" ,row,col); 
        goto table;
    }
   
        


    
    
    if(flag == 0 && grid[row][col] == 0 && row < size && col < size )
    {

    //printf("Row %d Col %d\n", row,col);
         //print_grid(size,grid);
    //printf("\n");

    
    mystruct s[N]; 
    pthread_t pid[N] ={0};
   
    


    
    int e = 0;
    /*pthread_attr_t a ;
    pthread_attr_setstacksize(&a, 67626);
    pthread_attr_init(&a);*/
/*
   mystruct data2 ;   
   data2.row = row; 
   data2.col = col; 
   data2.size = size;
   data2.num = num ;
   data2.grid;
   for( int k = 0 ; k < size; k++)
   for(int j = 0 ; j < size; j++)
    data2.grid[k][j] = grid[k][j] ;
    pthread_t threads[N] = {0};
   
*/
                                             


for(int k = 1 ; k <= size; k++){
/*
    valid[k] = 0 ; 
    pthread_create(&threads[k], NULL, isValide, &data2);
    int y = valid[k] ;
*/
    int y = isValid(grid,  row, col,  k, size) ;
    if(y == 1)
      {  
             
        s[e].row = row; 
        s[e].col = col+1; 
        s[e].size = size;
        s[e].num = num ;
        s[e].final = 1;
        s[e].grid;
        s[e].runner = runner ;
         for( int k = 0 ; k < size; k++)
        for(int j = 0 ; j < size; j++)
        s[e].grid[k][j] =  grid[k][j] ;

        s[e].grid[row][col] = k;
         //printf("Row %d Col %d\n ", row,col);
         //printf("%d e value \n",e);
        //print_grid(size,s[e].grid);
        pthread_create(&pid[e],NULL,solvei,(void*)&s[e]);
         e++; 
        
    }  
    
    }
    for(int i = 0 ; i < e ; i++)
    pthread_join(pid[i],NULL);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

  int grid[36][36], size, i, j;
	
	if (argc != 3) {
		printf("Usage: ./sudoku.out grid_size inputfile");
		exit(-1);
	}
	
	size = atoi(argv[1]);
 
    

	read_grid_from_file(size, argv[2], grid);
	 	/* Do your thing here */
    //print_grid(size,grid);
         
    pthread_t tid = 1;
    mystruct ss;
    ss.row = 0; 
    ss.col = 0; 
    ss.size = size;
    ss.num = 1;
    ss.grid;
    ss.final = 0; 
    ss.runner = 0 ;
    for( int k = 0 ; k < size; k++)
    for(int j = 0 ; j < size; j++)
        ss.grid[k][j] =  grid[k][j] ;

    
	//clock_t t;
    //t = clock();
  
    pthread_create(&tid, NULL,solvei, &ss) ; 
    pthread_join(tid,NULL);
    

    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC;
	//printf("fun() took %f seconds to execute \n", time_taken);
    if(flag ==1){
    print_grid(size,grida);}
    if(flag == 0)
    printf("No solution");	

return 0 ; 
}   
