#include <iostream>
#include<iterator>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include"time.h"


using namespace std;

int main(/*int argc, char *argv[]*/)
{
//Part a
/****get the size of the transformation matrix****/
    int n;
    cout<< "Size of the matrix(numbers of points on the plot): ";
    cin >> n ;



/****start counting time****/
        clock_t start , finish ;
        start = clock () ;

/*************matrix generator**********/
    double *row;
    row = new double[n*n];
    for (int i=0;i<n*n;i++){
        if (i%(n+1)==0)
            row[i]=2;
        else if(i%(n+1)==1){
            row[i]=-1;
        }
        else if(i%(n+1)==n){
            row[i]=-1;
        }
        else
            row[i]=0;
        //cout<<row[i]<<endl;
    }


/**************Getting test values**********/
    double sp,h;
    sp=0;
    h=1.0/n;


    double *ival;
    ival = new double[n];
    ival[0]=sp;
    for (int i=1;i<n;i++){
        ival[i]=ival[i-1]+h;
        //cout<<ival[i]<<endl;
    }

/****************function to get fx****************/
    double x,*fx;
    double *actu;
    actu = new double[n];
    fx = new double[n];
    cout<<endl;
    cout<<"autu: ";
    for (int i=0;i<n;i++){
        x=ival[i];
        fx[i]=100*exp(-10*x)*h*h;
        actu[i]=1-(1-exp(-10))*x-exp(-10*x);

        //cout<<actu[i]<<", ";
    }


    //cout<<endl;

/***********Gaussian elimination Forward substitution********/
    double *row_front,*row2_front;
    double *row_back;
    double *row2;
    row2=new double[n*n];
    row_front = row;
    row_back = row+n*n;
    row2_front = row2;
    copy(row_front, row_back,row2_front);
    //copy(row2_front, row2_back, ostream_iterator<double>(cout, "\n"));


    for (int j=1;j<n;j++){
        for (int i=0;i<n;i++){
            if(i==j){
                row2[j*n+i]-=(row2[(j-1)*n+i]*(row2[(j-1)*n+i]))/(row2[(j-1)*n+(i-1)]);
                //cout<<fx[j]<<"-";
                fx[j]-=(-fx[j-1])/(row2[(j-1)*n+(i-1)]);
                //fx[j]=round(fx[j]);
                //cout<<fx[j-1]<<"/"<<row2[(j-1)*n+(i-1)]<<"="<<fx[j]<<endl;
            }
            else if(i==j-1)
                row2[j*n+i]=0;
            else
                continue;
        }
    }

/************get v(backward substitution)***********/
    double *v;
    v=new double[n];
    cout<<endl;
    v[n-1]=fx[n-1]/row2[n*n-1];
    //cout<<"v[n-1]:"<<v[n-1]<<endl;
    for (int i=n-2;i>=0;i--){
        v[i]=(fx[i]+v[i+1])/row2[i*n+i];
    }
    cout<<endl;
    //end of algorithm
    finish = clock () ;
    printf("It took %f seconds to do Gaussian elimination\n",
             ((double) (finish - start)) / CLOCKS_PER_SEC );

//    cout<<"v: ";
//    for(int i=0;i<n;i++)
//        cout<<i<<": "<<v[i]<<endl;
//    cout<<endl;
//    cout<<endl;



    delete [] row2_front;
    //delete [] row2;
    delete [] row;
    delete [] ival;
    delete [] fx;
    //delete [] row_front;
    //delete [] row_back;

/*******Part B********/
    cout<<"Part B"<<endl;
/****get the size of the transformation matrix****/
    n=0;
    cout<< "Size of the matrix(numbers of points on the plot): ";
    cin >> n ;



/****start counting time****/

    start = clock () ;



/**************Getting test values**********/
    double spb,hb;
    spb=0;
    hb=1.0/n;

    double *val;
    val = new double[n];
    val[0]=spb;
    for (int i=1;i<n;i++){
        val[i]=val[i-1]+hb;
        //cout<<val[i]<<endl;
    }



/*************matrix generator**********/
    double *row4;
    row4 = new double[n*n];
    for (int i=0;i<n*n;i++){
        if (i%(n+1)==0)
            row4[i]=2;
        else if(i%(n+1)==1){
            row4[i]=-1;
        }
        else if(i%(n+1)==n){
            row4[i]=-1;
        }
        else
            row4[i]=0;
        //cout<<row4[i];

    }


/****************get function to be integrated****************/
    double *bx;
    bx = new double[n];
    cout<<endl;
    //cout<<"bx: ";
//    x=0;a
    cout<<n<<endl;
    for (int i=0;i<n;i++){
        x=val[i];
        bx[i]=100*exp(-10*x)*hb*hb;
        cout<<i<<":"<<bx[i]<<", "<<endl;
    }

    //cout<<endl;






/***************************/

    double *row4_front,*row3_front;
    double *row4_back;

    double *row3;
    row3=new double[n*n];
    row4_front = row4;
    row4_back = row4+n*n;
    row3_front = row3;
    copy(row4_front, row4_back,row3_front);




/****************LU decomposition**********/


    double *L,*U;
    L = new double[n*n];
    U = new double[n*n];

    U[0]=row3[0];
    for (int j=0;j<n;j++){
        for (int i=0;i<n;i++){
            if(i==j){
                L[j*n+i]=1;
            }
            if(i==0){
                L[j*n]=row3[j*n]/U[0]*1.0;
            }
            if(j==0){
                U[i]=row3[i];
            }
            if(j>i)
                U[j*n+i]=0;
            if(i>j)
                L[j*n+i]=0;
        }
    }
    for (int j=1;j<n;j++){
        for (int i=1;i<n;i++){
            if(i>=j){
                for (int k=0;k<j;k++){
                    U[j*n+i]=row3[j*n+i]-L[j*n+k]*U[k*n+i];
                }
            }
            if(i<j){
                for (int k=0;k<i;k++){
                    if(U[(j-1)*n+i]==0)
                        U[(j-1)*n+i]=0.00000000000000001;
                    L[j*n+i]=1.0/U[(j-1)*n+i]*(row3[j*n+i]-L[j*n+k]*U[k*n+i]);
                }
            }
        }
    }

    /*cout<<"L: "<<endl;
    for(int i=0;i<n*n;i++){
        //cout<<L[i]<<", ";
        //if ((i+1)%(n)==0)
            //cout<<endl;
    }*/
    //cout<<"U:"<<endl;
    for(int i=0;i<n*n;i++){
        if (U[i]==0.00000000000000001)
            U[i]=0;
        //cout<<U[i]<<", ";
        //if ((i+1)%(n)==0)
            //cout<<endl;
    }

    double *Y,*X;
    Y = new double[n];
    X = new double[n];
    Y[0]=bx[0]/L[0];
    //cout<<"Y[0]:"<<Y[0]<<endl;
    for (int i=1;i<=n-1;i++){
        Y[i]=(bx[i]-L[i*n+i-1]*Y[i-1])/L[i*n+i];
    }
    X[n-1]=Y[n-1]/U[n*n-1];
    //cout<<"Y[n-1]:"<<Y[n-1]<<endl;
    for (int i=n-2;i>=0;i--){
        X[i]=(Y[i]-U[i*n+i+1]*X[i+1])/U[i*n+i];
    }
    //cout<<endl;
    for (int i=0;i<n;i++)
    //cout<<i<<": "<<X[i]<<endl;
    finish = clock () ;
    printf("It took %f seconds to do LU decomposition\n",
             ((double) (finish - start)) / CLOCKS_PER_SEC );





/**********************Part c**********/
    cout<<endl<<endl<<"Part C"<<endl;

    double *er;
    er = new double [n];
    for (int i=0;i<n;i++){
        er[i]=log10(abs((v[i]-actu[i])/actu[i]));
        cout<<i<<"(log): "<<er[i]<<" fx(actual value): "<<actu[i]<<endl;//actu is a dynamic meory storing the value calculated by 1-(1-exp(-10))*x-exp(-10*x)

    }


/**************write out values****/
    ofstream myfile;
    myfile.open ("LUdecmp.txt");
    for (int i=1;i<n-1;i++){
        myfile << "x: " <<setprecision(4)<< val[i]<<"   Actual: "<<setprecision(7)<<actu[i]<<"  Calculated(LU): "<<(X[i])
                  << "    Calculated(Gaussian): " << v[i]
                  << "    log:"<< er[i] <<"\n";
    }
    myfile.close();



/*******delete memeory********/
/*
    cout<<"transformed matrix:"<<endl;
    for (int i=0;i<n*n;i++){
        cout<<row2[i]<<" ";
        if ((i+1)%(n)==0)
            cout<<endl;
    }
    cout<<endl;
*/


    /*
    cout<<"l: ";
    for (int i=0;i<n;i++)
        cout<<fx[i]<<", ";
    */


    delete [] v;

    delete [] bx;
    delete [] val;
    delete [] row4;
//    delete [] row4_front;
//    delete [] row4_back;
    delete [] row3;
//    delete [] row3_front;
//    //delete [] vv;
    delete [] L;
    delete [] U;
    delete [] Y;
    delete [] X;

    delete [] actu;
    delete [] er;
    cout <<  endl;


    return 0;
}

