#include<bits/stdc++.h>

using namespace std;

#define V 9 //Khởi tạo V = 9(Số nút của đồ thị)

int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for(int v=0; v<V; v++){
        if(sptSet[v] == false && dist[v] <= min){//Điều kiện là điểm đấy chưa được xét và khoảng cách đến điểm ấy < khoảng cách đến các điểm khác
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[]){
    cout << "VT  Khoang cach " << endl;
    for (int i = 0; i < V; i++) 
        cout << i << setw(5) << dist[i] << endl;
}
void Dijsktra_Algorithm(int graph[V][V], int s){
    int dist[V]; //Mảng lưu trữ khoảng cách ngắn nhất từ 0 đến các nút còn lại

    bool sptSet[V];//Mảng lưu trữ các nút đã đi qua

    for(int i=0; i<V; i++){
        dist[i] = INT_MAX;//Khởi tạo khoảng cách từ 0 đến các nút
        sptSet[i] = false;//Đánh dấu những nút chưa được xét
    }

    dist[s] = 0; // Khởi tạo khoảnh cách từ 0 đến chính nó
    for (int count = 0; count < V; count++)//duyệt đồ thị từ 0 -> 8
    {
        int u = minDistance(dist, sptSet); // tìm ra vị trí mà có khoảng cách ngắn nhất từ 0

        sptSet[u] = true; //Đánh dấu lại điểm vừa được xét

        for(int v=0; v<V; v++){
            //Kiểm tra điều kiện nút kế tiếp phải chưa được xét
            //Có đường đi từ u -> v
            if(sptSet[v] == false && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v]; 
            }
        }
    }
    printSolution(dist);
}
int main(){
    //Khởi tạo mảng 2 chiều 9x9 để lưu trữ đồ thị
    //Giá trị 0 thể hiện cho không có đường đi giữa 2 điểm trong đồ thị
    int graph[V][V] = { { 0,  4,  0,  0,  0,  0,  0,  8,  0 }, //0
                        { 4,  0,  8,  0,  0,  0,  0,  11, 0 }, //1
                        { 0,  8,  0,  7,  0,  4,  0,  0,  2 }, //2
                        { 0,  0,  7,  0,  9,  14, 0,  0,  0 }, //3
                        { 0,  0,  0,  9,  0,  10, 0,  0,  0 }, //4
                        { 0,  0,  4,  14, 10, 0,  2,  0,  0 }, //5
                        { 0,  0,  0,  0,  0,  2,  0,  1,  6 }, //6
                        { 8,  11, 0,  0,  0,  0,  1,  0,  7 }, //7
                        { 0,  0,  2,  0,  0,  0,  6,  7,  0 }};//8

                        //0   1   2   3   4   5   6   7   8
    Dijsktra_Algorithm(graph, 0);
}