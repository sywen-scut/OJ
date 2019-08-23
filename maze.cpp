#include <iostream>
#include <queue>
using namespace std;
struct Location{
    int i;
    int j;
    int distance;
    Location(int i, int j, int d){
        this->i = i;
        this->j = j;
        this->distance = d;
    }
};
int goStep(int n, char**a, queue<Location>* queue);
int main(){
    queue<Location> stepQueue;
    int n;
    cin>>n;
    char** a = new char *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new char[n];
    }
    
    int s_i = 0, s_j = 0;
    for(int i = 0; i<n; i++){
        string str;
        cin>>str;
        for(int j = 0; j<n; j++){
            a[i][j] = str[j];
            //find the start location
            if(a[i][j] == 'S'){
                Location l(i,j,0);
                stepQueue.push(l);
            }
        }
    }
    int result = goStep(n, a, &stepQueue);
    cout<<result<<endl;
 
    return 0;
}
int goStep(int n, char**a, queue<Location>* queue){
    if(queue->empty())
        return -1;
    Location first = queue->front();
    int cur_i = first.i;
    int cur_j = first.j;
    a[cur_i][cur_j] == '#';
    queue->pop();
    for(int p = cur_i-1; p <= cur_i+1; p++){
        for(int q = cur_j-1; q <= cur_j +1; q++){
            if(p>=0 && p< n && q>=0 && q <n){
                if((p==cur_i-1 && q== cur_j)||(p==cur_i+1 && q== cur_j)
                ||(p==cur_i && q== cur_j-1)||(p==cur_i && q== cur_j+1)){
                    if(a[p][q]=='.'){
                        queue->push(Location(p, q, first.distance+1));
                        a[p][q] = '#';
                    }
                    if(a[p][q]=='E'){
                        return first.distance+1;
                    }
                }
            }
        }
    }
    /* 迭代 */
    return goStep(n,a,queue);
}
