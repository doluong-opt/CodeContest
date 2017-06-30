#include <stdio.h>
#include <stdlib.h>
#include <fft.h>
#include <math.h>
#include <ctime>


double * multiply(double * x, int n , double * y , int m , double * z);
double * zNorm(double * x, int n, double * y);


//Global data structures

struct match
{

int i; //start of the subsequence for this match
int length; //Length
double corr; //Correlation of this match
int j; // position of the query that matched

}typedef Match;

int pairComparator(const void * x, const void * y)
{
	
		Match * X = (Match *)x;
		Match * Y = (Match *)y;
		return (int )((Y->corr-X->corr)*10000);
	
};

class heap
{
private:
	Match * heapArray;
	int maxSize;
public:
	int currentSize;
	heap(int maxHeapSize)
	{
		maxSize = maxHeapSize;
		currentSize = 0;
		heapArray = new Match[maxSize];
	}
	bool IsEmpty()
	{ return currentSize == 0; }
	bool Insert(Match value)
	{
		if (currentSize == maxSize)
			return false;
		
		heapArray[currentSize] = value;
		CascadeUp(currentSize++);
		return true;
	}
	void CascadeUp(int index)
	{
		int parent = (index - 1) / 2;
		Match bottom = heapArray[index];
		while (index > 0 && heapArray[parent].corr > bottom.corr)
		{
			heapArray[index] = heapArray[parent];
			index = parent;
			parent = (parent - 1) / 2;
		}
		heapArray[index] = bottom;
	}
	Match Remove() // Remove maximum value Pair
	{
		Match root = heapArray[0];
		heapArray[0] = heapArray[--currentSize];
		CascadeDown(0);
		return root;
	}
	void CascadeDown(int index)
	{
		int largerChild;
		Match top = heapArray[index];
		while (index < currentSize / 2)
		{
			int leftChild = 2 * index + 1;
			int rightChild = leftChild + 1;
			if (rightChild < currentSize && heapArray[leftChild].corr > heapArray[rightChild].corr)
				largerChild = rightChild;
			else
				largerChild = leftChild;
			if (top.corr <= heapArray[largerChild].corr)
				break;
			heapArray[index] = heapArray[largerChild];
			index = largerChild;
		}
		heapArray[index] = top;
	}
	bool HeapIncreaseDecreaseKey(int index, Match newValue)
	{
		if (index < 0 || index >= currentSize)
			return false;
		Match oldValue = heapArray[index];//The top-most element of the tree is don't care.
		heapArray[index] = newValue;
		if (oldValue.corr > newValue.corr)
			CascadeUp(index);
		else
			CascadeDown(index);
		return true;
	}
	void convertToSorted()
	{
		qsort(heapArray, currentSize, sizeof(Match), pairComparator);
	}
	Match last()
	{
		return heapArray[currentSize - 1];
	}
	Match first()
	{
		for (int i = 0; i < currentSize; i++)
			if (heapArray[i].corr != 0)
				return heapArray[i];
		return heapArray[0];
	}

	Match topK()
	{
		return heapArray[1];
		for (int i = 0; i < currentSize; i++)
			if (heapArray[i].corr != 0)
				return heapArray[i];
		return heapArray[0];
	}
	Match valueAt(int i)
	{
		return heapArray[i];
	}
	bool Append(Match value)
	{
		if (currentSize == maxSize)
			return false;
		
		heapArray[currentSize++] = value;
		return true;
	}
	
	
	void DisplayHeap()
	{
		//printf("\n");
		//printf("Elements of the Heap Array are : \n");
		for (int m = 0; m < currentSize; m++)
			if (heapArray[m].corr != 0.0)
				printf( "%d %d %lf %d\n" , heapArray[m].i, heapArray[m].length, heapArray[m].corr, heapArray[m].j );
			else
				printf("-- ");
		printf("\n");
	/*	int emptyLeaf = 32;
		int itemsPerRow = 1;
		int column = 0;
		int j = 0;
		char separator[] = "---------------------------";
		printf("%s%s\n",separator,separator);
		while (currentSize > 0)
		{
			if (column == 0)
				for (int k = 0; k < emptyLeaf; k++)
					printf(" ");
			printf("%lf",heapArray[j].corr);
			
			if (++j == currentSize)
				break;
			if (++column == itemsPerRow)
			{
				emptyLeaf /= 2;
				itemsPerRow *= 2;
				column = 0;
				printf("\n");
			}
			else
				for (int k = 0; k < emptyLeaf * 2 - 2; k++)
					printf(" ");
		}
		printf("\n%s%s",separator,separator);*/
	}
} typedef Heap;

Heap Jocor(double *x, double * y, int n, int m, int minLength,int topk,int s,int mcomp);
Heap JocorBF(double *x, double * y, int n, int m, int minLength,int topk,int s,int mcomp);
Heap JocorLA(double *x, double * y, int n, int m, int minLength,int topk,int s, int mcomp);


double * computeMax(double * y, int n, int minLength)
{
	double * maX = (double *)malloc(sizeof(double)*n);
	double * x = (double *)malloc(sizeof(double)*(n+1));
	double * x2 = (double *)malloc(sizeof(double)*(n+1));

	x[0] = 0; x2[0] = 0;

	for(int i = 1 ; i <= n ; i++ )
	{
		x[i] = y[i-1] + x[i - 1];
        x2[i] = y[i-1] * y[i-1] + x2[i - 1];
		maX[i-1] = 0;
    }

	

	for (long i = 1; i < n-minLength ; i++)
    {
            long mLoc = -1;
            long mnLoc = -1;
            double runMax = 0;
            double runMin = 999999999999999.099;


            for (long j = minLength; i+j < n; j++)
            {

                double sumY = x[i + j - 1] - x[i - 1];
                double meanY = sumY / j;
                double sumY2 = x2[i + j - 1] - x2[i - 1];
                double sigmaY = sqrt((sumY2 / j) - (meanY * meanY));




                if (j == minLength)
                {
                    runMax = 0;
                    runMin = 999999999999999.099;
                    for (long k = 1; k <= minLength; k++)
                    {
                        double X = (y[i + k - 1] - meanY) / sigmaY;
                        if (X > runMax)
                        {
                            runMax = X;
                            mLoc = i + k - 1;
                        }
                        if (X < runMin)
                        {
                            runMin = X;
                            mnLoc = i + k - 1;
                        }



                    }

                }
                else
                {
                    runMax = (y[mLoc] - meanY) / sigmaY;
                    runMin = (y[mnLoc] - meanY) / sigmaY;
                    double Y = (y[i + j - 1] - meanY) / sigmaY;
                    if (runMax < Y)
                    {
                        runMax = Y;
                        mLoc = i + j - 1;
                    }
                    if (runMin > Y)
                    {
                        runMin = Y;
                        mnLoc = i + j - 1;
                    }



                }

                if (runMax > maX[j])
                    maX[j] = runMax;
                //if (-runMax*runMin > maX[j])
                //   maX[j] = -runMax * runMin;
                if (-runMin > maX[j])
                    maX[j] = -runMin;

            }

            // Console.WriteLine(i+ " " + maX[128]);
        }
	free(x); free(x2);
	return maX;
}


double * computeMax(double * y, int n)
{
	double * maX = (double *)malloc(sizeof(double)*n);
	double  maxV = 0;
	for( int i = 0; i < n; i++ )
	{
		if(fabs(y[i]) > maxV )
			maxV = fabs(y[i]);
	}
	for(int i = 0 ; i < n ; i++ )
		maX[i] = maxV;
	return maX;
}



int main(int argc, char* argv[])
{
	//Assume n > m

	int n = atol(argv[3]); 
	int m = atol(argv[4]);
	int minLength = atol(argv[5]);
	int stepSize = atol(argv[6]);
	int algo = atol(argv[7]);
	int maxComp = atol(argv[8]);
	int K = atol(argv[9]);
	//printf("\n%d is algo\n",algo);
	double *x, *y;

	//Allocation
	
	FILE * fp ; errno_t err = fopen_s(&fp,argv[1],"r");
	  if( err )
      printf_s( "The file fscanf.out was not opened\n" );
	FILE * fp1 ; err = fopen_s(&fp1,argv[2],"r");
		   if( err )
      printf_s( "The file fscanf.out was not opened\n");

	x = (double *)malloc(sizeof(double) * n);
	y = (double *)malloc(sizeof(double) * m);

	//Data Input
	for ( int i = 0 ; i < n ; i ++ )
	{
		double d;
		fscanf_s(fp,"%lf",&d);
		x[i] = d;
		if( i < m )
		{
			fscanf_s(fp1,"%lf",&d);
			y[i] = d;
		}
	}

	fclose(fp); fclose(fp1);
    


	if( algo == 0 )
		Jocor(x,y,n,m,minLength,K,stepSize,maxComp);
	else if(algo == 1)
		JocorLA(x,y,n,m,minLength,K,stepSize,maxComp);
	else if( algo == 2 )
		JocorBF(x,y,n,m,minLength,K,stepSize,maxComp);

	free(x); free(y); 

//	system("PAUSE");
}



Heap Jocor(double *x, double * y, int n, int m, int minLength,int topk,int s,int mcomp)
{
	
	Heap H(topk+1);

	long stepStat = 0;
	//Assume n > m
	double **z , *maX , *maY;
	double *cx, *cx2, *cy, *cy2;
	//Allocation

	cx = (double *)malloc(sizeof(double) * (n+1));
	cx2 = (double *)malloc(sizeof(double) * (n+1));
	cy = (double *)malloc(sizeof(double) * (m+1));
	cy2 = (double *)malloc(sizeof(double) * (m+1));


	std::clock_t start = std::clock();

	//Compute MaxV
	x = zNorm(x,n,x);
	y = zNorm(y,m,y);
	double maxV = 0;


	if( mcomp == 0 )
	{
		maX = computeMax(x,n,minLength);
		maY = computeMax(y,m,minLength);
	}
	else if ( mcomp == 1 )
	{
		maX = computeMax(x,n);
		maY = computeMax(y,m);
	}
	else
	{
		 maX = (double *)malloc(sizeof(double)*n);
		 maY = (double *)malloc(sizeof(double)*m);
		for(int i = 0 ; i < n ; i++ )
			maY[i] = maX[i] = mcomp;
		
	}

	//Compute the cumulative sums
	cx[0] = cx2[0] = cy[0] = cy2[0] = 0.0;
	for( int i = 1 ; i <= n; i++ )
	{
		cx[i] = cx[i-1]+x[i-1];
		cx2[i] = cx2[i-1]+x[i-1]*x[i-1];
		if( i < m )
		{
			cy[i] = cy[i-1]+y[i-1];
			cy2[i] = cy2[i-1]+y[i-1]*y[i-1];

		}

	}

	//Compute the multiplication numbers
	z = (double **)malloc(sizeof(double*) * m);
	for(int i = 0; i < m ; i++ )
	{
		z[i] = (double *)malloc(sizeof(double)*2*n);
		z[i] = multiply(x,n,y+i,m-i,z[i]);
	}

		
	double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts : %lf\n",duration);

	//The Search
	double maxC = 0;
	int mi=-1,mj=-1,mlen=0;
	double stepStatAvg = 0;
	double pairCount = 0.0;
	for( int i = 0 ; i < m-minLength ; i=i+1 )
	{
		for( int j = 0 ; j < n-minLength ; j=j+s )
		{
			int maxLen = (m-i<n-j)?(m-i):(n-j);
			int len = minLength;
			int a = 0;
			stepStat = 0;
			while( len < maxLen )
			{

				double sumxy = z[i][m-1-i+j] - z[i+len][m-1-i+j];

				double sumx = cx[j+len]-cx[j];
				double sumx2 = cx2[j+len]-cx2[j];
				double meanx = sumx/len;
				double sigmax = (sumx2/len)-meanx*meanx;
				sigmax = sqrt(sigmax);

			
				double sumy = cy[i+len]-cy[i];
				double sumy2 = cy2[i+len]-cy2[i];
				double meany = sumy/len;
				double sigmay = (sumy2/len)-meany*meany;
				sigmay = sqrt(sigmay);
			
				double c = ( sumxy - len*meanx*meany ) / ( len*sigmax*sigmay );

				if(topk > 1)
				{
					Match M;
					M.i = i;
					M.j = j;
					M.corr = c;
					M.length = len;
				
					if (H.Insert(M) == false)
					{
						H.HeapIncreaseDecreaseKey(0, M);
				
					}
					maxC = H.topK().corr;
				}
				else 
				{
						if( c > maxC )
						{
							mi = i;
							mj = j;
							mlen = len;
							maxC = c;
						} 
				}
				
				double dist = (1-c);
				double bestD = (1-maxC);
				double z = (maX[len]>maY[len])?maX[len]:maY[len];
				double factor = 1.0 / (  (double)(len-1)/len + (double)(len-1)*(z*z)/(len*len)  );
				
				a = floor(log(bestD/dist)/(log(factor)-1.0/(double)len));
			
			
				if ( a < 0 )
					a = 0;

				len = len + a;
				len++;

				if(len < maxLen)
					stepStat += a;
				else
					stepStat += (a - (len-maxLen));
				
			}
			stepStatAvg += (double)stepStat/(maxLen-minLength);
			pairCount++;

		}
	}

	
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts + search : %lf\n",duration);
	
    free(cx); free(cx2); free(cy); free(cy2);
	for(int i = 0; i < m ; i++ )
	{
		free(z[i]);
	}
	free(z);

	if(topk > 1)
		H.DisplayHeap();
	else
		printf_s("%d %d %d %lf %lf\n",mi,mj,mlen,maxC,stepStatAvg/pairCount);

	return H;
}



Heap JocorLA(double *x, double * y, int n, int m, int minLength,int topk,int s,int mcomp)
{
	
	Heap H(topk+1);

	long stepStat = 0;
	double stepStatAvg = 0.0;
	double pairCount = 0.0;
	//Assume n > m
	double **z, *maX , *maY;
	double *cx, *cx2, *cy, *cy2;
	//Allocation

	cx = (double *)malloc(sizeof(double) * (n+1));
	cx2 = (double *)malloc(sizeof(double) * (n+1));
	cy = (double *)malloc(sizeof(double) * (m+1));
	cy2 = (double *)malloc(sizeof(double) * (m+1));


	std::clock_t start = std::clock();

	//Compute MaxV
	x = zNorm(x,n,x);
	y = zNorm(y,m,y);
	double maxV = 0;

	if( mcomp == 0 )
	{
		maX = computeMax(x,n,minLength);
		maY = computeMax(y,m,minLength);
	}
	else if ( mcomp == 1 )
	{
		maX = computeMax(x,n);
		maY = computeMax(y,m);
	}
	else
	{
		 maX = (double *)malloc(sizeof(double)*n);
		 maY = (double *)malloc(sizeof(double)*m);
		for(int i = 0 ; i < n ; i++ )
			maY[i] = maX[i] = mcomp;
	
	}
	

	//Compute the cumulative sums
	cx[0] = cx2[0] = cy[0] = cy2[0] = 0.0;
	for( int i = 1 ; i <= n; i++ )
	{
		cx[i] = cx[i-1]+x[i-1];
		cx2[i] = cx2[i-1]+x[i-1]*x[i-1];
		if( i < m )
		{
			cy[i] = cy[i-1]+y[i-1];
			cy2[i] = cy2[i-1]+y[i-1]*y[i-1];

		}

	}

	//Compute the multiplication numbers
	z = (double **)malloc(sizeof(double*) * m);
	for(int i = 0; i < m ; i++ )
	{
		z[i] = (double *)malloc(sizeof(double)*2*n);
		z[i] = multiply(x,n,y+i,m-i,z[i]);
	}

		
	double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts : %lf\n",duration);

	//The Search
	double maxC;
	double maxD = 99999999999999.99999999999;
	int mi=-1,mj=-1,mlen=0;
	for( int i = 0 ; i < m-minLength ; i=i+1 )
	{
		for( int j = 0 ; j < n-minLength ; j=j+s )
		{
			int maxLen = (m-i<n-j)?(m-i):(n-j);
			int len = minLength;
			stepStat = 0;
			while( len < maxLen )
			{
			
				double sumxy = z[i][m-1-i+j] - z[i+len][m-1-i+j];

				double sumx = cx[j+len]-cx[j];
				double sumx2 = cx2[j+len]-cx2[j];
				double meanx = sumx/len;
				double sigmax = (sumx2/len)-meanx*meanx;
				sigmax = sqrt(sigmax);

			
				double sumy = cy[i+len]-cy[i];
				double sumy2 = cy2[i+len]-cy2[i];
				double meany = sumy/len;
				double sigmay = (sumy2/len)-meany*meany;
				sigmay = sqrt(sigmay);
			
				double c = ( sumxy - len*meanx*meany ) / ( len*sigmax*sigmay );
				double d = (1-c)*2/len;

				if(topk > 1)
				{
					Match M;
					M.i = i;
					M.j = j;
					M.corr = c;
					M.length = len;
				
					if (H.Insert(M) == false)
					{
						H.HeapIncreaseDecreaseKey(0, M);
				
					}
					maxC = H.topK().corr;
				}
				else 
				{
						if( d < maxD )
						{
							mi = i;
							mj = j;
							mlen = len;
							maxC = c;
							maxD = d;
						} 
				}
        


				//double dist = (1-c);
				//double bestD = (1-maxC);
				//double z = maxV;
				//double factor = (double)len/((double)len+1+z*z);
				//double t = len*log(factor)+1;	
				//int a = floor((-t+sqrt(t*t+4*log(bestD/dist)))/2);
				double dist = (1-c);
				double bestD = (1-maxC);
				double z = (maX[len]>maY[len])?maX[len]:maY[len];
				double factor = 1.0 / (  (double)(len-1)/len + (double)(len-1)*(z*z)/(len*len)  );
				
				int a = floor(log(bestD/dist)/(log(factor)+1.0/(double)len));
			
			
			
				if ( a < 0 )
					a = 0;

				len = len + a;
				len++;
				if(len < maxLen)
					stepStat += a;
				else
					stepStat += (a - (len-maxLen));
			}
			stepStatAvg += (double)stepStat/(maxLen-minLength);
			pairCount++;
		}
	}

	
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts + search : %lf\n",duration);
	
    free(cx); free(cx2); free(cy); free(cy2);
	for(int i = 0; i < m ; i++ )
	{
		free(z[i]);
	}
	free(z);

	if(topk > 1)
		H.DisplayHeap();
	else
		printf_s("%d %d %d %lf %lf\n",mi,mj,mlen,maxC,stepStatAvg/pairCount);

	return H;
}
 


Heap JocorBF(double *x, double * y, int n, int m, int minLength,int topk,int s,int mcomp)
{
	
	Heap H(topk+1);

	long stepStat = 0;
	//Assume n > m
	double **z , *maX , *maY;
	double *cx, *cx2, *cy, *cy2;
	//Allocation

	cx = (double *)malloc(sizeof(double) * (n+1));
	cx2 = (double *)malloc(sizeof(double) * (n+1));
	cy = (double *)malloc(sizeof(double) * (m+1));
	cy2 = (double *)malloc(sizeof(double) * (m+1));


	std::clock_t start = std::clock();

	//Compute MaxV
	x = zNorm(x,n,x);
	y = zNorm(y,m,y);
	double maxV = 0;


	if( mcomp == 0 )
	{
		maX = computeMax(x,n,minLength);
		maY = computeMax(y,m,minLength);
	}
	else if ( mcomp == 1 )
	{
		maX = computeMax(x,n);
		maY = computeMax(y,m);
	}
	else
	{
		 maX = (double *)malloc(sizeof(double)*n);
		 maY = (double *)malloc(sizeof(double)*m);
		for(int i = 0 ; i < n ; i++ )
			maY[i] = maX[i] = mcomp;
		
	}

	//Compute the cumulative sums
	cx[0] = cx2[0] = cy[0] = cy2[0] = 0.0;
	for( int i = 1 ; i <= n; i++ )
	{
		cx[i] = cx[i-1]+x[i-1];
		cx2[i] = cx2[i-1]+x[i-1]*x[i-1];
		if( i < m )
		{
			cy[i] = cy[i-1]+y[i-1];
			cy2[i] = cy2[i-1]+y[i-1]*y[i-1];

		}

	}

	//Compute the multiplication numbers
	z = (double **)malloc(sizeof(double*) * m);
	for(int i = 0; i < m ; i++ )
	{
		z[i] = (double *)malloc(sizeof(double)*2*n);
		z[i] = multiply(x,n,y+i,m-i,z[i]);
	}

		
	double duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts : %lf\n",duration);

	//The Search
	double maxC = 0;
	int mi=-1,mj=-1,mlen=0;
	double stepStatAvg = 0;
	double pairCount = 0.0;
	for( int i = 0 ; i < m-minLength ; i=i+1 )
	{
		for( int j = 0 ; j < n-minLength ; j=j+s )
		{
			int maxLen = (m-i<n-j)?(m-i):(n-j);
			int len = minLength;
			int a = 0;
			stepStat = 0;
			while( len < maxLen )
			{

				double sumxy = z[i][m-1-i+j] - z[i+len][m-1-i+j];

				double sumx = cx[j+len]-cx[j];
				double sumx2 = cx2[j+len]-cx2[j];
				double meanx = sumx/len;
				double sigmax = (sumx2/len)-meanx*meanx;
				sigmax = sqrt(sigmax);

			
				double sumy = cy[i+len]-cy[i];
				double sumy2 = cy2[i+len]-cy2[i];
				double meany = sumy/len;
				double sigmay = (sumy2/len)-meany*meany;
				sigmay = sqrt(sigmay);
			
				double c = ( sumxy - len*meanx*meany ) / ( len*sigmax*sigmay );

				if(topk > 1)
				{
					Match M;
					M.i = i;
					M.j = j;
					M.corr = c;
					M.length = len;
				
					if (H.Insert(M) == false)
					{
						H.HeapIncreaseDecreaseKey(0, M);
				
					}
					maxC = H.topK().corr;
				}
				else 
				{
						if( c > maxC )
						{
							mi = i;
							mj = j;
							mlen = len;
							maxC = c;
						} 
				}
				

			
			
				a = 0;

				len = len + a;
				len++;

				if(len < maxLen)
					stepStat += a;
				else
					stepStat += (a - (len-maxLen));
				
			}
			stepStatAvg += (double)stepStat/(maxLen-minLength);
			pairCount++;

		}
	}

	
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	printf("time for ffts + search : %lf\n",duration);
	
    free(cx); free(cx2); free(cy); free(cy2);
	for(int i = 0; i < m ; i++ )
	{
		free(z[i]);
	}
	free(z);

	if(topk > 1)
		H.DisplayHeap();
	else
		printf_s("%d %d %d %lf %lf\n",mi,mj,mlen,maxC,stepStatAvg/pairCount);

	return H;
}


double * zNorm(double * x, int n, double * y)
{
	double ex = 0, ex2 = 0;
	for(int i = 0 ; i < n ; i++ )
	{
		ex += x[i];
		ex2 += x[i]*x[i];
	}
	double	mean = ex/n;
    double std = ex2/n;
    std = sqrt(std-mean*mean);
	for(int i = 0 ; i < n ; i++ )
		y[i] = (x[i]-mean)/std;
	return y;
}

double * multiply(double * x, int n , double * y , int m , double * z)
{
	fftw_complex * X, * Y, * Z , *XX, *YY, *ZZ;
    fftw_plan p;
    
	//assuming n > m
	X = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);
	Y = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);
	XX = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);
	YY = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);
	Z = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);
	ZZ = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * 2 * n);


	for(int i = 0 ; i < 2*n ; i++ )
	{
		X[i][1] = 0; Y[i][1] = 0; //iaginary part is always zero
		if(i < n )
			X[i][0] = x[i];
		else
			X[i][0] = 0;

		if(i < m )
			Y[i][0] = y[m-i-1]; //reversing y
		else
			Y[i][0] = 0;
	}


    p = fftw_plan_dft_1d(2 * n, X, XX, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); 
    
    p = fftw_plan_dft_1d(2 * n, Y, YY, FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p); 

	for(int i = 0 ; i < 2*n; i++)
	{
		ZZ[i][0] = XX[i][0]*YY[i][0] - XX[i][1]*YY[i][1]; 
		ZZ[i][1] = XX[i][1]*YY[i][0] + XX[i][0]*YY[i][1];
	}
	
	p = fftw_plan_dft_1d(2 * n, ZZ , Z , FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(p); 


	for(int i = 0; i < 2*n; i++ )
		z[i] = Z[i][0]/(2*n);
	
	fftw_destroy_plan(p);
    fftw_free(X); fftw_free(Y);
	fftw_free(XX); fftw_free(YY);
	fftw_free(Z); fftw_free(ZZ);
	
	return z;
}
