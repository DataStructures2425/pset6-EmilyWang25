#include "problems.h"
#include<vector>
using namespace std;


int main()
{
    cout<<"find order test:"<<endl;

    int numCourse=4;
    vector<vector<int>> prequesites={{1,0},{2,0},{3,1},{3,2}};

    vector<int> ans = findOrder(numCourse,prequesites);

     if(ans.size()==0){
        cout<<"empty"<<endl;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;

    numCourse = 3;
    vector<vector<int>> prequesites1={{1,0},{0,2},{2,1}};
    ans = findOrder(numCourse,prequesites1);

    if(ans.size()==0){
        cout<<"empty"<<endl;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;

    numCourse = 4;
    vector<vector<int>> prequesites2={{0,3},{0,2},{0,1},{1,2}};
    ans = findOrder(numCourse,prequesites2);

    if(ans.size()==0){
        cout<<"empty"<<endl;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;

    numCourse = 10;
    vector<vector<int>> prequesites3 = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,9}};
    ans = findOrder(numCourse,prequesites3);

    if(ans.size()==0){
        cout<<"empty"<<endl;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    
    numCourse = 9;
    vector<vector<int>> prequesites4 = {{0,6},{1,4},{2,4},{3,2},{4,8},{5,8},{6,7},{7,8},{6,8}};
    ans = findOrder(numCourse,prequesites4);

    if(ans.size()==0){
        cout<<"empty"<<endl;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"unlock room test:"<<endl;
    vector<vector<int>> rooms1 = {{1,3},{3,0,1},{2},{0}};
    if(canVisitAllRooms(rooms1)) cout<<"able to unlock"<<endl;
    else cout<<"unable to unlock"<<endl;


    vector<vector<int>> rooms2 = {{1},{2},{0},{1}};
    if(canVisitAllRooms(rooms2)) cout<<"able to unlock"<<endl;
    else cout<<"unable to unlock"<<endl;

    vector<vector<int>> rooms3 = {{3,2},{2},{1},{0}};
    if(canVisitAllRooms(rooms3)) cout<<"able to unlock"<<endl;
    else cout<<"unable to unlock"<<endl;

    vector<vector<int>> rooms4 = {{1,2,3,4},{},{},{},{}};
    if(canVisitAllRooms(rooms4)) cout<<"able to unlock"<<endl;
    else cout<<"unable to unlock"<<endl;


    vector<vector<int>> rooms5 = {{1},{3},{},{2,4},{}};
    if(canVisitAllRooms(rooms5)) cout<<"able to unlock"<<endl;
    else cout<<"unable to unlock"<<endl;
    /*
        Test your code here! You need at least 5 cases (five different graphs)
        for each solution you implement. Try to make the cases as different
        as you can to ensure maximum coverage. Only one example from the pdf
        handout will count towards your five. 
    */

   cout<<"find cheapest flights"<<endl;
   int n=4;
   vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
   int src = 0;
   int dst = 3;
   int k =1;
   cout<<findCheapestPrice(n,flights,src,dst,k)<<endl;

   n=3;
   vector<vector<int>> flights1 = {{0,1,900},{1,2,600},{0,2,800}};
   src = 0;
   dst = 2;
   k = 1;
   cout<<findCheapestPrice(n,flights1,src,dst,k)<<endl;

   n=4;
   vector<vector<int>> flights2 = {{0,1,900},{1,2,600},{0,3,800},{3,2,600}};
   src = 0;
   dst = 2;
   k = 1;
   cout<<findCheapestPrice(n,flights2,src,dst,k)<<endl;

   n=5;
   vector<vector<int>> flights3 = {{2,4,50},{3,4,20},{0,2,300},{0,3,200},{4,1,20}};
   src = 0;
   dst = 1;
   k = 1;
   cout<<findCheapestPrice(n,flights3,src,dst,k)<<endl;

   n=5;
   vector<vector<int>> flights4 = {{2,4,50},{3,4,20},{0,2,300},{0,3,200},{4,1,20}};
   src = 0;
   dst = 1;
   k = 2;
   cout<<findCheapestPrice(n,flights4,src,dst,k)<<endl;


   cout<<"Minium Cost to Make Path test:"<<endl;

   vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
   cout<<minCost(grid)<<endl;

    vector<vector<int>> grid2 = {{1,2,1},{1,2,1},{1,2,1}};
    cout<<minCost(grid2)<<endl; 

    vector<vector<int>> grid3 = {{1,4,1},{2,3,4},{1,2,3}};
    cout<<minCost(grid3)<<endl; 

    vector<vector<int>> grid4 = {{1,3,1,2},{2,1,4,3},{1,2,3,4},{4,1,1,1}};
    cout<<minCost(grid4)<<endl; 


    vector<vector<int>> grid5 = {{2,1},{4,3}};
    cout<<minCost(grid5)<<endl; 


    cout<<"Shortestpathtest:"<<endl;

    vector<vector<int>> graph1 = {{1,2,3},{0},{0},{0}};
    cout<<shortestPathLength(graph1)<<endl;

    vector<vector<int>> graph2 = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    cout<<shortestPathLength(graph2)<<endl;

    vector<vector<int>> graph3 = {{1,2},{0,2},{0,1}};
    cout<<shortestPathLength(graph3)<<endl;

    vector<vector<int>> graph4 = {{1},{0,2},{1,3},{2}};
    cout<<shortestPathLength(graph4)<<endl;

    vector<vector<int>> graph5 = {{1,2,3,4},{0},{0},{0},{0}};
    cout<<shortestPathLength(graph5)<<endl;

}
