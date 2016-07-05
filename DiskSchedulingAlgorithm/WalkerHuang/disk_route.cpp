#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

#define TIME_JUMP_TRACK  400
#define TIME_JUMP_SECTOR 1
#define TIME_READ_DATA   10
#define MAX_SECTORS      360

class DiskRoute {
    public:
        bool readData(char* filename);
        long long calculate_without_return();
        long long calculate_with_return();

    private:
        int time_of_path(int i, int j);
        long long imin(int num, int cur);

    private:
        vector<pair<int, int> > data; 
        vector<vector<long long> > graph; //only for second answer
        vector<bool> done; 
};


bool DiskRoute::readData(char* filename)  {
    if(filename == NULL) {
        cout << "invalidate filename" << endl;
        return false;
    }

    ifstream infile(filename);
    int N;
    infile >> N;

    data.clear();
    data.resize(N+1);
    data[0] = pair<int,int>(0,0);
    for(int i = 1; i <= N; i++) {
        int track;
        int sector;
        infile >> track >> sector;
        data[i] = pair<int, int>(track, sector);
    }
    return true;
}

int DiskRoute::time_of_path(int i, int j) {
    pair<int, int> x = data[i];
    pair<int, int> y = data[j];

    int track_offset = (x.first > y.first) ? (x.first - y.first) : (y.first - x.first);
    int sector_offset = (x.second > y.second) ? (x.second - y.second) : (y.second - x.second);
    sector_offset = (sector_offset < MAX_SECTORS/2) ? sector_offset : (MAX_SECTORS - sector_offset);

    return (track_offset * TIME_JUMP_TRACK + sector_offset * TIME_JUMP_SECTOR);
}

long long DiskRoute::calculate_without_return() {
    long long sum_time(0);
    pair<int, int> previous(0, 0);

    for (int i = 1; i < data.size(); i++) {
        sum_time += time_of_path(i-1, i) + TIME_READ_DATA;
    }
    return sum_time;
}

long long DiskRoute::imin(int num, int cur) {
    int count = graph.size();
    if(num == 1)
        return graph[cur][0];
    long long mincost = LLONG_MAX;
    for(int i = 0; i < count; i++) {
        if(!done[i] && i!=0) {
            if(mincost <= graph[cur][i] + graph[i][0]) {
                continue;
            }

            done[i] = 1;

            int value = graph[cur][i] + imin(num-1, i);

            if(mincost > value) {
                mincost = value;
            }
            done[i] = 0;
        }
    }
    return mincost;
}


long long DiskRoute::calculate_with_return() {
    int count = data.size();
    graph.resize(count);
    done.resize(count);
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(i != j) {
                graph[i].push_back(time_of_path(i, j));
            } else{
                graph[i].push_back(0);
            }
        }
    }
    return imin(count, 0) + (count - 1) * 10;
}

int main(int argc, char** argv) {
    if(argv == NULL) {
        cout << "invalidate input!!" << endl;
        return 1;
    }
    DiskRoute dr;
    if(!dr.readData(argv[1]))
        return 1;

    long long time1 = dr.calculate_without_return();
    long long time2 = dr.calculate_with_return();;

    cout << time1 << endl << time2 << endl;

    return 0;
}

